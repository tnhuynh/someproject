//For navigation of the robot
//#include "Turningmaze.h"
#include <Servo.h>


int leftMotorSpeed=140;
int rightMotorSpeed=(180-leftMotorSpeed);

int leftSensor=5;
int frontSensor=7;//The sensor PINS at 5 & 7...

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

int IRSensor=22;//IR sensor on pin22
int IRthreshold=1024/2;

Servo leftMotor;
Servo rightMotor;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 

}



void loop() {
  // read the analog in value:
  sensorValue = analogRead(IRSensor);

  if(leftSensor>=IRthreshold){
   turn90();         
 }            
 else if(leftSensor<=IRthreshold && frontSensor>=IRthreshold)
 { 
   driveForward();
 }
 else if(leftSensor<=IRthreshold && frontSensor<=IRthreshold){
   turn90(); 
 } 
 else if(leftSensor<=IRthreshold && frontSensor<=IRthreshold){
   // statement
 }
 else {
   stopMotors();
 }   
}


 void turn90()
 {
  leftMotor.write(leftMotorSpeed);//tank driving 
  rightMotor.write(leftMotorSpeed);
  delay(1500);//for completing 90 degrees...USE THE IMU later to see if the angle turned is 90 degrees.
  leftMotor.write(180);
  rightMotor.write(0);
 }

 void driveForward()
 {
  leftMotor.write(leftMotorSpeed);
  rightMotor.write(rightMotorSpeed);
 }

void stopMotors()
{
  leftMotor.write(90);
  rightMotor.write(90);
}

