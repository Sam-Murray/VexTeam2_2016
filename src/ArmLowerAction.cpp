#include "ArmLowerAction.h"
//assumes Param is 1 or 0 for
void ArmLowerAction::ExecuteAction(int Param){
  for(int i=0;i<executeTime;i++){
    arm->Update(true,false);
    wait(1);
  }
  arm->Update(false,false);
  return;
}
