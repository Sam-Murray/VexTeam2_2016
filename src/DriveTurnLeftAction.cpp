#include"DriveTurnLeftAction.h"
void DriveTurnLeftAction::ExecuteAction(int Param){
  for(int i=0;i<Param*driveTurnLeftConversionFactor;i++){
    drive->Update(0,0,-127,0);
    wait(1);
  }
  drive->Update(0,0,0,0);

  return;// Param*driveTurnLeftConversionFactor;
}
