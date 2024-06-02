#include "GameModeA.h"

char password[4];
int currentLength = 0;

void gameModeA()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter defusing ");
    lcd.setCursor(0, 1);
    lcd.print("Code: ");
    while (currentLength < 4)
    {
        lcd.setCursor(currentLength + 6, 1);
        lcd.cursor();
        char key = keypad.getKey();
        if (key != NO_KEY)
        {
            if ((key != '*') && (key != '#'))
            {
                lcd.print(key);
                password[currentLength] = key;
                currentLength++;
                digitalWrite(LED_BUILTIN, HIGH);
                tone(Buzzer, 250, 100);
                delay(200);
                digitalWrite(LED_BUILTIN, LOW);
            }
        }
    }
    if (currentLength == 4)
    {
        delay(500);
        lcd.noCursor();
        lcd.clear();
        lcd.home();
        lcd.print("You've Entered: ");
        lcd.setCursor(6, 1);
        lcd.print(password[0]);
        lcd.print(password[1]);
        lcd.print(password[2]);
        lcd.print(password[3]);
        delay(2000);
        lcd.clear();
        currentLength = 0;
    }
}
