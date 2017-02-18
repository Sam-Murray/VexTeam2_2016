#ifndef DRIVE_RIGHT_ACTION_H
#define DRIVE_RIGHT_ACTION_H
#include "Action.h"
#include "DriveTrain.h"
class DriveRightAction: public Action{
private:
  DriveTrain* drive;
  int driveRightConversionFactor=1;
public:
   DriveRightAction(DriveTrain* drive1)
  {
    drive=drive1;
  };
  void ExecuteAction(int Param);
};
#endif
