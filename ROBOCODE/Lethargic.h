#ifndef   LETHARGIC_H
#define   LETHARGIC_H
#include "simpletools.h"
#include "servo.h"
#include "GLOBLE.h"


struct Lethargic{
  int (*passive)();
  void (*active)();
};


int PassiveLethargic(int c){
        blinkLED(BLU);
        pause(1000);
        servo_disable(RW);
        servo_disable(LW);
        if (c < COUNTERMAX){
          if (crashDetect() < MINDIST){
            travelStraight(50);
          }else {
            ActiveLethargic();
      } return c+1;

    }else if (c >= COUNTERMAX){
      turnRight(300,2000);
      return 0;
    }
  }

void ActiveLethargic(){
        servo_disable(RW);
        servo_disable(LW);
        sigh();
        pause(2000);
        return;
  }






#endif
