#ifndef HARDWARESETUP_H
#define HARDWARESETUP_H

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;
extern Keypad keypad;
extern const int Buzzer;
extern const int REDLED;

void hardwareSetup();

#endif
