#Vex Robotics MSSM Team #2

* Requirements
  * Brew: `/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`
  * arm-none-eabi-gcc - C compiler for ARM cpus
   * `brew tap PX4/homebrew-px4`
   * `brew update`
   * `brew install gcc-arm-none-eabi`
  * python3: `brew install python3`
  * make: `brew install make`
   * NOTE: if you have xcode installed, you make may already be installed
  * git: `brew install git`
   * Optional - needed only if you want to use git to manage your code.
* To install your code, type `make upload` with the vex unit connected by serial cable - or via the cable to the joystick controller
* To connect to the debug terminal, type `make terminal`.  
  * To exit type <control>-c
  * NOTE: The terminal may freeze after a while of inactivity.  exit and restart.


Other notes here...
