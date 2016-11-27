#include "Actuator.h"

Actuator::Actuator():actuatorMotor(MotorUnit(10)){
}
Actuator::Actuator(int aPin):actuatorMotor(MotorUnit(aPin)){
}
void Actuator::Update(bool outPressed, bool inPressed){
  int aSpeed=0;
  if(outPressed){
    aSpeed=127;
  }else if(inPressed){
    aSpeed=-127;
  }
  actuatorMotor.setSpeed(aSpeed);
}
