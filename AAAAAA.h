
#define ENCODER_USE_INTERRUPTS

#define IRLeft A0
#define IRRight A1

#define SonarTrigger 22 // INPUT pin
#define SonarEcho 23 // OUTPUT pin

#define LCD_W 16
#define LCD_H 2


Servo motorLeft, motorRight, motorBlack, motorRed, balloon;
Encoder encoderLeft(22, 23);
Encoder encoderRight(24, 25);
Encoder encoderBlack(26, 27);
LiquidCrystal lcd(48, 49, 50, 51, 52, 53);
SharpIR irLeft(IRLeft, 1080);
SharpIR irRight(IRRight, 1080);
NewPing sonarFront(SonarTrigger, SonarEcho);

String lcdState = "Initializing...";
String lcdPosition = "";
String line0 = "Finding candle";
String line1 = "Candle found";
String line2 = "Putting out fire";
String line3 = "Fire put out";
String line4 = "Going back";
String line5 = "Beeeccckkk";

boolean hugLeft;

// Drive_System.h
void drive(int x, int y);

// Encoders.h
#define TICKS_PER_INCH  41.67 // wheel's diamater, pi, 360 encoder ticks
#define DEG_TICKS 3.36
#define K 0.5
void encoderWReset();
double encoderDistance();
int encoderWAvg();
double encoderDistanceInit();

// Fire_System.h
void setMotorRed();
boolean fiiireee;
boolean fireFound;
void setMotorRed();

// IMU.h

#define ToRad(x) ((x)*0.01745329252)  // *pi/180
#define ToDeg(x) ((x)*57.2957795131)  // *180/pi
void sumOfVectors();

// IR.h
float distance_init;
float distance_final;
float distance_end;
float prevIRLeft;
float prevIRRight;
boolean wallDisconnects = false;
int encDiff;
boolean isFirstDetect = false;
float prevIR_Left = 6;
float prevIR_Right = 6;
unsigned int IR_Left;
unsigned int IR_Right;
unsigned long initTime;

void setDirection();
void irReadingInit();
void irInitDistance();
int irSideDistance();
void irFinalDistance();

// LCD_Display.h

// Navigation_System.h

// Sonars.h
#define MAX_DISTANCE    200   // Maximum distance (in cm) to ping.
#define PING_INTERVAL   33    // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).
#define FRONT_FAR       25
#define FRONT_CLOSE     15

typedef enum RobotState {
  FORWARD,
  TURN,
  FIRE,
  PUT_OUT_FIRE,
  RED_MOTOR,
  BLACK_MOTOR,
  STOP,
};
RobotState robotState;


void switchState(RobotState rs) {
  if (robotState == FORWARD) sumOfVectors();
  robotState = rs;
  switch(rs) {
    case FORWARD:
      setMotorRed();
      irInitDistance();
      encoderWReset();
      break;
    case TURN:
      encoderWReset();
      break;
    case PUT_OUT_FIRE:
      break;
    case STOP:
      break;
    case RED_MOTOR:
      drive(0, 0);
      break;
  }
}
