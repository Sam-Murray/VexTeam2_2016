#include"ClawOpenAction.h"
void ClawOpenAction::ExecuteAction(int Param){
  for(int i=0;i<executeTime;i++){
    claw->Update(true,false);
    wait(1);
  }
  claw->Update(false,false);
  return;
}
