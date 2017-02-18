#ifndef DRIVE_TURN_RIGHT_ACTION_H
#define DRIVE_TURN_RIGHT_ACTION_H
#include "Action.h"
#include "DriveTrain.h"
class DriveTurnRightAction: public Action{
private:
  DriveTrain* drive;
  int driveTurnRightConversionFactor=890;
public:
   DriveTurnRightAction(DriveTrain* drive1)
  {
    drive=drive1;
  };
  void ExecuteAction(int Param);
};
#endif
