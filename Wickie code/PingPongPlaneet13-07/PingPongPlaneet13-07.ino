//----------------------------------------------------------------

#include "Freenove_WS2812B_RGBLED_Controller.h"
#define I2C_ADDRESS  0x20
#define LEDS_COUNT   10

//Freenove_WS2812B_Controller strip(&Serial1, LEDS_COUNT, TYPE_GRB, 115200UL);
Freenove_WS2812B_Controller strip(I2C_ADDRESS, LEDS_COUNT, TYPE_GRB);

//SoftwareSerial esp8266(10,11);

int all_laser[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43}; //orange
//define lasers and group them
int laserpin_low[] = {22, 25, 28, 31, 34, 37, 40, 43}; //orange

int laserpin_mid[] = {23, 26, 29, 32, 35, 38, 41, 44}; //green

int laserpin_high[] = {24, 27, 30, 33, 36, 39, 42, 45}; //blue

int laserpin_1[] = {22, 23, 24};
int laserpin_2[] = {25, 26, 27};
int laserpin_3[] = {28, 29, 30};
int laserpin_4[] = {31, 32, 33};
int laserpin_5[] = {34, 35, 36};
int laserpin_6[] = {37, 38, 39};
int laserpin_7[] = {40, 41, 42};
int laserpin_8[] = {43, 44, 45};

const int smokePin = 13;

void setup() {
  Serial.begin(115200);
   Serial.println("Initializing planet");

     pinMode(51, OUTPUT);
 // esp8266.begin(9600);
  pinMode(laserpin_low[0], OUTPUT);
  pinMode(laserpin_low[1], OUTPUT);
  pinMode(laserpin_low[2], OUTPUT);
  pinMode(laserpin_low[3], OUTPUT);
  pinMode(laserpin_low[4], OUTPUT);
  pinMode(laserpin_low[5], OUTPUT);
  pinMode(laserpin_low[6], OUTPUT);
  pinMode(laserpin_low[7], OUTPUT);

  pinMode(laserpin_mid[0], OUTPUT);
  pinMode(laserpin_mid[1], OUTPUT);
  pinMode(laserpin_mid[2], OUTPUT);
  pinMode(laserpin_mid[3], OUTPUT);
  pinMode(laserpin_mid[4], OUTPUT);
  pinMode(laserpin_mid[5], OUTPUT);
  pinMode(laserpin_mid[6], OUTPUT);
  pinMode(laserpin_mid[7], OUTPUT);


  pinMode(laserpin_high[0], OUTPUT);
  pinMode(laserpin_high[1], OUTPUT);
  pinMode(laserpin_high[2], OUTPUT);
  pinMode(laserpin_high[3], OUTPUT);
  pinMode(laserpin_high[4], OUTPUT);
  pinMode(laserpin_high[5], OUTPUT);
  pinMode(laserpin_high[6], OUTPUT);
  pinMode(laserpin_high[7], OUTPUT);

 // while (!strip.begin());
 //while (esp8266.begin())
 Serial.println("poepenineenouweschoen");
}
String readstring;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    int i = Serial.read();
    Serial.print(" I recieved:");
    Serial.println(i);
  }
 while(Serial.available())
 { Serial.println("poepenineenouweschoen");

   char inChar = (char)Serial.read();
    if (inChar == '1') { //Lights On
      Serial.println("Jippiiiieeee");
       digitalWrite(51, HIGH);
    //make here a loop to all lights on including lasers
    }
    else if (inChar == '0') { // Lights Off
    //make it loop to all lights off
    Serial.println("KKHOOERUUUUU");
     digitalWrite(51, LOW);
    }
    if (inChar == '3') {   //Smoke On
    //all smoke on
    }
    else if (inChar == '2') {  //Smoke Off
    //smoke off
    }
 }
 //Serial.println("klaarmetpoepenineenouweschoen");

}

