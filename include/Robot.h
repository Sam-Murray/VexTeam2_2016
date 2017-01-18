#ifndef ROBOT_H
#define ROBOT_H
#include "API.h"
#include "DriveTrain.h"
#include "ActuatorArray.h"
#include "Arm.h"

#define X_MOVE 4
#define Y_MOVE 3
#define X_TURN 1
#define Y_TURN 2

class Robot
{
public:
  Robot();
  Robot(int hangerPin ,int FRpin, int FLpin, int Blpin, int BRpin,std::array<int,4> clawPins,std::array<int,4> armPinsLeft,std::array<int,4> armPinsRight,int speedC); //constructor for ROBOT
  DriveTrain driveT;//drive train
  Arm arm;
  ActuatorArray claw;
  void Update(int joystickSlot);
  void AutoUpdate(int stage);
};

#endif
