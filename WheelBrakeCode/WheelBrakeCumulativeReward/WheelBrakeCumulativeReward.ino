/* 
  Ramp Cage IR and Wheel Brake
*/

#include <Servo.h>
Servo brakeServo1;
Servo brakeServo2;

//PINS
const int IR1 = 4;
const int IR2 = 5;

// variables
int IRread1 = 0;
int IRread2 = 0;
int brakeRelease = 40;
int brakeRelease2 = 40;
int brakeStop = 20;
int brakeStop2 = 20;
int reward_time = 30000;
int cumulative_time_1 = 0;
int cumulative_time_2 = 0;


void setup() {
  // initialize the sensor pin as an input:
  pinMode(IR1, INPUT_PULLUP);     
  digitalWrite(IR1, HIGH); // turn on the pullup
  pinMode(IR2, INPUT_PULLUP);     
  digitalWrite(IR2, HIGH); // turn on the pullup
  brakeServo1.attach(9);
  brakeServo2.attach(10);
  Serial.begin(9600);

  brakeServo1.write(brakeStop); //Start the wheel stopped
  brakeServo2.write(brakeStop2); //Start the wheel stopped
}

void loop(){
  // read the state of the pushbutton value:
  IRread1 = digitalRead(IR1);
  IRread2 = digitalRead(IR2);

  // check if the sensor beam is broken
  // if it is, the IRread is LOW:
  if (IRread1 == LOW) {
    delay(100);
    while (IRread1 == LOW){
        cumulative_time_1 += 100;
        if (cumulative_time_1 >= reward_time){
          cumulative_time_1 = 0;
          brakeServo1.write(brakeRelease);
          delay(2000); //wait for the animal to fall to the ramp
          brakeServo1.write(brakeStop);  //stop the wheel
        }
        
    }
    
  } 

  if (IRread2 == LOW) {
    delay(100);
    while (IRread2 == LOW){
        cumulative_time_2 += 100;
        if (cumulative_time_2 >= reward_time){
          cumulative_time_2 = 0;
          brakeServo2.write(brakeRelease);
          delay(2000); //wait for the animal to fall to the ramp
          brakeServo2.write(brakeStop);  //stop the wheel
        }
        
    }
    
  } 
}
