#ifndef CLAW_CLOSE_ACTION_H
#define CLAW_CLOSE_ACTION_H
#include "Action.h"
#include "ActuatorArray.h"
class ClawCloseAction: public Action{
private:
  ActuatorArray* claw;
  const int executeTime=300;
public:
ClawCloseAction(ActuatorArray* claw1)
  {
    claw=claw1;
  };
  void ExecuteAction(int Param);
};
#endif
