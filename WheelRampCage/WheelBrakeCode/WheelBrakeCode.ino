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
int brakeRelease = 90;
int brakeRelease2 = 40;
int brakeStop = 60;
int brakeStop2 = 30;

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
    // Release the brake
    brakeServo1.write(brakeRelease);
    delay(15); //wait for the servo to release the wheel
    delay(2000); //wait for the animal to fall to the ramp
    brakeServo1.write(brakeStop);  //stop the wheel
  } 
  if (IRread2 == LOW) {     
    // Release the brake
    brakeServo2.write(brakeRelease2);
    delay(15); //wait for the servo to release the wheel
    delay(2000); //wait for the animal to fall to the ramp
    brakeServo2.write(brakeStop2);  //stop the wheel
  } 
}
