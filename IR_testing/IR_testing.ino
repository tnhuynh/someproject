#include <SharpIR.h>

int IRpin = 3; // pin A3

SharpIR sharp(IRpin, 1080);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int d = sharp.distance(); // distance in cm
  Serial.println(d);
  delay(100);
}
