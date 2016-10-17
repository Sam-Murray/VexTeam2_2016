import serial
import serial.tools.list_ports
import time
import sys
from enum import Enum

file = sys.argv[1]
if len(sys.argv) == 3:
    portname = sys.argv[2]
else:
    ports = [x for x in serial.tools.list_ports.comports() if x.vid is not None and (x.vid in [0x4d8, 0x67b] or 'vex' in x.product.lower())]
    if(len(ports) == 0):
        print("ERROR: could not detect connected Cortex")
    else:
        portname = ports[0].device


print("Connecting to: {}".format(portname))
port = serial.Serial(portname, baudrate=115200,parity=serial.PARITY_EVEN,timeout=5)

class ConnectionType(Enum):
    unknown = -1
    serial_vexnet1 = 0x00
    serial_vexnet1_turbo = 0x01  # no known affecting difference between turbo and non-turbo
    serial_vexnet2 = 0x04
    serial_vexnet2_dl = 0x05
    serial_usb = 0x10
    direct_usb = 0x20

class SystemInfo:
    device = ''
    joystick_firmware = ''
    cortex_firmware = ''
    joystick_battery = 0.0
    cortex_battery = 0.0
    backup_battery = 0.0
    connection_type = ConnectionType.unknown
    previous_polls = 0
    byte_representation = [0x00]

    def __repr__(self):
        if self.connection_type == ConnectionType.serial_vexnet1:
            connection = '  Serial w/ VEXnet 1.0 Keys'
        elif self.connection_type == ConnectionType.serial_vexnet2:
            connection = '  Serial w/ VEXnet 2.0 Keys'
        elif self.connection_type == ConnectionType.serial_vexnet2_dl:
            connection = '  Serial w/ VEXnet 2.0 Keys (download mode)'
        elif self.connection_type == ConnectionType.serial_usb:
            connection = '  Serial w/ a USB cable'
        elif self.connection_type == ConnectionType.direct_usb:
            connection = 'Directly w/ a USB cable'
        else:
            connection = 'Unknown tether connection ({})'.format(self.connection_type)

        return \
            '''Cortex Microcontroller connected on {}
  Tether: {}
Joystick: F/W {} w/ {:1.2f}V
  Cortex: F/W {} w/ {:1.2f}V (Backup: {:1.2f}V)''' \
                .format(self.device,
                        connection,
                        self.joystick_firmware, self.joystick_battery,
                        self.cortex_firmware, self.cortex_battery, self.backup_battery)

def bytes_to_str(arr):
    if isinstance(arr, str):
        arr = bytes(arr)
    if hasattr(arr, '__iter__'):
        return ''.join('{:02X} '.format(x) for x in arr)
    else:  # actually just a single byte
        return '{:02X}'.format(arr)

def expect(port, bytes):
    if not isinstance(bytes, list):
        bytes = [bytes]
    ptr = 0
    start = time.time()
    while(time.time() < start + 5):
        value = port.read()
        if(len(value) > 0 and value[0] == bytes[ptr]):
            ptr += 1
            if(ptr == len(bytes)):
                return True
    return False

def read_vex_packet(port, type=0):
    pattern = [0xaa, 0x55]
    if(type > 0):
        pattern.append(type)
    if expect(port, pattern):
        if len(pattern) == 2:
            got = port.read()
            print("TYPE: {:02X}".format(got[0]))
        length = port.read()
        if(len(length) > 0):
            return port.read(length[0])
    return None

def send_vex_command(port, command, expected=0):
    for _ in range(0,5):
        scrap = port.read(port.in_waiting)
        port.flush()
#        print('COMMAND: {}'.format(bytes_to_str(command)))
        port.write(command)
        port.flush()
        response = read_vex_packet(port, expected)
        if response is not None:
#            print("RESPONSE: {}".format(bytes_to_str(response)))
            return response
    return None

def send_bootloader_command(port, command):
    port.read(port.in_waiting)
    port.write([command, 0xff - command])
    port.flush()

def compute_address_commandable(address):
    address = [(address >> 24) & 0xff, (address >> 16) & 0xff, (address >> 8) & 0xff, address & 0xff]
    checksum = 0x00
    for x in address:
        checksum ^= x
    address.append(checksum)
    return address

MAX_WRITE_SIZE = 0x100
WRITE_SIZE = MAX_WRITE_SIZE
BASE_ADDRESS = 0x08000000

