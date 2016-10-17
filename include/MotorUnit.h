#ifndef MOTOR_UNIT_H
#define MOTOR_UNIT_H
#include "API.h"

class MotorUnit
{
public:
  MotorUnit(int p);
  //MotorUnit();
  void setSpeed(int speed);
private:
  int channel;
  int speed;
};

#endif
