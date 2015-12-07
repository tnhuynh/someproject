// Code to test the flame sensors

int red = 11; // pin A11
int black = 2; // pin A2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
//  Serial.print("red sensor: ");
//  Serial.print(analogRead(red));
//  Serial.print("\t");
//  Serial.print("black sensor: ");
  Serial.println(analogRead(black));
}
