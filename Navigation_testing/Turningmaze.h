/*
  Turningmaze.h - Library for flashing Morse code.
  Created by Kushagra Kumar, December 7, 2015.
*/

#ifndef _TURNINGMAZE_H_
#define _TURNINGMAZE_H_

#include "Servo.h"
#include "Arduino.h"

#define leftMotorSpeed=140
#define rightMotorSpeed=(180-leftMotorSpeed)

void driveForward();
void turn90();
void stopMotors();

#endif
