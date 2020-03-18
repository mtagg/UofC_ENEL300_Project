#ifndef   ANXIOUS_H
#define  ANXIOUS_H
#include "simpletools.h"
#include "servo.h"
#include "GLOBLE.h"

//void PassiveAnxious();
//void AcriveAnxious();
//void anxiousScan();

struct Anxious{
  void (*passive)();
  void (*active)();
};


void PassiveAnxious();
void ActiveAnxious();

void anxiousScan(){
      servo_disable(RW);
      servo_disable(LW);
    }




#endif
