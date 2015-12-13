

void encoderInit() {
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
}

void encoderWReset() {
  encoderLeft.write(0);
  encoderRight.write(0);
}

void encoderBReset() {
  encoderBlack.write(0);
}

int encoderWAvg() {
  int a = (encoderLeft.read() + encoderRight.read()) / 2;
  return a;
}

double encoderDistance() {
  int average = encoderWAvg();
  double inches = average / TICKS_PER_INCH;
  return inches;
}

float encoderWAvgInit;

double encoderDistanceInit() {
  double inches = encoderWAvgInit / TICKS_PER_INCH;
  return inches;
}
