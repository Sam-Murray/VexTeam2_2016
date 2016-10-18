#include "Robot.h"

Robot::Robot()
{
  driveT=DriveTrain();
  pusher=Actuator();
}
Robot::Robot(int pPin, int FRpin, int FLpin, int Blpin, int BRpin,int speedC)
{
  driveT=DriveTrain(FRpin, FLpin, Blpin, BRpin, speedC);
  pusher=Actuator(pPin);
}
void Robot::Update(int joystickSlot)
{
    driveT.Update(-joystickGetAnalog(joystickSlot,X_MOVE),joystickGetAnalog(joystickSlot,Y_MOVE),joystickGetAnalog(joystickSlot,X_TURN),joystickGetAnalog(joystickSlot,Y_TURN));
    pusher.Update(joystickGetDigital(joystickSlot,6,JOY_UP),joystickGetDigital(joystickSlot,6,JOY_DOWN));
}
