#ifndef ACTUATOR_ARRAY_H
#define ACTUATOR_ARRAY_H
#include "Actuator.h"
#define __FILE_defined
#include <array>


class ActuatorArray{
private:
  std::array<Actuator,4> Array;

public:
ActuatorArray();
ActuatorArray(std::array<int,4> pinNumber);
void Update(bool outPressed, bool inPressed);

};
#endif
