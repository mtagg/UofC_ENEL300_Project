#ifndef    GLOBLE_H
#define    GLOBLE_H
#include "simpletools.h"
#include "servo.h"
#include "ping.h"

//Global-Functions/MACROS//

#define RW 13 //right wheel  negative speed for forward motion
#define LW 12 // left wheel positive speed for forward emotion
#define COUNTERMAX 20
#define BLU  0   // GND trigger
#define GRN  1   // GND trigger
#define RED  2   // GND trigger
#define ECHO 6      //ultrasonic pin for sensor input
#define TRIGGER 5 // ultrasonic pin for trigger0
#define NECK 13  //Motor pin for the neck
#define MINDIST 50 // minimum distance required to disregard chance of collision (cm)
#define RED_BUTTON 4 // trigger for ActiveAngry mode
#define BUZZ 7
#define MIC_D0 9
#define MIC_A0 10



int counter;
int countermax = 1000;

void blinkLED(int ledpin){
      toggle(ledpin);
}

int crashDetect(){
        low(TRIGGER); //off
        pause(2);
        high(TRIGGER);//send sonic wave for 10us pulse
        pause(0.1);
        low(TRIGGER);//off
        return ping_cm(ECHO);
  }
void travelStraight(int SPEED){
        servo_speed(RW,-SPEED);
        servo_speed(LW, SPEED);
        pause(1000);
  }

void turnLeft(int LOAD, int PAUSE){ // Load = servo_angle, Pause = pause time before returning
        servo_speed(12,0);
        servo_speed(13,0);
        servo_angle(LW,LOAD);
        servo_angle(RW,LOAD);
        pause(PAUSE);
        return;
  }
void turnRight(int LOAD, int PAUSE){
        servo_speed(12,0);
        servo_speed(13,0);
        servo_angle(LW,-LOAD);
        servo_angle(RW,-LOAD);
        pause(PAUSE);
        return;
  }
  void sigh(){
          servo_speed(RW, 0);
          servo_speed(LW, 0);
          freqout(BUZZ, 400, 261);
          freqout(BUZZ, 400, 423);
          freqout(BUZZ, 700, 100);
          pause(1000);
  }



#endif
