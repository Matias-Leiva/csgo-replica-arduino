#include "HardwareSetup.h"
#include "GameMode.h"

void setup()
{
  hardwareSetup();
  lcd.print("CSGO Bomb");
  lcd.setCursor(0, 1);
  lcd.print("Replica");
  delay(3000);
  lcd.clear();
  Serial.print("init");
}

void loop()
{
  selectGameMode();
  lcd.clear();
  lcd.setCursor(0, 0);
  switch (gameMode)
  {
  case 'A':
    lcd.print("Selected Mode A");
    break;
  case 'B':
    lcd.print("Selected Mode B");
    break;
  case 'C':
    lcd.print("Selected Mode C");
    break;
  case 'D':
    lcd.print("Selected Mode D");
    break;
  }
  exit(0);
}