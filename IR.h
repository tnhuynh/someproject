// IR.h

/*----------------------------------------------*/

#define SIDE_FAR     24
#define SIDE_CLOSE   10

void irReadingInit() {
  long time_init = millis();
  while (millis() - initTime < 3000) {
    prevIR_Left = IR_Left;
    prevIR_Right = IR_Right;

    IR_Left = irLeft.distance();
    IR_Right = irRight.distance();
  }
}

int irSideDistance() {
  if (hugLeft) {
    IR_Left = irLeft.distance();
    return IR_Left;
  }
  else {
    IR_Right = irRight.distance();
    return IR_Right;
  }
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


void setDirection() {
  hugLeft = IR_Left < IR_Right;
}

void irInitDistance() {
  distance_init = irSideDistance();
  if (distance_init > FRONT_CLOSE) isFirstDetect = true;
}

void irFinalDistance() {
  distance_final = irSideDistance();
}

