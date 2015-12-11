

#define SIDE_CLOSE   10
#define SIDE_FAR     24

float distance_init;
float distance_final;
float distance_end;
float prevIRLeft;
float prevIRRight;
boolean wallDisconnects = false;
int encDiff;
boolean isFirstDetect = false;

int irSideDistance() {
  if (hugLeft) return irLeft.distance();
  else return irRight.distance();
}

boolean checkSide() {
  if (irSideDistance() > SIDE_FAR) {
    encoderWAvgInit = encoderWAvg();
    if (hugLeft) distance_end = prevIRLeft;
    else distance_end = prevIRRight;
    wallDisconnects = true;
  } else {
    wallDisconnects = false;
    encDiff = 0;
    isFirstDetect = false;
  }
}


