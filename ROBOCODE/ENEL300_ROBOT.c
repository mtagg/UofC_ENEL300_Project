/*

*/

#include "simpletools.h"
#include "servo.h"
#include "ping.h"
#include "Lethargic.h"
#include "Anxious.h"
#include "Angry.h"
#include "Scared.h"
#include "GLOBLE.h"

int main()
{
  counter = 0;        // used to determine travel distance/timing
  high(RED);
  high(GRN);
  high(BLU); 
  low(BUZZ);
       
  int emotionalState = 0;
               // = 0; //Lethargic
               // = 1; //Anxious
               // = 2; //Angry
               // = 3; //Scared
 
  struct Lethargic lethargic;
  lethargic.passive = PassiveLethargic;
  lethargic.active = ActiveLethargic;

  struct Anxious anxious;
  anxious.passive = PassiveAnxious;
  anxious.active = ActiveAnxious;

  struct Angry angry;
  angry.passive = PassiveAngry;
  angry.active = ActiveAngry;

  struct Scared scared;
  scared.passive = PassiveScared;
  scared.active = ActiveScared;

  

  while(1){
    if     (emotionalState==0){ // lethargic
          lethargic.passive();
        }          
    else if(emotionalState==1); // anxious
    else if(emotionalState==2){ // angry state
      if (input(RED_BUTTON) == 0){
          angry.active();
         }else { counter = angry.passive(counter);}
    }else if(emotionalState==3); // scared



    else{ //blinking LED code to show show code error
      blinkLED(26);
      pause(50);
      blinkLED(27);
      }
    counter ++;
  }


}
