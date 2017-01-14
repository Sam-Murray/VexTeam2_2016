#include "ActuatorArray.h"
ActuatorArray::ActuatorArray(){
  Array=std::array<Actuator,4>();
}
ActuatorArray::ActuatorArray(std::array<int,4> pinNumber){
  Array=std::array<Actuator,4>();
  for(int i=0;i<pinNumber.size();i++){
    Array[i]=Actuator(pinNumber[i]);
  }


}
void ActuatorArray::Update(bool outPressed, bool inPressed){
  for(int i=0;i<Array.size();i++){
    Array[i].Update(outPressed,inPressed);
  }
}
