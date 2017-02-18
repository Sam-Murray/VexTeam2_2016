#ifndef MOTOR_UNIT_H
#define MOTOR_UNIT_H
#include "API.h"
//Abstract Class MotorUnit
class MotorUnit
{
public:
  MotorUnit(int p);
  //MotorUnit();
  void setSpeed(int speed);
  virtual void Update(){return;};
private:
  int channel;
  int speed;
};

#endif
