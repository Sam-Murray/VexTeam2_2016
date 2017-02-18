#ifndef ACTUATOR_H
#define ACTUATOR_H
#include "MotorUnit.h"
#include "API.h"

class Actuator:public MotorUnit
{
private:
  typedef MotorUnit super;
public:
  Actuator();
  Actuator(int aPin);
  void Update(bool outPressed, bool inPressed);
  void Update(bool outPressed, bool inPressed,int speed);

};

#endif
