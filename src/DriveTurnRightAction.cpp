#include"DriveTurnRightAction.h"
void DriveTurnRightAction::ExecuteAction(int Param){
  for(int i=0;i<Param*driveTurnRightConversionFactor;i++){
    drive->Update(0,0,127,0);
    wait(1);
  }
  drive->Update(0,0,0,0);
  return;// Param*driveTurnRightConversionFactor;
}
