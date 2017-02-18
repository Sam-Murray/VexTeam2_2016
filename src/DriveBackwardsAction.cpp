#include"DriveBackwardsAction.h"
void DriveBackwardsAction::ExecuteAction(int Param){
  for(int i=0;i<Param*driveBackwardConversionFactor;i++){
    drive->Update(0,-127,0,0);
    wait(1);
  }
  drive->Update(0,0,0,0);
  return;
}
