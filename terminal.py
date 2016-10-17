import sys
import serial
import serial.tools.list_ports
import select

if len(sys.argv) == 2:
    portname = sys.argv[1]
else:
    ports = [x for x in serial.tools.list_ports.comports() if x.vid is not None and (x.vid in [0x4d8, 0x67b] or 'vex' in x.product.lower())]
    if(len(ports) == 0):
        print("ERROR: could not detect connected Cortex")
    else:
        portname = ports[0].device

port = serial.Serial(portname, baudrate=115200,parity=serial.PARITY_NONE,timeout=5)
port.write(bytes('\r\n\r\n\r\n', 'utf-8'))
while True:
    ready,_,_ = select.select([port, sys.stdin], [], [])
    if port in ready:
        value = port.read(port.in_waiting or 1)
        if value:
            sys.stdout.write(value.decode('utf-8'));
    if sys.stdin in ready:
        value = sys.stdin.read(1)
        if value:
            port.write(bytes(value, 'utf-8'))
