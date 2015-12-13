// Fire_System.h

#define RedSensor A2
#define BlackSensor A3

#define Fire_Limit 900

int redAngle;

boolean fireCheck() {
  if (fiiireee) {
    fireFound = analogRead(RedSensor) < Fire_Limit;
    if (fireFound) {
      fiiireee = false;
      return true;
    }
  }
  return false;
}

int limit (int reading) {
  if (reading > 180) return 180;
  else if (reading < 0) return 0;
  else return reading;
}

boolean firePutOut() {
  
}

boolean fireSearch() {
  const int x_min = 10;
  const int x_max = 170;

  static int desiredReading = 1010;
  static int x_final;
  static unsigned long prevTime;
  static int x_pos = x_min;

  if ((millis() - prevTime) > 70) {
    prevTime = millis();
    if (x_pos >= x_max) {
      x_pos = x_min;
      delay(100);
    }
    
    int prevReading = analogRead(RedSensor);
    if (prevReading < desiredReading) {
      x_final = x_pos;
    }

    x_pos += 5;
    motorRed.write(x_pos);
    return false;
  }
}


void setMotorRed() {
  if(hugLeft) motorRed.write(170);
  else motorRed.write(10);
}

boolean fireTurnSearch() {
  drive(0, 0);
  int redReading = analogRead(RedSensor) + 100;
  for (float i = 10; i < 170; i += 0.002) {
    motorRed.write(i);
    if (analogRead(RedSensor) <= redReading) {
      redReading = analogRead(RedSensor);
      if (redReading < Fire_Limit) {
        fireFound = true;
        redAngle = i;
      }
    }
  }
  return fireFound;
}

