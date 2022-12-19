void gameStates() {
  if (startGame == false) {
    if (millis() - previousMillis > gameStateDelay) {
      if (state1Menu == true)
        scrollMenu();
      if (toMainMenu == true && joystickPress()) {
        state1Menu = true;
        state2Menu = false;
        toMainMenu = false;

        snake[32][2] = {};
        snake[0][0] = 0; 
        snake[0][1] = 3;
        snake[1][0] = 0; 
        snake[1][1] = 2;

        foodSnake[1][2] = {};
        foodSnake[0][0] = 0;
        foodSnake[0][1] = 5;

        snakeLength = 2;
        wallsOn = 0;
        snakeDirection = 0;
        score = 0;
        lastBlink = 0;
        previousMillis2 = 0;
        moveInterval = 200;
        matrixChanged = false;
        foodState = false;
        lastMoved = 0;
        dead = false;
        menuPart();
      } 
      else if (state2Menu == true && menuPartPosition == 1)
        scrollHighScoreMenu();
      else if (state2Menu == true && menuPartPosition == 3)
        scrollAboutMenu();
      else if (state2Menu == true && menuPartPosition == 4)
        scrollHowPlayMenu();
      if (startSetting == true && state2Setting == false ) {
        settingPart();
        startSetting = false;
      }
      if (state1Setting == true && state2Setting == false &&  startSetting == false)
        scrollSettings();
      if (joystickRight() && state1Setting == true && state2Setting == false && settingPartPosition != 5 && settingPartPosition != 7 && firstEnterSettings == 1) {
        delay(gameStateDelay);
        firstEnterSettings = 2;
      }
      if (joystickRight() && state1Setting == true && state2Setting == false && settingPartPosition != 5 && settingPartPosition != 7 && firstEnterSettings != 1 && firstEnterSettings != 0) 
        settingsCommandsSwitch();

      if (state2Setting == true && settingPartPosition == 0 )
        difficultyMenu();
      if (state2Setting == true && settingPartPosition == 1)
        contrastMenu();
      if (state2Setting == true && settingPartPosition == 2)
        brightLCDMenu();
      if (state2Setting == true && settingPartPosition == 3)
        brightMatrixMenu();
      if (state2Setting == true && settingPartPosition == 4)
        soundMenu();
      if (state2Setting == true && settingPartPosition == 6)
        speedMenu();

      if (state1Setting == true && state2Setting == false && joystickPress() && settingPartPosition == 5) { // reset highscore
        initializeNameAndScores();
      }

       if (state1Setting == true && state2Setting == false && joystickLeft() && settingPartPosition == 7) { //back to menu
        
        settingPartPosition = 0;
        state1Menu = true;
        state2Menu = false;
        state1Setting = false;
        menuPart();
      }
      previousMillis = millis();
    }
  } 
  else {
    if (writePlayerName == true) {
      if (millis() - previousMillis2 > gameStateDelay) {
        scrollPlayer();
        blink();
        previousMillis2 = millis();
      }
    }
    else if (transitionToMenu == true) {
      if (millis() - previousMillis2 > gameStateDelay) {
        goToMenu();
        transitionToMenu = false;
        toMainMenu = true;
        previousMillis2 = millis();
      }
    } 
    else
      setupGame();

  }
}