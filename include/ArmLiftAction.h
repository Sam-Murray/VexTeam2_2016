#ifndef ARM_LIFT_ACTION_H
#define ARM_LIFT_ACTION_H
#include "Action.h"
#include "Arm.h"
class ArmLiftAction: public Action{
private:
  Arm* arm;
  const int executeTime=1300;
public:
  ArmLiftAction(Arm* arm1)
  {
    arm=arm1;
  };
  void ExecuteAction(int Param);
};
#endif
