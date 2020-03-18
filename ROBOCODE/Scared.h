#ifndef   SCARED_H
#define   SCARED_H
#include "simpletools.h"
#include "servo.h"
#include "GLOBLE.h"

//void PassiveScared();
//void ActiveScared();
//void creepBack();
//void run();

struct Scared{
  void (*passive)();
  void (*active)();
};


      void PassiveScared(){
        servo_disable(RW);
        servo_disable(LW);
      }
      void ActiveScared(){
        servo_disable(RW);
        servo_disable(LW);
      }
      void creepBack (){
        servo_speed(RW, 0);
        servo_speed(LW, 0);
        }
      void run (){
        servo_disable(RW);
        servo_disable(LW);
        servo_speed(RW,-300);
        servo_speed(LW, 300);
        }




#endif
