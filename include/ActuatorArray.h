#ifndef ACTUATOR_ARRAY_H
#define ACTUATOR_ARRAY_H
#include "Actuator.h"
#define __FILE_defined
#include <array>


class ActuatorArray{
private:
  std::array<Actuator,4> Array;
  int speed=127;

public:
ActuatorArray();
ActuatorArray(std::array<int,4> pinNumber);
ActuatorArray(std::array<int,4> pinNumber,int speedi);
virtual void Update(bool outPressed, bool inPressed);

};
#endif
