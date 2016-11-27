#include "ActuatorArray.h"
ActuatorArray::ActuatorArray(){
  array=std::vector<Actuator>();
}
ActuatorArray::ActuatorArray(std::vector<int> pinNumber){
  array=std::vector<Actuator>(pinNumber.size());
  for(int i=0;i<pinNumber.size();i++){
    array[i]=Actuator(pinNumber[i]);
  }


}
void ActuatorArray::Update(bool outPressed, bool inPressed){
  for(int i=0;i<array.size();i++){
    array[i].Update(outPressed,inPressed);
  }
}
