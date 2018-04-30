#include <Adafruit_NeoPixel.h>

uint8_t pixels = 40;

Adafruit_NeoPixel neoPixel = Adafruit_NeoPixel(pixels, D2, NEO_GRB + NEO_KHZ800);

char Buffer[3];
uint8_t health, bombStatus, bombBegin, ammoBegin, ammoStatus;
uint16_t bombBlinkLength;
unsigned long bombPreviousLength, ammoBlinkLength, bombTimeLength;
uint8_t hRed, hGreen, hBlue;
uint8_t ledBrightness = 127;

void readSerialData() {
  Buffer[0] = NULL;
  Buffer[0] = Serial.read();

  if (Buffer[0] == 'b') {
    readBombData();
  }
  else if (Buffer[0] == 'h') {
    readHealthData();
  }
  else if (Buffer[0] == 'a') {
    readAmmoData();
  }
}

uint8_t chartoInt() {
  Buffer[0] = NULL; Buffer[1] = NULL; Buffer[2] = NULL;
  Serial.readBytes(Buffer, 3);
  Buffer[0] = (Buffer[0] - '0');
  Buffer[1] = (Buffer[1] - '0');
  Buffer[2] = (Buffer[2] - '0');
  Buffer[0] *= 100;
  Buffer[1] *= 10;
  return Buffer[0] + Buffer[1] + Buffer[2];
}

void readHealthData() {
  health = chartoInt();
  if (health > 50) {
    health = health - 50;
    hRed = 50 - health;
    hGreen = 50 + health;
    hBlue = 0;
  }
  else if (health <= 50) {
    health = 50 - health;
    hRed = 50 + health;
    hGreen = 50 - health;
    hBlue = 0;
  }
}

void driveHealth() {
  driveRGB(hRed, hGreen, hBlue);
}

void readBombData() {
  Buffer[0] = Serial.read();
  if (Buffer[0] == 'p') {
    bombStatus = 1;
    bombBegin = 1;
  }
  else if (Buffer[0] == 'd') {
    bombStatus = 2;
  }
  else if (Buffer[0] == 'e') {
    bombStatus = 3;
  }
  else if (Buffer[0] == 'n') {
    bombStatus = 0;
    bombBlinkLength = 1000;
  }
}

void bombTimer() {
  driveRGB(0, 0, 100);
  if (bombStatus == 1) {
    driveRGB(0, 100, 0);
    for (size_t i = 41; i > 0; i--) {
      if (i == 11) {
        for (size_t j = 11; j > 0; j--) {
          neoPixel.setPixelColor(j-1, 255, 69, 0);
          neoPixel.show();
        }
      }
      if (i == 6) {
        for (size_t k = 6; k > 0; k--) {
          neoPixel.setPixelColor(k-1,240,22,22);
          neoPixel.show();
        }
      }
      neoPixel.setPixelColor(i-1, 0, 0, 0);
      neoPixel.show();
      delay(1000);
    }
  } else if (bombStatus == 3) {
    //driveRGB(100,0,0);
    bombBlink();
  } else if (bombStatus == 2) {
    defuseBlink();
  }
}

void bombBlink() {
  for (size_t i = 0; i < 100; i++) {
    driveRGB(i, 0, 0);
    delay(2);
  }
  for (size_t i = 100; i > 0; i--) {
    driveRGB(i, 0, 0);
    delay(2);
  }
  driveRGB(hRed, hGreen, hBlue);
}

void defuseBlink() {
  for (size_t i = 0; i < 100; i++) {
    driveRGB(0,i,0);
    delay(2);
  }
  for (size_t i = 100; i > 0; i--) {
    driveRGB(0,i,0);
    delay(2);
  }
}

void driveBomb() {
  if (bombBegin == 1) {
    bombBlink();
    bombPreviousLength = millis();
    bombBegin = 0;
  }
  else if (bombStatus == 1) {
    if ((millis() - bombPreviousLength) > bombBlinkLength) {
      bombBlink();
      bombBlinkLength -= 25;
      bombPreviousLength = millis();
    }
  }
  else if (bombStatus == 2) {
    bombPreviousLength = millis();
    while ((millis() - bombPreviousLength) < 5000) {
      driveRGB(0, 100, 0);
    }
    bombStatus = 0;
  }
  else if (bombStatus == 3) {
    bombPreviousLength = millis();
    while ((millis() - bombPreviousLength) < 5000) {
      driveRGB(100, 0, 0);
    }
    bombStatus = 0;
  }
}

void readAmmoData() {
  Buffer[0] = Serial.read();
  if ((Buffer[0] - '0') == 0) {
    ammoStatus = 0;
  }
  else if ((Buffer[0] - '0') == 1) {
    ammoStatus = 1;
  }
}

void ammoBlink() {
  for (size_t i = 0; i < 100; i++) {
    driveRGB(0, 0, i);
    delay(1);
  }
  for (size_t i = 100; i > 0; i--) {
    driveRGB(0, 0, i);
    delay(1);
  }
  driveRGB(hRed, hGreen, hBlue);
}

void driveAmmo() {
  if (ammoStatus == 1) {
    if (ammoBegin == 1) {
      ammoBlink();
      ammoBlinkLength = millis();
      ammoBegin = 0;
    }
    if ((millis() - ammoBlinkLength) > 1000) {
      ammoBlink();
      ammoBlinkLength = millis();
    }
  }
  if (ammoStatus == 0) {
    ammoBegin = 1;
  }
}

void driveRGB(uint8_t red, uint8_t green, uint8_t blue) {
  red = map(red, 0, 100, 0, ledBrightness);
  green = map(green, 0, 100, 0, ledBrightness);
  blue = map(blue, 0, 100, 0, ledBrightness);
  for (size_t i = 0; i < pixels; i++) {
    neoPixel.setPixelColor(i, red, green, blue);
  }
  neoPixel.show();
}

void setup() {
  neoPixel.begin();
  neoPixel.show();
  Serial.begin(115200);
  Serial.setTimeout(10);

}

void loop() {
  readSerialData();
  //driveHealth();
  //driveBomb();
  bombTimer();
  //driveAmmo();


}
