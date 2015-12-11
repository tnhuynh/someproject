

#define LIMIT         20

#define MotorLeft     4
#define MotorRight    5
#define MotorBlack    8
#define MotorRed      10
#define Balloon       11

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

//--------------//

int currentSpeed;
int desiredSpeed;
int lastLeftSpeed;
int lastRightSpeed;
float endAngle;
float botAngle;

void servoEnd() {
//  terminate();
  currentSpeed = desiredSpeed;
  lastLeftSpeed = 0;
  lastRightSpeed = 0;
  endAngle = botAngle;
}

int leftSpeed;
int rightSpeed;
long currentEncoderLeft;
long currentEncoderRight;

void manualDriveSpeed(int left, int right) {
  if ((left != lastLeftSpeed) || (right != lastRightSpeed)) {
    leftSpeed = left;
    rightSpeed = right;
    lastLeftSpeed = left;
    lastRightSpeed = right;
  } 
//  else if (wait(100) == true) {
//    currentEncoderLeft = encoderLeft.read();
//    currentEncoderRight = encoderRight.read();
//  }
}

