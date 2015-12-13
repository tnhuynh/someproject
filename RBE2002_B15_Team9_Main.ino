/*
 * RBE 2002 - B15 - Final Project - Team 9
 * Author: Trung-Nghia Huynh & Kushagra Kumar
 * Created: 12/ 04/ 2015
 * Last Modified:
 */

#include <Servo.h>
#include <Encoder.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <L3G.h>
#include <LSM303.h>
#include <SharpIR.h>
#include <NewPing.h>
#include <TimerOne.h>

#include "AAAAAA.h"
#include "Drive_System.h"
#include "Encoders.h"
#include "Fire_System.h"
#include "IMU.h"
#include "IR.h"
#include "LCD_Display.h"
//#include "Navigation_System.h"
#include "Sonars.h"

void setup() {

  Serial.begin(9600);
  Serial.print("Initializing robot");
  
  IMUInit();
  pingInit();
  encoderInit();
  servoInit();
  mapInit();
  lcdInit();

  Serial.println("\t");
  Serial.println("...complete");

  sonarReadingInit();
  irReadingInit();
  setDirection();
  setMotorRed();

  switchState(FORWARD);
}

void loop() {

}


