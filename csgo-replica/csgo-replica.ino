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
  lcd.print("Selected Mode ");
  lcd.print(gameMode);
  delay(1500);
  switch (gameMode)
  {
  case 'A':
    gameModeA();
    break;
  case 'B':
    break;
  case 'C':
    break;
  case 'D':
    break;
  }
  exit(0);
}