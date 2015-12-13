// Drive_System.h

/*----------------------------------------------*/

int turnTicks;

void servoInit() {
  motorLeft.attach(MotorLeft);
  motorRight.attach(MotorRight);
  motorBlack.attach(MotorBlack);
  motorRed.attach(MotorRed, 1000, 2000);
  balloon.attach(Balloon);
  motorLeft.write(90);
  motorRight.write(90);
  motorBlack.write(90);
  motorRed.write(90);
  balloon.write(90);
}

void drive(int x, int y) {
  if (x > 100)        x = 100;
  else if (x < -100)  x = -100;
  if (y > 100)        y = 100;
  else if (y < -100)  y = -100;

  if (x > 0 && x < LIMIT)   x = LIMIT;
  if (x > -LIMIT && x < 0)  x = -LIMIT;
  if (y > 0 && y < LIMIT)   y = LIMIT;
  if (y > -LIMIT && y < 0)  y = -LIMIT;

  motorLeft.writeMicroseconds(map(x, -100, 100, 1000, 2000));
  motorRight.writeMicroseconds(map(y, -100, 100, 2000, 1000));
}

void readyTurnDisconnect() {
  float distance_error = asin((distance_end - distance_init) / encoderDistanceInit());
  float ticks_error = DEG_TICKS * ToDeg(distance_error);

  if (distance_init > FRONT_FAR) ticks_error = 0;
  if (hugLeft) {
    turnTicks = -TICKS_TO_TURN;
    turnTicks += ticks_error;
  } else {
    turnTicks = TICKS_TO_TURN;
    turnTicks += -ticks_error;
  }
}

int error_accum;

void readyTurnCorner() {
  irFinalDistance();
  float distance_error = asin((distance_end - distance_init) / encoderDistance());
  float ticks_error = DEG_TICKS * ToDeg(distance_error);

  if (distance_init > FRONT_FAR) ticks_error = 0;
  if (hugLeft) {
    turnTicks = TICKS_TO_TURN;
    turnTicks += -ticks_error;
  } else {
    turnTicks = -TICKS_TO_TURN;
    turnTicks += ticks_error;
  }
  error_accum = 0;
}

boolean turnComplete() {
  int pos_left = encoderLeft.read();
  int pos_right = encoderRight.read();

  if (abs(pos_left - turnTicks) < 10 &&
      abs(pos_right + turnTicks) < 10) {
        wallDisconnects = false;
        encDiff = 0;
        return true;
      }

  float speed_wheel;
  if (turnTicks > 0) speed_wheel = 1.5;
  else speed_wheel = -1.5;

  int speed_left = speed_wheel * (abs(turnTicks) - abs(pos_left));
  int speed_right = speed_wheel * (abs(turnTicks) - abs(pos_right));

  drive (speed_left, speed_right);
  return false;
}

int storedEncoderWAvg;

boolean goBackwards() {
  int error_encoder = encoderLeft.read() - encoderRight.read();

  if ((encoderWAvg() - storedEncoderWAvg) < -80) return true;

  drive(-50 - K * error_encoder, -50 + K * error_encoder);
  return false;
}


boolean goForwards() {
  if (fireFound && irSideDistance() < 50) return false;

  int error_ir = IR_Left - IR_Right;
  if (abs(error_ir) > 10) error_ir = 0;
  error_ir *= 2;

  if (IR_Right > prevIR_Right)      error_accum += -30;
  else if (IR_Right < prevIR_Right) error_accum += 30;
  if (IR_Left > prevIR_Left)        error_accum += 30;
  else if (IR_Left < prevIR_Left)   error_accum += -30;

  int error_encoder = encoderLeft.read() - encoderRight.read();
  int error_total = error_encoder + error_accum;

  drive(50 - K * error_total - error_ir,
        50 + K * error_total + error_ir);
  return true;
}
