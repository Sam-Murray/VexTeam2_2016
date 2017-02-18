#include"DriveRightAction.h"
void DriveRightAction::ExecuteAction(int Param){
  for(int i=0;i<Param*driveRightConversionFactor;i++){
    drive->Update(-127,0,0,0);
    wait(1);
  }
  drive->Update(0,0,0,0);

  return ;//Param*driveRightConversionFactor;
}
