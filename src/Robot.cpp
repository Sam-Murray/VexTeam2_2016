#include "Robot.h"

Robot::Robot()
{
  driveT=DriveTrain();
  arm=Arm();
  hanger=Actuator(8);
  claw=ActuatorArray({9,10});

}
Robot::Robot(int hPin,int FRpin, int FLpin, int Blpin, int BRpin, std::array<int,4> clawPin,std::array<int,4> armPins,int speedC)
{
  driveT=DriveTrain(FRpin, FLpin, Blpin, BRpin, speedC);
  arm=Arm(armPins);
  hanger=Actuator(hPin);
  claw=ActuatorArray(clawPin);


}

void Robot::Update(int joystickSlot)
{
    driveT.Update(-joystickGetAnalog(joystickSlot,X_TURN),joystickGetAnalog(joystickSlot,Y_TURN),-joystickGetAnalog(joystickSlot,X_MOVE),joystickGetAnalog(joystickSlot,Y_MOVE));
    arm.Update(joystickGetDigital(joystickSlot,7,JOY_UP),joystickGetDigital(joystickSlot,7,JOY_DOWN));
    claw.Update(joystickGetDigital(joystickSlot,5,JOY_UP),joystickGetDigital(joystickSlot,5,JOY_DOWN));
    hanger.Update(joystickGetDigital(joystickSlot,6,JOY_UP),joystickGetDigital(joystickSlot,6,JOY_DOWN));

}
void Robot::AutoUpdate(int stage){
  if(stage==1){
    driveT.Update(-127,0,0,0);
  }
  if(stage==2){
    driveT.Update(0,127,0,0);
  }
  //pusher.Update(0,1);

}
