#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H
#include "MotorUnit.h"
#include "API.h"
#include "math.h"

class DriveTrain
{
private:
  MotorUnit FR; //front right motor
  MotorUnit FL; //front left motor
  MotorUnit BL;//back left motor
  MotorUnit BR;//back right motor
  int speedConvertion;
  void allMotorSet(int speed);
  void allMotorSetStrafe(int speed);
  void frontMotorSet(int speed);
  void backMotorSet(int speed);
  void MotorSet(int FRs, int FLs, int BLs, int BRs);

public:
  DriveTrain();
  DriveTrain(int FRpin, int FLpin, int Blpin, int BRpin,int speedC);
  void Update(int X_MOVE, int Y_MOVE, int X_TURN, int Y_TURN);
};



#endif
