#ifndef DRIVE_LEFT_ACTION_H
#define DRIVE_LEFT_ACTION_H
#include "Action.h"
#include "DriveTrain.h"
class DriveLeftAction: public Action{
private:
  DriveTrain* drive;
  int driveLeftConversionFactor=1;
public:
   DriveLeftAction(DriveTrain* drive1)
  {
    drive=drive1;
  };
  void ExecuteAction(int Param);
};
#endif
