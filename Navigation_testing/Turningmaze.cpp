#include "Servo.h"
#include "Arduino.h"
#include "Turningmaze.h"

/*int leftMotorSpeed=140;
int rightMotorSpeed=(180-leftMotorSpeed);

Servo leftMotor;
Servo rightMotor;*/

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
