const int buzzerPin = A2;
const int buzzerDuration = 2000;
const int scrollDuration = 100;
bool sound = true;
byte soundsGame;
#define NOTE_FS2 93
#define NOTE_C8 4186
#define NOTE_AS5 932
#define NOTE_DS8 4978
void openSound() {
  if (EEPROM.read(3) == 1) {
    tone(buzzerPin, NOTE_FS2, buzzerDuration);
  } 
}

void scroll() {
  if (EEPROM.read(3) == 1) {
    tone(buzzerPin, NOTE_C8, scrollDuration);
  } 
}

void deadSound() {
  if (EEPROM.read(3) == 1) {
    tone(buzzerPin, NOTE_DS8, scrollDuration);
  } 
}
void eatSound() {
  if (EEPROM.read(3) == 1) {
    tone(buzzerPin, NOTE_AS5, scrollDuration);
  }
}