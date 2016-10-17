#include "Robot.h"

Robot::Robot()
{
  DriveT=DriveTrain();
}
Robot::Robot(int FRpin, int FLpin, int Blpin, int BRpin,int speedC)
{
  DriveT=DriveTrain(FRpin, FLpin, Blpin, BRpin, speedC);
}
void Robot::Update(int joystickSlot)
{
    DriveT.Update(-joystickGetAnalog(joystickSlot,X_MOVE),joystickGetAnalog(joystickSlot,Y_MOVE),joystickGetAnalog(joystickSlot,X_TURN),joystickGetAnalog(joystickSlot,Y_TURN));
}
