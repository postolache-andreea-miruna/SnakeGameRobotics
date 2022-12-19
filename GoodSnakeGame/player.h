const int firstNamePosition = 0;
const int lastNamePosition = namePl.length() - 1;

const String characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
const int firstCharacterPosition = 0;
const int lastCharacterPosition = characters.length() - 1;

void blink() {
  characterPosition = lastCharacterPosition;
  namePl[namePosition] = characters[characterPosition];
  printNamePlayer(namePl);
  characterPosition = characterPosition1;
  namePl[namePosition] = characters[characterPosition];
  printNamePlayer(namePl);
}
void printingName() {
  characterPosition1 = characterPosition;
  namePl[namePosition] = characters[characterPosition];
  printNamePlayer(namePl);
}
void scrollPlayer() {

  placeNamePlayer();

  if (joystickUp()) {
   
    characterPosition --;
    if (characterPosition < firstCharacterPosition) {
      characterPosition = firstCharacterPosition;
    }
    printingName();
  }
  else if (joystickDown()) {
    characterPosition ++;
    if (characterPosition > lastCharacterPosition) {
      characterPosition = lastCharacterPosition;
    }
    printingName();
  }
  else if (joystickRight()) {
    namePosition ++;
    if (namePosition > lastNamePosition) {
      namePosition = lastNamePosition;
    }
    characterPosition = characters.indexOf(namePl[namePosition]);
    printingName();
  }
  else if (joystickLeft()) {
    namePosition --;
    if (namePosition < firstNamePosition) {
      namePosition = firstNamePosition;
    }
    characterPosition = characters.indexOf(namePl[namePosition]); 
    printingName(); 
  }
  else if (joystickPress()) {
    newHighScore(score,namePl);
    writePlayerName = false;
    transitionToMenu = true;
  }
}
