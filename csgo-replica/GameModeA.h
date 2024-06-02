#ifndef GAMEMODEA_H
#define GAMEMODEA_H

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

extern char password[];
extern int currentLength;

extern LiquidCrystal_I2C lcd;
extern Keypad keypad;
extern const int Buzzer;

void gameModeA();

#endif