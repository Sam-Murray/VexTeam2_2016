#include "Actuator.h"

Actuator::Actuator():super(10){

}
Actuator::Actuator(int aPin):super(aPin){
}
void Actuator::Update(bool outPressed, bool inPressed){
  int aSpeed=0;
  if(outPressed){
    aSpeed=127;
  }else if(inPressed){
    aSpeed=-127;
  }
  super::setSpeed(aSpeed);
}
void Actuator::Update(bool outPressed, bool inPressed,int speed){
  int aSpeed=0;
  if(outPressed){
    aSpeed=speed;
  }else if(inPressed){
    aSpeed=-speed;
  }
  super::setSpeed(aSpeed);
}
