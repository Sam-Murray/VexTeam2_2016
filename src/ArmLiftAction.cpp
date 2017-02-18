#include "ArmLiftAction.h"
//assumes Param is 1 or 0 for
void ArmLiftAction::ExecuteAction(int Param){
  for(int i=0;i<executeTime;i++){
    arm->Update(false,true);
    wait(1);
  }
  arm->Update(false,false);
  return;
}
