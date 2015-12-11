
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

float heading;
int xCoor;
int yCoor;

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
  
}
