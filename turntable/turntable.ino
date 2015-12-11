#include <Servo.h>
#include <Arduino.h>

int turntablePot=20;//PIN INTITIALIZATIONS
int Redsensor=21;//PIN INTITIALIZATIONS

Servo turntableServo;//SERVO INITIALIZATION


int valctr=2000;//VALUE INITIALIZATIONS
float flameAngle=0;//VALUE INITIALIZATIONS

void setup()
{
	turntableServo.attach(9);	//FOR SERVO
}

float recordFireAngle()
{

/*int turntablePotval=analogRead(turntablePot); 
turntablePotval = map(turntablePotval, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
if using pot...*/

for(float pos=5; pos<175; pos+=0.05)
{
	turntableServo.write(pos);
	
	if(valctr>analogRead(Redsensor))
	{
			valctr=analogRead(Redsensor);
			flameAngle=pos;

	}
}
return flameAngle;

}