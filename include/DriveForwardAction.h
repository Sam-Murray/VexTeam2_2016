#ifndef DRIVE_FORWARD_ACTION_H
#define DRIVE_FORWARD_ACTION_H
#include "Action.h"
#include "DriveTrain.h"
class DriveForwardAction: public Action{
private:
  DriveTrain* drive;
  int driveForwardConversionFactor=12;
public:
   DriveForwardAction(DriveTrain* drive1)
  {
    drive=drive1;
  };
  void ExecuteAction(int Param);
};
#endif
