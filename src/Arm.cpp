#include "Arm.h"
Arm::Arm(){
  std::array<int,4> arrayLeft={5,6};
  std::array<int,4> arrayRight={7,8};
  MotorsLeft=ActuatorArray(arrayLeft);
  MotorsRight=ActuatorArray(arrayRight);

}
Arm::Arm(int p1,int p2,int p3,int p4,int p5,int p6){
  std::array<int,4> arrayLeft;
  arrayLeft[0]=p1;
  arrayLeft[1]=p2;
  std::array<int,4> arrayRight;
  arrayRight[0]=p1;
  arrayRight[1]=p2;
  MotorsLeft=ActuatorArray(arrayLeft);
  MotorsRight=ActuatorArray(arrayRight);
}
Arm::Arm(std::array<int,4> pinsLeft,std::array<int,4> pinsRight){
  MotorsLeft=ActuatorArray(pinsLeft);
  MotorsRight=ActuatorArray(pinsRight);
}
void Arm::Update(bool outPressed,bool inPressed){
  MotorsLeft.Update(inPressed,outPressed);
  MotorsRight.Update(outPressed,inPressed);
}
