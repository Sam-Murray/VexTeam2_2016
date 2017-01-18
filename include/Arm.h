#ifndef ARM_H
#define ARM_H
#include "ActuatorArray.h"
class Arm{
  private:
    ActuatorArray MotorsLeft;
    ActuatorArray MotorsRight;
    //Encoder goes here
  public:
    Arm();
    Arm(int p1,int p2,int p3,int p4,int p5,int p6);
    Arm(std::array<int,4> pinsLeft,std::array<int,4> pinsRight);
    void Update(bool outPressed,bool inPressed);
    //TODO:: implement 3 state functionality

};
#endif
