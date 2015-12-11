
void lcdInit() {
  lcd.begin(LCD_W, LCD_H);
  lcd.setCursor(0, 0);
}

void lcdUpdate() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(lcdState);
  lcd.setCursor(0, 1);
  lcd.print(lcdPosition);
}

