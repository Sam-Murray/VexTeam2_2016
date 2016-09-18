#ifndef MOTOR_UNIT_H
#define MOTOR_UNIT_H

class MotorUnit
{
public:
  MotorUnit(int p);
  void setSpeed(int speed);
private:
  int channel;
  int speed;
};

#endif