def write_flash(port, address, data):
    data = bytearray(data)
    if len(data) > MAX_WRITE_SIZE:
        error('Tried writing too much data at once! ({} bytes)'.format(len(data)))

    # initiate write
    #print('Writing {} bytes to 0x{:02X}'.format(len(data), address))
    print('.', end="",flush=True)
    port.read(port.in_waiting)
    send_bootloader_command(port, 0x31)
    if not expect(port, 0x79):
        error('failed (write command not accepted)')

    # send address to write to
    address = compute_address_commandable(address)
    port.read(port.in_waiting)
    port.write(address)
    port.flush()
    if not expect(port, 0x79):
        error('failed (address not accepted)')

    checksum = len(data) - 1
    for x in data:
        checksum ^= x
    data.insert(0, len(data) - 1)
    data.append(checksum)
    port.read(port.in_waiting)
    port.write(data)
    port.flush()
    if not expect(port, 0x79):
        error('failed (could not complete upload)')

def error(message):
    print(message)
    sys.exit(1)

sys_info_bits = [0xc9, 0x36, 0xb8, 0x47, 0x21] # expect 0x21
stopbits = [0x0f, 0x0f, 0x21, 0xde, 0x08, 0x00, 0x00, 0x00, 0x08, 0xf1, 0x04]
download_ch_bits = [0xc9, 0x36, 0xb8, 0x47, 0x35]
bootloader_bits = [0xc9, 0x36, 0xb8, 0x47, 0x25]

port.write([0x20])
port.flush()
time.sleep(0.5)
print("Looking for Cortex...", end="",flush=True)
response = send_vex_command(port, sys_info_bits, 0x21)
if response is None:
    error("Couldn't talk to Cortex")
else:
    print("Done.")
    sys_info = SystemInfo()
    sys_info.device = port.name
    sys_info.joystick_firmware = '{}.{}'.format(response[0], response[1])
    sys_info.cortex_firmware = '{}.{}'.format(response[2], response[3])
    if response[4] > 5:  # anything smaller than 5 is probably garbage from ADC
        sys_info.joystick_battery = response[4] * 0.059
    if response[5] > 5:  # anything smaller than 5 is probably garbage from ADC
        sys_info.cortex_battery = response[5] * 0.059
    if response[6] > 5:  # anything smaller than 5 is probably garbage from ADC
        sys_info.backup_battery = response[6] * 0.059
    try:
        sys_info.connection_type = ConnectionType(response[7])
    except ValueError:
        sys_info.connection_type = ConnectionType.unknown
    sys_info.previous_polls = response[9]
    sys_info.byte_representation = response

    print(repr(sys_info))

    if sys_info.connection_type == ConnectionType.serial_vexnet2:
        # send to download channel
        print("Switching to download channel...", end="",flush=True)
        port.read(port.in_waiting)
        port.write(download_ch_bits)
        if expect(port, 0x79):
            print ("Done.")
        else:
            error ("ERROR: No ack to download channel request")

    # switch to bootloader
    print("Switching to bootloader...",end="",flush=True)
    for _ in range(0,5):
        port.read(port.in_waiting)
        port.write(bootloader_bits)
        port.flush()
        time.sleep(0.15)
    time.sleep(0.3)
    print("Done.") #no ack

    # prepare bootloader
    print("Preparing bootloader...",end="",flush=True)
    port.read(port.in_waiting)
    port.write([0x7f])
    if expect(port, 0x79):
        print ("Done.")
    else:
        error ("ERROR: No ack to prepare bootloader.")

    # erase flash
    print("Erasing flash...", end="", flush=True)
    port.read(port.in_waiting)
    send_bootloader_command(port, 0x43)
    if expect(port, 0x79):
        print("Done.")
    else:
        error("ERROR: No ack to erase flash command.")
    send_bootloader_command(port, 0xFF)
    if not expect(port, 0x79):
        error("ERROR:No ack to erase flash value.")

    # load new binary
    print("Writing new code...",end="",flush=True)
    destination = BASE_ADDRESS
    with open(file, "rb") as f:
        while True:
            chunk = f.read(WRITE_SIZE)
            if chunk:
                write_flash(port, destination, chunk)
                destination += WRITE_SIZE
            else:
                break
    print("Done.")

    # run the code
    print('Executing new code...',end="",flush=True)
    send_bootloader_command(port, 0x21)
    if not expect(port, 0x79):
        error('failed (execute command not accepted)')
    port.write(compute_address_commandable(BASE_ADDRESS))
    port.flush()
    if not expect(port, 0x79):
        error('failed (execute address not accepted)')
    port.read(port.in_waiting)
    port.write([0x20])
    port.flush()
    print('Done.')
