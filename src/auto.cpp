/**
* File for autonomous code.
*
* This file should contain the user autonomous() function and any functions related to it.
*
* Copyright (c) 2011-2014, Purdue University ACM SIG BOTS. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
* Neither the name of Purdue University ACM SIG BOTS nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source code may be obtained from http://sourceforge.net/projects/freertos/files/ or on request.
********************************************************************************/

#include "main.h"
#include "Robot.h"
#include"ArmLiftAction.h"
#include"ArmLowerAction.h"
#include "ClawCloseAction.h"
#include "ClawOpenAction.h"
#include "DriveBackwardsAction.h"
#include "DriveForwardAction.h"
#include "DriveRightAction.h"
#include "DriveLeftAction.h"
#include "DriveTurnLeftAction.h"
#include "DriveTurnRightAction.h"
#include "ClawBegin.h"
/**
* Runs the user autonomous code.
*
* This function will be started in its own task with the default priority and stack size whenever the robot is enabled via the Field Management System or the VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart the task, not re-start it from where it left off.
*
* Code running in the autonomous task cannot access information from the VEX Joystick. However, the autonomous function can be invoked from another task if a VEX Competition Switch is not available, and it can access joystick information if called in this way.
*
* The autonomous task may exit, unlike operatorControl() which should never exit. If it does so, the robot will await a switch to another mode or disable/enable cycle.
*/
//
// // void autoStage(int stage, int duration,Robot robot) {
// //   for(int counter=0;counter < duration; counter++){
// //     robot.AutoUpdate(stage);
// //     wait(1);
// //   }
// }
void autonomous() {
  Robot robot= Robot();
  ClawCloseAction clawClose=ClawCloseAction(&robot.claw);
  ClawOpenAction clawOpen=ClawOpenAction(&robot.claw);
  ArmLiftAction armLift=ArmLiftAction(&robot.arm);
  ArmLowerAction armDownt=ArmLowerAction(&robot.arm);
  DriveBackwardsAction driveBack=DriveBackwardsAction(&robot.driveT);
  DriveForwardAction driveForward=DriveForwardAction(&robot.driveT);
  DriveLeftAction driveLeft=DriveLeftAction(&robot.driveT);
  DriveRightAction driveRight=DriveRightAction(&robot.driveT);
  DriveTurnRightAction turnLeft=DriveTurnRightAction(&robot.driveT);
  DriveTurnLeftAction turnRight=DriveTurnLeftAction(&robot.driveT);
  ClawBegin begin=ClawBegin(&robot.claw);
  //begin.ExecuteAction(1);
   clawOpen.ExecuteAction(1);
  // driveForward.ExecuteAction(100);
   clawClose.ExecuteAction(1);
  // armLift.ExecuteAction(1);
  // turnLeft.ExecuteAction(1);
  // driveForward.ExecuteAction(128);
  // clawOpen.ExecuteAction(1);






  return;
}
// for(int counter=0;counter < 50;){
//   robot.AutoUpdate(1);
//   counter++;
//   wait(1);
// }
// for(int counter=0;counter < 350;){
//   robot.AutoUpdate(2);
//   counter++;
//   wait(1);
// }
// for(int counter=0;counter < 1500;){
//   robot.AutoUpdate(3);
//   counter++;
//   wait(1);
// }
// for(int counter=0;counter < 500;){
//   robot.AutoUpdate(4);
//   counter++;
//   wait(1);
// }

// autoStage(2, 50,robot);//open claw
// autoStage(0,2000,robot);
//
//
// autoStage(3,3000,robot);//drive forward
// autoStage(0,1,robot);
// autoStage(4,500,robot);//close claw
//
// autoStage(0,1,robot);
//
// autoStage(5,1450,robot);//arm lift
// //autoStage(0,1,robot);
//
// autoStage(6,900,robot);//turn
// autoStage(0,1,robot);
// autoStage(7,1700,robot);//drive forward
// autoStage(0,1,robot);
// autoStage(8,50,robot);//open claw
// autoStage(0,1,robot);
// for(int i=250;i<=1000;i+=50){
//   autoStage(1, i,robot);
//   autoStage(0,1,robot);
//   wait(5000);
// }