void lasermode_1() {
  //loop through all lasers
  for (int i = 22; i < 43; i++) {
    digitalWrite(i, HIGH);
    delay(1000); //1 sec
    digitalWrite(i, LOW);
  }
}
void lasermode_2(float delayTime) {
  //loop through all sets of lasers
  digitalWrite(22, HIGH);
  digitalWrite(23, HIGH);
  digitalWrite(24, HIGH);
  delay(delayTime);
  digitalWrite(22, LOW);
  digitalWrite(23, LOW);
  digitalWrite(24, LOW);
  delay(delayTime);
  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  delay(delayTime);
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  delay(delayTime);
  digitalWrite(28, HIGH);
  digitalWrite(29, HIGH);
  digitalWrite(30, HIGH);
  delay(delayTime);
  digitalWrite(28, LOW);
  digitalWrite(29, LOW);
  digitalWrite(30, LOW);
  delay(delayTime);
  digitalWrite(31, HIGH);
  digitalWrite(32, HIGH);
  digitalWrite(33, HIGH);
  delay(delayTime);
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
  delay(delayTime);
  digitalWrite(34, HIGH);
  digitalWrite(35, HIGH);
  digitalWrite(36, HIGH);
  delay(delayTime);
  digitalWrite(34, LOW);
  digitalWrite(35, LOW);
  digitalWrite(36, LOW);
  delay(delayTime);
  digitalWrite(37, HIGH);
  digitalWrite(38, HIGH);
  digitalWrite(39, HIGH);
  delay(delayTime);
  digitalWrite(37, LOW);
  digitalWrite(38, LOW);
  digitalWrite(39, LOW);
  delay(delayTime);
  digitalWrite(40, HIGH);
  digitalWrite(41, HIGH);
  digitalWrite(42, HIGH);
  delay(delayTime);
  digitalWrite(40, LOW);
  digitalWrite(41, LOW);
  digitalWrite(42, LOW);
  delay(delayTime);
  digitalWrite(43, HIGH);
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  delay(delayTime);
  digitalWrite(43, LOW);
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  delay(delayTime);
}
void lasermode_3(float delayTime) {
  //laser random
  digitalWrite(random(22, 43), HIGH);
  delay(delayTime);
  for (int i = 22; i < 43; i++) {
    digitalWrite(i, LOW);
  }
}
void lasermode_4() {
  //all lasers off
  for (int i = 22; i < 43; i++) {
    digitalWrite(i, LOW);
  }
}

float ledWalk;
float ledWalkSpeed = 1;
void Walking() {
  ledWalk += ledWalkSpeed;
  if (ledWalk > LEDS_COUNT) {
    ledWalkSpeed = -ledWalkSpeed;
  }
  if (ledWalk < 1) {
    ledWalkSpeed = -ledWalkSpeed;
  }

  strip.setLedColorData(ledWalk, 255, 0, 0);
  strip.show();
  delay(100);
  strip.setLedColorData(ledWalk, 0, 255, 0);
  strip.show();
  delay(100);
}

float strobeColor;
float strobeColorSpeed = 1;
void StrobeRainbow() {
  strobeColor += strobeColorSpeed;
  if (strobeColor > 255) {
    strobeColorSpeed = -strobeColorSpeed;
  }
  if (strobeColor < 0) {
    strobeColorSpeed = -strobeColorSpeed;
  }

  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColorData(i, strip.Wheel(strobeColor));
  }
  strip.show();
  delay(100);
  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColor(i, 0, 0, 0);
  }
  strip.show();
  delay(100);
}

void StrobeRainbowLoop() {
  for (int j = 0; j < 255; j += 2) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel((i * 8 / LEDS_COUNT + j) & 255));
    }
    strip.show();
  }
  delay(100);
  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColor(i, 0, 0, 0);
  }
  strip.show();
  delay(100);
}


float color;
float colorSpeed = 1;
void campFire() {
  color += colorSpeed;

  if (color >= 30) {
    colorSpeed = -colorSpeed;
  }
  if (color <= 0) {
    colorSpeed = -colorSpeed;
  }

  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColorData(i, strip.Wheel(color));
  }
  strip.show();
  delay(22);
}

void bluePurpleLoop() {
  for (int j = 160; j < 220; j ++) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel(j));
    }
    strip.show();
    delay(22);
  }
}

void crazyMode() {
  for (int i = 0; i < LEDS_COUNT; i += 4) {
    strip.setLedColorData(i, random(0, 255), random(0, 255), random(0, 255));
  }
  strip.show();
  for (int i = 0; i < LEDS_COUNT; i += 3) {
    strip.setLedColorData(i, 0, random(0, 255), random(0, 255));
  }
  strip.show();
  for (int i = 0; i < LEDS_COUNT; i += 2) {
    strip.setLedColorData(i, 0, 0, random(0, 255));
  }
  strip.show();
  for (int i = 0; i < LEDS_COUNT; i ++) {
    strip.setLedColorData(i, random(0, 255), 0, 0);
  }

  strip.show();
  delay(44);
}

void randomColorFlickering() {
  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColorData(i, random(0, 255), random(0, 255), random(0, 255));
  }
  strip.show();
  delay(200);
}

void blueRed () {
  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColorData(i, 255, 0, 0);
  }
  delay(1000);
  strip.show();
  for (int i = 0; i < LEDS_COUNT; i++) {
    strip.setLedColorData(i, 0, 0, 255);
  }
  delay(1000);
  strip.show();
  delay(20);
}

void rainbowAllLeds() {
  for (int j = 0; j < 255; j += 2) {
    for (int i = 0; i < LEDS_COUNT; i++) {
      strip.setLedColorData(i, strip.Wheel((i * 8 / LEDS_COUNT + j) & 255));
    }
    strip.show();
    delay(22);
  }
}

void smoke() {
  digitalWrite(smokePin, HIGH);
  delay(9000);
  digitalWrite(smokePin, LOW);
  delay(900000);
}
