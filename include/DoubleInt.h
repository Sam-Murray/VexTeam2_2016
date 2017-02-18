#ifndef DOUBLE_INT_H
#define DOUBLE_INT_H
class DoubleInt{
private:
  int x;
  int y;
public:
  DoubleInt(){
    x=0;
    y=0;
  }
  DoubleInt(int x1,int y1){
    x=x1;
    y=y1;
  }
  int GetX(){
    return x;
  }
  int GetY(){
    return y;
  }
};
#endif
