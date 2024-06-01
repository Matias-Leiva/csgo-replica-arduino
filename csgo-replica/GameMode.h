#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

extern char gameMode;
extern int gameModeLength;
extern bool modeSelected;

extern LiquidCrystal_I2C lcd;
extern Keypad keypad;
extern const int Buzzer;

void selectGameMode();

#endif