const int pinX = A0;
const int pinY = A1;
const int pinSw = 2;

int xValue = 0;
int yValue = 0;

const int minThreshold = 200;//100;
const int maxThreshold = 600;//900;

byte reading = HIGH;
bool startGame = false;
bool press = false;

bool joystickUp() {
  xValue = analogRead(pinX);
  if (xValue > maxThreshold) {
    return true;
  }
  else
    return false;
}

bool joystickDown() {
  xValue = analogRead(pinX);
  if (xValue < minThreshold ) {
    return true;
  }
  else
    return false;
}

bool joystickLeft() {
  yValue = analogRead(pinY);
  if (yValue < minThreshold ) {
    return true;
  }
  else 
    return false;
}

bool joystickRight() {
  yValue = analogRead(pinY);
  if (yValue > maxThreshold) {
    return true;
  }
  else
    return false;
}

bool joystickPress() {
  reading = digitalRead(pinSw);
  if (reading == LOW) {
    return true;
  } 
  else 
    return false;
}
