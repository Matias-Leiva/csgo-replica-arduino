#include "GameMode.h"

char gameMode;
int gameModeLength = 0;
bool modeSelected = false;

void selectGameMode()
{
restartGameModeSelection:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select Game Mode");
  lcd.setCursor(0, 1);
  lcd.print("Mode: ");
  while (gameModeLength < 1)
  {
    lcd.cursor();
    char key = keypad.getKey();
    if (key != NO_KEY)
    {
      Serial.print(key);
      if ((key == 'A') || (key == 'B') || (key == 'C') || (key == 'D'))
      {
        tone(Buzzer, 440);
        gameMode = key;
        gameModeLength++;
        delay(250);
        noTone(Buzzer);
      }
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Mode ");
  lcd.print(gameMode);
  lcd.print(" selected");
  lcd.setCursor(0, 1);
  lcd.print("confirm: y* n#");
  while (!modeSelected)
  {
    lcd.cursor();
    char key = keypad.getKey();
    if (key != NO_KEY)
    {
      if ((key == '#'))
      {
        tone(Buzzer, 440);
        gameMode = ' ';
        gameModeLength = 0;
        modeSelected = false;
        noTone(Buzzer);
        delay(250);
        goto restartGameModeSelection;
      }
      if ((key == '*'))
      {
        tone(Buzzer, 440);
        delay(250);
        noTone(Buzzer);
        modeSelected = true;
      }
    }
  }
}