/*
 * Trung-Nghia Huynh - tnhuynh
 * RBE2002 Lab 3 - Part 2
 *
 * Code to measure the speed in rpm of the encoder attached with
 * a DC motor that is powered by a supply source. The speed measured
 * varies with different input voltage.
 */

#include <Encoder.h>

Encoder myEnc(22, 23);

long oldPosition  = -999;
long rev = 0;
float rpm = 0;
unsigned long prevTime;
void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");

  //  rev = 0;
  //  rpm = 0;
  prevTime = 0;
}


void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    if (abs(newPosition) % 360 == 0) {
      rev++;
      newPosition = 0;
//      Serial.println(rev);
//      Serial.println(millis());
      if (rev >= 30) {
        rpm = ((float) rev / (millis() - prevTime)) * 60000.0;
        prevTime = millis();

        Serial.print("RPM: \t");
        Serial.println(rpm);
//        Serial.println(prevTime);
//        Serial.println(millis());

        rev = 0;
      }
    }
  }
}
