#ifndef ACTION_H
#define ACTION_H

class Action{
private:
public:
  //Param param is any parameter you might need for the action(maybe should be an array, who cares though)
  //returns the time it will take
  virtual void ExecuteAction(int Param){
    return;
  }


};
#endif
