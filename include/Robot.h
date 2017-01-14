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
  Robot(int hPin ,int FRpin, int FLpin, int Blpin, int BRpin,int clawPin, std::array<int,4> armPins,int speedC); //constructor for ROBOT
  DriveTrain driveT;//drive train
  Arm arm;
  Actuator hanger;
  Actuator claw;
  void Update(int joystickSlot);
  void AutoUpdate(int stage);
};

#endif
