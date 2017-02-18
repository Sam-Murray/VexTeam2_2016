#include"DriveForwardAction.h"
void DriveForwardAction::ExecuteAction(int Param){
  for(int i=0;i<Param*driveForwardConversionFactor;i++){
    drive->Update(0,127,0,0);
    wait(1);
  }
  drive->Update(0,0,0,0);
  return;
}
