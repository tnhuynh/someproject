//Author-Kushagra Kumar & Andrew Huynh
//Function related to turning of the robot using pololu motors
//We consider one of the motors as a "master" and the other one as "slave".

//***********************turn180() function***************************************

#include <Encoder.h>
#include <Servo.h>

Servo left_motor;
Servo right_motor;

Encoder encoder_Left;
Encoder encoder_Right;

void turn180()
{
  long tenthsOfInch = 60;
  int masterPower = 70;//Speed of the master motor
  long goal_ticks = (42 * tenthsOfInch);//goal ticks that it needs to achieve
  int totalTicks = 0;//keeps track of the total ticks
  int slavePower = masterPower;
  int error = 0;

  float kp = .001;

  encoder_Left.write(0);
  encoder_Right.write(0);

  while (abs(totalTicks) < goal_ticks)
  {
    left_motor.write(masterPower);//master as the motor
    right_motor.write(slavePower);//slave power that tries to match the master power

    error = -encoder_Left.read() - encoder_Right.read();

    slavePower += error * kp;

    encoder_Left.write(0);
    encoder_Right.write(0);

    //delay(100);

    totalTicks += abs(encoder_Left.read());


    Serial.println(totalTicks);//printing total ticks in the Serial monitor
  }

  //track180();//calls for a helper function

}

//Helper function for turn180()
/*void track180()//tracks to 180 degrees
{
  while (analogRead(lineTrackRight) < 890) {
    left_motor.write(LeftForward);
    right_motor.write(LeftForward);
  }
  right_motor.write(90);
  left_motor.write(90);
}*/
