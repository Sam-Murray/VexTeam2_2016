#include"DriveLeftAction.h"
void DriveLeftAction::ExecuteAction(int Param){
  for(int i=0;i<Param*driveLeftConversionFactor;i++){
    drive->Update(127,0,0,0);
    wait(1);
  }
  drive->Update(0,0,0,0);
  return;
}
