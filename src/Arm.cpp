#include "Arm.h"
Arm::Arm(){
  std::array<int,4> array={5,6,7};
  Motors=ActuatorArray(array);
}
Arm::Arm(int p1,int p2,int p3){
  std::array<int,4> array;
  array[0]=p1;
  array[1]=p2;
  array[2]=p3;
  Motors=ActuatorArray(array);
}
Arm::Arm(std::array<int,4> pins){
  Motors=ActuatorArray(pins);
}
void Arm::Update(bool outPressed,bool inPressed){
  Motors.Update(outPressed,inPressed);
}
