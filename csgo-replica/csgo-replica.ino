#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

char gameMode;
int gameModeLength = 0;
bool modeSelected = false;

unsigned long duracion = 100;

LiquidCrystal_I2C lcd(0x27, 16, 2); // Rs, E, D4, D5, D6, D7;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
};
byte colPins[COLS] = {6, 7, 8, 9};
byte rowPins[ROWS] = {2, 3, 4, 5};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int Buzzer = 10;
const int REDLED = 11;

void setup()
{
  pinMode(Buzzer, OUTPUT);
  pinMode(REDLED, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("CSGO Bomb");
  lcd.setCursor(0, 1);
  lcd.print("Replica");
  delay(3000);
  lcd.clear();
  Serial.print("init");
}

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
    key == NO_KEY;
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
    key == NO_KEY;
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

void loop()
{
  selectGameMode();
  lcd.clear();
  lcd.setCursor(0, 0);
  // TODO make gamemodes;
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
