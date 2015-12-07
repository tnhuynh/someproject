/*
 This code prints a line on the LCD screen and automatically
 scrolls the whole line to the left.

 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Author: Trung-Nghia Huynh
 Created: 12/ 06/ 2015
 Last Modified: 12/ 06/ 2015

 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

#define STD_DELAY 250
#define LCD_W 16
#define LCD_H 2
#define INTERRUPT_PIN 2

String line0 = "Finding the candle";
String line1 = "Candle found";
String line2 = "Extinguishing the candle";
String line3 = "Fire has been put out";
String line4 = "Finding my way back home. Wish me luck!";
int lineIndex = 0;
int line = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(LCD_W, LCD_H);
  lcd.setCursor(0, 0);
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), switchLine, RISING);
}

void loop() {
  lcd.setCursor(15, 0);
  lineIndex = line % 5;
  switch (lineIndex) {
    case 0:
      lcd.print(line0);
      break;
    case 1:
      lcd.print(line1);
      break;
    case 2:
      lcd.print(line2);
      break;
    case 3:
      lcd.print(line3);
      break;
    case 4:
      lcd.print(line4);
      break;
  }
  lcd.scrollDisplayLeft();
  delay(STD_DELAY);
  Serial.println(lineIndex);
  
}

void switchLine()
{
  lcd.clear();
  line++;
}

