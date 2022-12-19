int snake[32][2] = {};
int wall[6][2] = {};  //wall[][0] = line; wall[][1] = column
int foodSnake[1][2] = {{0,5}};
int snakeLength = 2;
byte wallsOn = 0;
const int gameStateDelay = 300;
/*
Directions for snake
0 - stay
1 - up
2 - down
3 - left
4 - right
*/
byte snakeDirection = 0;

//food
byte lastFoodPosX;
byte lastFoodPosY;

byte newFoodPosX;
byte newFoodPosY;

//random interval 
const int minValue = 0;
const int maxValue = 8;

int score = 0;

const int blinkInterval = 500;
unsigned long long lastBlink;

unsigned long previousMillis2 = 0;
int moveInterval = 200;

bool matrixChanged = false;
bool foodState = false;
unsigned long long lastMoved = 0;
bool dead = false;

void turnOnTheWalls() {
  if (EEPROM.read(34) == 1) {  //medium
    wallsOn = 4;
    for (int i = 0; i < wallsOn; i++) {
      lc.setLed(0, wall[i][0], wall[i][1], true);
    }
  } 
  else if (EEPROM.read(34) == 2) {  //hard
    wallsOn = 6;
    for (int i = 0; i < wallsOn; i++) {
      lc.setLed(0, wall[i][0], wall[i][1], true);
    }
  }
}

void updateMatrix() {
  lc.setLed(0, snake[snakeLength - 1][0], snake[snakeLength - 1][1], false);
  for (int i = snakeLength - 1; i > 0; i--) {
    snake[i][0] = snake[i - 1][0];
    snake[i][1] = snake[i - 1][1];
    lc.setLed(0, snake[i][0], snake[i][1], true);
  }
}

void updatePositions() {
  /*
    If the snake was not moving up/down/right/left and I move joystick down/up/left/right,
    then the direction of the snake change to down/up/left/right.
  */
  if (joystickDown() && snakeDirection != 1) {  
    snakeDirection = 2;
    updateMatrix();
    
    if (snake[0][0] < matrixSize - 1) {  //the head is on a row that is inside the matrix
      snake[0][0]++;
      lc.setLed(0, snake[0][0], snake[0][1], true);
    } 
    else {
      snake[0][0] = 0;  //the head go on the first row
      lc.setLed(0, snake[0][0], snake[0][1], true);
    }
  }
  else if (joystickUp() && snakeDirection != 2) {  
    snakeDirection = 1;
    
    updateMatrix();
    if (snake[0][0] > 0) {  //the head is on a row that is inside the matrix
      snake[0][0]--;
      lc.setLed(0, snake[0][0], snake[0][1], true);
    } 
    else {
      snake[0][0] = 7;  //the head go on the last row
      lc.setLed(0, snake[0][0], snake[0][1], true);
    }
  }
  else if (joystickRight() && snakeDirection != 3) { 
    snakeDirection = 4;

    updateMatrix();
    if (snake[0][1] < matrixSize - 1) {  //the head is on a column that is inside the matrix
      snake[0][1]++;
      lc.setLed(0, snake[0][0], snake[0][1], true);    
    } 
    else {
      snake[0][1] = 0;  //the head go on the first column
      lc.setLed(0, snake[0][0], snake[0][1], true);
    }
  }
  else if (joystickLeft() && snakeDirection != 4) {  
    snakeDirection = 3;
    updateMatrix();
    if (snake[0][1] > 0) {  //the head is on a column that is inside the matrix
      snake[0][1]--;
      lc.setLed(0, snake[0][0], snake[0][1], true);
    } 
    else {
      snake[0][1] = 7;  //the head go on the last column
      lc.setLed(0, snake[0][0], snake[0][1], true);
    }
  }
  else if (snakeDirection != 0) { //if the snake move
    if (snakeDirection == 1) { //up
      updateMatrix();
      if (snake[0][0] > 0) {  
        snake[0][0]--;
        lc.setLed(0, snake[0][0], snake[0][1], true);
      } 
      else {
        snake[0][0] = 7;  
        lc.setLed(0, snake[0][0], snake[0][1], true);
      }
    }
    else if (snakeDirection == 2) { //down
      updateMatrix();
      if (snake[0][0] < matrixSize - 1) { 
        snake[0][0]++;
        lc.setLed(0, snake[0][0], snake[0][1], true);
      } 
      else {
        snake[0][0] = 0;
        lc.setLed(0, snake[0][0], snake[0][1], true);
      }
    }
    else if (snakeDirection == 3) { //right
      updateMatrix();
      if (snake[0][1] > 0) {  
        snake[0][1]--;
        lc.setLed(0, snake[0][0], snake[0][1], true);
      } 
      else {
        snake[0][1] = 7; 
        lc.setLed(0, snake[0][0], snake[0][1], true);
      }
    }
    else if (snakeDirection == 4) { //left
      updateMatrix();
      if (snake[0][1] < matrixSize - 1) {  
        snake[0][1]++;
        lc.setLed(0, snake[0][0], snake[0][1], true);    
      } 
      else {
        snake[0][1] = 0;  
        lc.setLed(0, snake[0][0], snake[0][1], true);
      }
    }
  }
}

