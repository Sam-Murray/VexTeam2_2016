#ifndef ARM_H
#define ARM_H
#include "ActuatorArray.h"
class Arm{
  private:
    ActuatorArray Motors;
    //Encoder goes here
  public:
    Arm();
    Arm(int p1,int p2,int p3,int p4);
    Arm(std::array<int,4> pins);
    void Update(bool outPressed,bool inPressed);
    //TODO:: implement 3 state functionality

};
#endif
