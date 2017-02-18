#ifndef DRIVE_BACKWARDS_ACTION_H
#define DRIVE_BACKWARDS_ACTION_H
#include "Action.h"
#include "DriveTrain.h"
class DriveBackwardsAction: public Action{
private:
  DriveTrain* drive;
  int driveBackwardConversionFactor=12;
public:
  DriveBackwardsAction(DriveTrain* drive1)
  {
    drive=drive1;
  };
  void ExecuteAction(int Param);
};
#endif
