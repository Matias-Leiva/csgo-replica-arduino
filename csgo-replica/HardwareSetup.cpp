#include "HardwareSetup.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

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

void hardwareSetup()
{
  pinMode(Buzzer, OUTPUT);
  pinMode(REDLED, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}
