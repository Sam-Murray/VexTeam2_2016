#ifndef CLAW_BEGIN_H
#define CLAW_BEGIN_H
#include "Action.h"
#include "ActuatorArray.h"
class ClawBegin: public Action{
private:
  ActuatorArray* claw;
  const int executeTime=20;
public:
ClawBegin(ActuatorArray* claw1)
  {
    claw=claw1;
  };
  void ExecuteAction(int Param);
};
#endif
