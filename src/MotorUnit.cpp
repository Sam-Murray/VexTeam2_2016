#include "MotorUnit.h"


MotorUnit::MotorUnit(int p): channel(p), speed(0)
{
}
// MotorUnit::MotorUnit(): channel(1), speed(0)
// {
// }
void MotorUnit::setSpeed(int s)
{
  if(s != speed)
    printf("Setting motor: %d to %d\r\n", channel, speed);
  speed = s;
  motorSet(channel, speed);

}
