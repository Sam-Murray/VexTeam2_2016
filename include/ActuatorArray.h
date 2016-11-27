#ifndef ACTUATOR_ARRAY_H
#define ACTUATOR_ARRAY_H
#include "Actuator.h"
#include <vector>


class ActuatorArray{
private:
  std::vector<Actuator> array;

public:
ActuatorArray();
ActuatorArray(std::vector<int> pinNumber);
void Update(bool outPressed, bool inPressed);

};
#endif
