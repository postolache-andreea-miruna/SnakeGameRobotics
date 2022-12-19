#include "drawMatrix.h"
#include "EEPROMMemo.h"
#include "buzzer.h"
#include "joystickMoves.h"
#include "lcdComands.h"
#include "settingsMenu.h"
#include "mainGame.h"
#include "Menu.h"
#include "player.h"
#include "gameLogic.h"


void setup() {
 //initialize();
 randomSeed(analogRead(A3));

  soundsGame = EEPROM.read(3);
  pinMode(pinSw, INPUT_PULLUP);
  if (soundsGame == 1) {
    sound = true;
  }
  else {
    sound = false;
  }
  speedPosition = EEPROM.read(35);
  contrastPosition = EEPROM.read(0);
  brightnessPosition = EEPROM.read(1);
  difficultyPosition = EEPROM.read(34);
  brightnessMatrixPosition = EEPROM.read(2);

  pinMode(contrastPin, OUTPUT);
  pinMode(brightPin, OUTPUT);

  lcd.begin(columnsLCD, rowsLCD);
  lcd.clear();
  lcd.setCursor(0, 0);
  
  lcd.createChar(0, heart);
  lcd.createChar(2, smiley);
  lcd.createChar(3, doubleArrows);
  lcd.createChar(4, downArrow);
  lcd.createChar(5, upArrow);
  lcd.createChar(6,buttonPress);

  lc.shutdown(0, false);                 // turn off power saving, enables display
  lc.setIntensity(0, matrixBrightnessValue[brightnessMatrixPosition]);  // sets brightness (0~15 possible values)
  lc.clearDisplay(0);                    // clear screen
  analogWrite(brightPin, lcdBrightnessValue[brightnessPosition]);
  analogWrite(contrastPin, lcdContrastValue[contrastPosition]);

  snake[0][0] = 0; 
  snake[0][1] = 3;
  snake[1][0] = 0; 
  snake[1][1] = 2;

  wall[0][0] = 0;
  wall[0][1] = 0;

  wall[1][0] = 0;
  wall[1][1] = 7;

  wall[2][0] = 7;
  wall[2][1] = 0;

  wall[3][0] = 7;
  wall[3][1] = 7;

  wall[4][0] = 3;
  wall[4][1] = 3;

  wall[5][0] = 3;
  wall[5][1] = 4;

  greeting();
  menuPart();

  Serial.begin(9600);
}

void loop() {
  gameStates();
}
