#include"ClawBegin.h"
void ClawBegin::ExecuteAction(int Param){
  for(int i=0;i<executeTime;i++){
    claw->Update(false,true);
    wait(1);
  }
  claw->Update(false,false);
  return;
}
