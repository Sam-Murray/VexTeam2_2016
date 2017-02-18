#ifndef CLAW_OPEN_ACTION_H
#define CLAW_OPEN_ACTION_H
#include "Action.h"
#include "ActuatorArray.h"
class ClawOpenAction: public Action{
private:
  ActuatorArray* claw;
  const int executeTime=300;
public:
ClawOpenAction(ActuatorArray* claw1)
  {
    claw=claw1;
  };
  void ExecuteAction(int Param);
};
#endif
