#ifndef ROBOT_H
#define ROBOT_H
#include "API.h"
#include "DriveTrain.h"
#include "ActuatorArray.h"

#define X_MOVE 4
#define Y_MOVE 3
#define X_TURN 1
#define Y_TURN 2

class Robot
{
public:
  Robot();
  Robot(int pPin ,int FRpin, int FLpin, int Blpin, int BRpin,std::vector<int> armPins,std::vector<int> hangerPins,int speedC); //constructor for ROBOT
  DriveTrain driveT;//drive train
  Actuator pusher;
  ActuatorArray hanger;
  ActuatorArray arm;


  void Update(int joystickSlot);
  void AutoUpdate(int stage);
};

#endif
