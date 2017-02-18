#ifndef CONTINUOUS_MOTOR_H
#define CONTINUOUS_MOTOR_H
#include "MotorUnit.h"
#include "API.h"
class ContinuousMotor:public MotorUnit
{
public:
  typedef MotorUnit super;
  ContinuousMotor();
  ContinuousMotor(int aPin);
  void Update(int speed);
};

#endif
