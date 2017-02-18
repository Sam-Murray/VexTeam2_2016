#ifndef DRIVE_TURN_LEFT_ACTION_H
#define DRIVE_TURN_LEFT_ACTION_H
#include "Action.h"
#include "DriveTrain.h"
class DriveTurnLeftAction: public Action{
private:
  DriveTrain* drive;
  int driveTurnLeftConversionFactor=890;
public:
   DriveTurnLeftAction(DriveTrain* drive1)
  {
    drive=drive1;
  };
  void ExecuteAction(int Param);
};
#endif
