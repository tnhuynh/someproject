#include <Servo.h>
#include <Arduino.h>

int sliderPot=23;//PIN INTITIALIZATIONS
int Blacksensor=24;//PIN INTITIALIZATIONS


float height=0;//to calculate the height of the flame
int sliderHeight=10;//Total height of the slider  

Servo sliderServo;//SERVO INITIALIZATION


int valctr=2000;//VALUE INITIALIZATIONS
float flamePosB=0;//VALUE INITIALIZATIONS

void setup()
{
	sliderServo.attach(10);
}

void loop()
{
	
}



float BlacksensorScan() //Scans for the flame, aligns in front of the flame and returns the height of the flame
{

for(float pos=1; pos<179; pos+=0.05)//Scanning up
{
	sliderServo.write(pos);
	
	if(valctr>analogRead(Blacksensor))
	{
			valctr=analogRead(Blacksensor);
			flamePosB=pos;
	}
}

for(float pos=179; pos>1; pos-=0.05)
{
	sliderServo.write(pos);
	
	if(valctr>analogRead(Blacksensor))
	{
			valctr=analogRead(Blacksensor);
			flamePosB=pos;
	}
}
sliderServo.write(flamePosB);//Go to the point where the sensor records the value that corresponds to the flame

//return flamePosB;//returning the positon for the angle

float height=(flamePosB/180)*sliderHeight;
return height;
}


