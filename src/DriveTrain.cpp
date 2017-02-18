#include "DriveTrain.h"
DriveTrain::DriveTrain():FR(ContinuousMotor(1)), FL(ContinuousMotor(2)), BL(ContinuousMotor(3)), BR(ContinuousMotor(4)){
  speedConvertion=1;
}

DriveTrain::DriveTrain(int FRpin, int FLpin, int BLpin, int BRpin,int speedC):FR(ContinuousMotor(FRpin)), FL(ContinuousMotor(FLpin)), BL(ContinuousMotor(BLpin)), BR(ContinuousMotor(BRpin)){
  speedConvertion=speedC;
}
void DriveTrain::MotorSet(int FRs, int FLs, int BLs, int BRs){
  FR.Update(FRs);
  FL.Update(FLs);
  BL.Update(BLs);
  BR.Update(BRs);
}
void DriveTrain::allMotorSet(int speed){
  // FR.Update(-speed);
  // FL.Update(speed);
  // BL.Update(speed);
  // BR.Update(-speed);
  MotorSet(-speed,speed,speed,-speed);
}
void DriveTrain::backMotorSet(int speed){
  BL.Update(speed);
  BR.Update(speed);
}
void DriveTrain::frontMotorSet(int speed){
  FR.Update(speed);
  FL.Update(speed);
}
void DriveTrain::allMotorSetStrafe(int speed){
  // FR.Update(-speed);
  // FL.Update(-speed);
  // BL.Update(speed);
  // BR.Update(speed);
  MotorSet(-speed,-speed,speed,speed);

}
void DriveTrain::Update(int xMove, int yMove, int xTurn, int yTurn){
  //Working X Y translation
  // if(abs(yMove) >= abs(xMove)){
  //   allMotorSet(yMove/speedConvertion);
  // }
  // if(abs(xMove) >= abs(yMove)){
  //   allMotorSetStrafe(xMove/speedConvertion);
  // }
  //strafe code
  double moveSpeed=sqrt(xMove*xMove  + yMove*yMove)/speedConvertion;
  if(moveSpeed<=10){//prevents annoying miro-inputs
    moveSpeed=0;
  }
  double unroundedAngle = atan2(yMove,xMove);
  int dFR=0;
  int dFL=0;
  int dBL=0;
  int dBR=0;
  if(xMove > 0 && yMove >= 0 ){// 1st quadrant
    dFR=(int)moveSpeed*-1;
    dFL=(int)moveSpeed*cos(2*unroundedAngle)*-1;
    dBL=(int)moveSpeed;
    dBR=(int)moveSpeed*cos(2*unroundedAngle);
  }
  if(xMove >= 0 && yMove < 0 ){//2nd quadrant
    dFR=(int)moveSpeed*cos(2*unroundedAngle)*-1;
    dFL=(int)moveSpeed*-1;
    dBL=(int)moveSpeed*cos(2*unroundedAngle);
    dBR=(int)moveSpeed;
  }
  if(xMove < 0 && yMove <= 0 ){//3rd quadrant
    dFR=(int)moveSpeed;
    dFL=(int)moveSpeed*cos(2*unroundedAngle);
    dBL=(int)moveSpeed*-1;
    dBR=(int)moveSpeed*cos(2*unroundedAngle)*-1;

  }
  if(xMove <= 0 && yMove > 0 ){//4th quadrant
    dFR=(int)moveSpeed*cos(2*unroundedAngle);
    dFL=(int)moveSpeed;
    dBL=(int)moveSpeed*cos(2*unroundedAngle)*-1;
    dBR=(int)moveSpeed*-1;

  }
  dFR += -xTurn/speedConvertion;
  dFL += -xTurn/speedConvertion;
  dBL += -xTurn/speedConvertion;
  dBR += -xTurn/speedConvertion;
  // dFR += -xTurn/4;
  // dFL += -xTurn/4;
  // dBL += -xTurn/4;
  // dBR += -xTurn/4;
  MotorSet(dFR,dFL,dBL,dBR);


}
