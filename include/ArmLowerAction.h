#ifndef ARM_LOWER_ACTION_H
#define ARM_LOWER_ACTION_H
#include "Action.h"
#include "Arm.h"
class ArmLowerAction: public Action{
private:
  Arm* arm;
  //FIND THIS
  const int executeTime=900;
public:
  ArmLowerAction(Arm* arm1)
  {
    arm=arm1;
  };
  void ExecuteAction(int Param);
};
#endif
