//For navigation of the robot


int leftSensor=A5;
int rightSensor=A6;
int frontSensor=A7;
int backSensor=A8;//The sensor pins

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 

}

	

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);            
if(leftSensor==LOW && backSensor==HIGH){ //NEED TO THINK MORE ABOUT THE CONDITIONS...DEFINITELY NOT A DIGITAL VALUE.
       //driveforward
   }
 else if(condition){
       // statement
   } 
   else if{
       // statement
   }
   else {
       // statement
   }   
 //blah blah blah...
                    
}
