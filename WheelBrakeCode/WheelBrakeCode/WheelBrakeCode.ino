/* 
  Ramp Cage IR and Wheel Brake
*/

#include <Servo.h>
Servo brakeServo1;
Servo brakeServo2;

//PINS
const int IR1 = 4;
const int IR2 = 5;
const int servoPin1 = 9;
const int servoPin2 = 10;

// variables
int IRread1 = 0;
int IRread2 = 0;

/////////USER VARIABLES////////////
int brakeApplyTime = 15; //duration when animal is at the top of the wheel after IR identification and before releasing brake
int brakeReleaseTime = 2000; //duration when animal is rolling off wheel before applying brake
int brakeRelease = 40; //brake servo value when released
int brakeRelease2 = 40;
int brakeStop = 24;    //brake servo value when stopped
int brakeStop2 = 20;
int reward_time = 30000;

void setup() {
  // initialize the sensor pin as an input:
  pinMode(IR1, INPUT_PULLUP);     
  digitalWrite(IR1, HIGH); // turn on the pullup
  pinMode(IR2, INPUT_PULLUP);     
  digitalWrite(IR2, HIGH); // turn on the pullup
  brakeServo1.attach(servoPin1);
  brakeServo2.attach(servoPin2);
  Serial.begin(9600);

  brakeServo1.write(brakeStop); //Begin with the wheel stopped
  brakeServo2.write(brakeStop2); //Begin with the wheel stopped
}

void loop(){
  // read the state of the pushbutton value:
  IRread1 = digitalRead(IR1);
  IRread2 = digitalRead(IR2);

  // check if the sensor beam is broken
  // if it is, the IRread is LOW:
  if (IRread1 == LOW) {   
    delay(reward_time);
    // Release the brake
    brakeServo1.write(brakeRelease);
    delay(brakeApplyTime); //wait for the servo to release the wheel
    delay(brakeReleaseTime); //wait for the animal to fall to the ramp
    brakeServo1.write(brakeStop);  //stop the wheel
  } 
  if (IRread2 == LOW) {   
    delay(reward_time);    
    // Release the brake
    brakeServo2.write(brakeRelease2);
    delay(brakeApplyTime); //wait for the servo to release the wheel
    delay(brakeReleaseTime); //wait for the animal to fall to the ramp
    brakeServo2.write(brakeStop2);  //stop the wheel
  } 
}