void foodBlink() {
  if (foodState == true) { 
    lc.setLed(0, foodSnake[0][0], foodSnake[0][1], false);
    foodState = false;    
  }
  else {
   lc.setLed(0, foodSnake[0][0], foodSnake[0][1], true);
   foodState = true;
  }
}

bool isSnakeBody(byte x, byte y) {
  for (int i = 0; i < snakeLength; i++) {
    if (snake[i][0] == newFoodPosX && snake[i][1] == newFoodPosY) {
      return true;
    }
  }
  return false;
}
bool isWall(byte x, byte y) {
  if (EEPROM.read(34) != 0) {
    for (int i = 0; i < wallsOn; i++) {
      if (wall[i][0] == newFoodPosX && wall[i][1] == newFoodPosY) {
        return true;
      }
    }
    return false;
  }
  else
    return false; //if I have no wall then the food can bee generate anywhere
}
void generateFood() {

  newFoodPosX = random(minValue, maxValue);
  newFoodPosY = random(minValue, maxValue);

  while (isSnakeBody(newFoodPosX, newFoodPosY) == true) {
    newFoodPosX = random(minValue, maxValue);
    newFoodPosY = random(minValue, maxValue);
  }
  while (isWall(newFoodPosX, newFoodPosY) == true) {
    newFoodPosX = random(minValue, maxValue);
    newFoodPosY = random(minValue, maxValue);
  }

  lc.setLed(0, snake[0][0], snake[0][1], true);

  foodSnake[0][0] = newFoodPosX;
  foodSnake[0][1] = newFoodPosY;
  Serial.println(foodSnake[0][0]);
  Serial.println(foodSnake[0][1]);
  lc.setLed(0, foodSnake[0][0], foodSnake[0][1], true);
  foodState = true;
}
void setupGame() {
  turnOnTheWalls();

  if (EEPROM.read(34) == 1  //hit the walls in medium level
      && (((snake[0][0] == wall[0][0]) && (snake[0][1] == wall[0][1])) || ((snake[0][0] == wall[1][0]) && (snake[0][1] == wall[1][1]))
          || ((snake[0][0] == wall[2][0]) && (snake[0][1] == wall[2][1])) || ((snake[0][0] == wall[3][0]) && (snake[0][1] == wall[3][1]))))
    dead = true;


  if (EEPROM.read(34) == 2  //hit the walls in hard level
      && (((snake[0][0] == wall[0][0]) && (snake[0][1] == wall[0][1])) || ((snake[0][0] == wall[1][0]) && (snake[0][1] == wall[1][1]))
          || ((snake[0][0] == wall[2][0]) && (snake[0][1] == wall[2][1])) || ((snake[0][0] == wall[3][0]) && (snake[0][1] == wall[3][1]))
          || ((snake[0][0] == wall[4][0]) && (snake[0][1] == wall[4][1])) || ((snake[0][0] == wall[5][0]) && (snake[0][1] == wall[5][1]))))
    dead = true;


  for (int i = 1; i < snakeLength; i++) {  //when the snake hits itself
    if (snake[i][0] == snake[0][0] && snake[i][1] == snake[0][1]) {
      dead = true;
    }
  }

  if (millis() - lastMoved > moveInterval) {
    // game logic
    updatePositions();
    lastMoved = millis();
  }

  for (int i = 0; i < snakeLength; i++)
    lc.setLed(0, snake[i][0], snake[i][1], true);

  if (dead == true) {
    deadSound();
    congratsScreen(score);  //congrats screen
  }

  if (millis() - lastBlink > blinkInterval) {
    // game logic
    foodBlink();
    lastBlink = millis();
  }

  if (foodSnake[0][0] == snake[0][0] && foodSnake[0][1] == snake[0][1]) {
    eatSound();
    if (EEPROM.read(34) == 0 && EEPROM.read(35) == 0)
      score++;
    else if ( (EEPROM.read(34) == 0 && EEPROM.read(35) == 1)  || (EEPROM.read(34) == 1 && EEPROM.read(35) == 0) )
      score = score + 2;
    else if ((EEPROM.read(34) == 0 && EEPROM.read(35) == 2)  || (EEPROM.read(34) == 1 && EEPROM.read(35) == 1) || (EEPROM.read(34) == 2 && EEPROM.read(35) == 0))
      score = score + 3;
    else if ((EEPROM.read(34) == 1 && EEPROM.read(35) == 2) || (EEPROM.read(34) == 2 && EEPROM.read(35) == 1))
      score = score + 4;
    else if (EEPROM.read(34) == 2 && EEPROM.read(35) == 2)
      score = score + 5;

    snakeLength++;
    if (snakeLength % 4 == 0) {
      if (EEPROM.read(35) == 0)
        moveInterval = moveInterval - speedValue[EEPROM.read(35)];
      else if (EEPROM.read(35) == 1) 
        moveInterval = moveInterval - speedValue[EEPROM.read(35)];
      else if (EEPROM.read(35) == 2)
        moveInterval = moveInterval - speedValue[EEPROM.read(35)];
    }
    snake[snakeLength - 1][0] = snake[snakeLength - 2][0] +  1;
    snake[snakeLength - 1][1] = snake[snakeLength - 2][1];
    scorePrint(score);
    generateFood();
  }
}