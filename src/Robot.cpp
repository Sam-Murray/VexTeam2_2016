#include "Robot.h"

Robot::Robot()
{
  driveT=DriveTrain();
  pusher=Actuator(9);
  hanger=ActuatorArray({5,6});
  arm=ActuatorArray({7,8});


}
Robot::Robot(int pPin, int FRpin, int FLpin, int Blpin, int BRpin,std::vector<int> armPins,std::vector<int> hangerPins,int speedC)
{
  driveT=DriveTrain(FRpin, FLpin, Blpin, BRpin, speedC);
  pusher=Actuator(pPin);
  hanger=ActuatorArray(hangerPins);
  arm=ActuatorArray(armPins);

}

void Robot::Update(int joystickSlot)
{
    driveT.Update(-joystickGetAnalog(joystickSlot,X_TURN),joystickGetAnalog(joystickSlot,Y_TURN),-joystickGetAnalog(joystickSlot,X_MOVE),joystickGetAnalog(joystickSlot,Y_MOVE));
    pusher.Update(joystickGetDigital(joystickSlot,6,JOY_UP),joystickGetDigital(joystickSlot,6,JOY_DOWN));
    hanger.Update(joystickGetDigital(joystickSlot,5,JOY_UP),joystickGetDigital(joystickSlot,5,JOY_DOWN));
    // if(joystickGetDigital(joystickSlot,5,JOY_UP),joystickGetDigital(joystickSlot,7,JOY_UP)){
    //   driveT.Update(-joystickGetAnalog(joystickSlot,X_TURN),joystickGetAnalog(joystickSlot,Y_TURN)+50,-joystickGetAnalog(joystickSlot,X_MOVE),joystickGetAnalog(joystickSlot,Y_MOVE));
    // }
    arm.Update(joystickGetDigital(joystickSlot,7,JOY_UP),joystickGetDigital(joystickSlot,7,JOY_DOWN));


}
void Robot::AutoUpdate(int stage){

}
