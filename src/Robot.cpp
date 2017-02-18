#include "Robot.h"

Robot::Robot()
{
  driveT=DriveTrain();
  arm=Arm();
  claw=ActuatorArray({9,10},65);

}
Robot::Robot(int hPin,int FRpin, int FLpin, int Blpin, int BRpin, std::array<int,4> clawPin,std::array<int,4> armPinsLeft,std::array<int,4> armPinsRight,int speedC)
{
  driveT=DriveTrain(FRpin, FLpin, Blpin, BRpin, speedC);
  arm=Arm(armPinsLeft,armPinsRight);
  claw=ActuatorArray(clawPin);
}

void Robot::Update(int joystickSlot)
{
    driveT.Update(-joystickGetAnalog(joystickSlot,X_TURN),joystickGetAnalog(joystickSlot,Y_TURN),-joystickGetAnalog(joystickSlot,X_MOVE),joystickGetAnalog(joystickSlot,Y_MOVE));
    arm.Update(joystickGetDigital(joystickSlot,6,JOY_UP),joystickGetDigital(joystickSlot,6,JOY_DOWN));
    claw.Update(joystickGetDigital(joystickSlot,5,JOY_UP),joystickGetDigital(joystickSlot,5,JOY_DOWN));

}
void Robot::AutoUpdate(int stage){
  // if(stage==1){
  //   claw.Update(false,true);
  // }
  // if (stage==2){
  //   arm.Update(true,false);
  // }
  if(stage==1){
    arm.Update(false,true);
  }
  // }
  // if(stage==4){
  //   claw.Update(true,false);
  if(stage==0){
    driveT.Update(0,0,0,0);
    arm.Update(false,false);
    claw.Update(false,false);
  }
  // if(stage==1){
  //   driveT.Update(0,0,-127,0);
  // }
  // if (stage==2){
  //   claw.Update(false,true);
  // }
  // if(stage==3){
  //   driveT.Update(0,127,0,0);
  //
  // }
  // if(stage==4){
  //   claw.Update(true,false);
  // }
  //
  // if(stage==5){
  //
  //   arm.Update(true,false);
  //   claw.Update(true,false);
  //
  //
  // }
  // if(stage==6){
  //
  //   driveT.Update(0,0,127,0);
  //   claw.Update(true,false);
  //
  // }
  // if(stage==7){
  //
  //   driveT.Update(0,127,0,0);
  //   claw.Update(true,false);
  //
  // }
  //
  //
  // if(stage==8){
  //   claw.Update(false,true);
  //
  // }


}
