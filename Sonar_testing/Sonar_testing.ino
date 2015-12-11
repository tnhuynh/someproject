
#include <NewPing.h>

const int triggerPin = 22; // digital pin 22
const int echoPin = 23; // digital pin 23
int d;

NewPing sonar(triggerPin, echoPin, 200);

void setup() {
  Serial.begin(9600);
}

void loop() {
  d = sonar.ping();
  Serial.print("Ping: ");
  Serial.print(d/US_ROUNDTRIP_CM);
  Serial.println("cm");
  delay(100);
}
