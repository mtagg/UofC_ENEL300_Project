#ifndef   ANGRY_H
#define   ANGRY_H
#include "simpletools.h"
#include "servo.h"
#include "GLOBLE.h"


struct Angry{
  int (*passive)();
  void (*active)();
};

int PassiveAngry(int c){
        servo_disable(RW);
        servo_disable(LW);
        blinkLED(RED);

        if (crashDetect() >= MINDIST && c < COUNTERMAX){
            travelStraight(100);
            return c + 1;
          }else {
            turnRight(300,300);
            return 0;
       }
}

void ActiveAngry(){
      low(RED);
      servo_disable(RW);
      servo_disable(LW);
      while (crashDetect() >= MINDIST){
          servo_speed(LW, 200);//
          servo_speed(RW, 200);//
          pause(100);//
          pause(50);
          }
      servo_disable(RW);
      servo_disable(LW);
      servo_speed(RW, -200);
      servo_speed(LW, 200);
      freqout(BUZZ, 6000, 8000);
      pause(6000);
}


#endif
