#ifndef ROBOT_H
#define ROBOT_H
#include "API.h"
#include "DriveTrain.h"

#define X_MOVE 4
#define Y_MOVE 3
#define X_TURN 1
#define Y_TURN 2

class Robot
{
public:
  Robot();
  Robot(int FRpin, int FLpin, int Blpin, int BRpin,int speedC); //constructor for ROBOT
  DriveTrain DriveT;//drive train
  void Update(int joystickSlot);
};

#endif
