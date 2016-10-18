#ifndef ACTUATOR_H
#define ACTUATOR_H
#include "MotorUnit.h"
#include "API.h"

class Actuator
{
private:
  MotorUnit actuatorMotor;
public:
  Actuator();
  Actuator(int aPin);
  void Update(bool outPressed, bool inPressed);

};

#endif
