#include "ContinuousMotor.h"
ContinuousMotor::ContinuousMotor():super(1){
}
ContinuousMotor::ContinuousMotor(int aPin):super(aPin){
}
void ContinuousMotor::Update(int speed){
  super::setSpeed(speed);
}
