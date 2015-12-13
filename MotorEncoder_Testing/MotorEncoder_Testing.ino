/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>
#include <Servo.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(22, 23);

const int motorPin1 = 13;
const int motorPin2 = 12;

void setup() {
  Serial.begin(9600);
  Serial.println("Motor Encoder Test:");

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

}

long oldPosition  = -999;

void loop() {

//  digitalWrite(motorPin1, HIGH);
//  digitalWrite(motorPin2, HIGH);
//  delay(100);
//  digitalWrite(motorPin1, LOW);
//  digitalWrite(motorPin2, LOW);
//  delay(100);

  analogWrite(motorPin1, 255);
  analogWrite(motorPin2, 255);
  
  long d = myEnc.read();
  Serial.println(d);

//  long newPosition = myEnc.read();
//  if (newPosition != oldPosition) {
//    oldPosition = newPosition;
//    Serial.println(newPosition);
//  }
}
