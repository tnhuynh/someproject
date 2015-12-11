//**************************************PID Function******************************
//CALLING STATEMENT EXAMPLE-
//myPID(Kp_turntable, Ki_turntable, Kd_turntable, 20, analogRead(turntable_pot), posT, turntable_motor);

void myPID(float Kp, float Ki, float Kd, int motorspeed, int actualPos, int setpoint, Servo myservo) {

  int error = (setpoint - actualPos);//error calculation

  if (abs(error) > 20) {

    int p = error * Kp;//Proportional 
    int i = sum * Ki;//Integral
    int d = (error - prevError) * Kd;//Derivative

    Serial.print(" P is ");
    Serial.print(p);
    Serial.print(" I is ");
    Serial.print(i);
    Serial.print(" D is ");
    Serial.print(d);
    Serial.print(" Actual_pos is ");
    Serial.print(actualPos);
    Serial.println();

    myservo.write((p + i + d) + 90);
    sum = sum + error;
    prevError = error;
  }
  else myservo.write(90);
}


