#include <Arduino.h>

byte k1 = 12;
byte k2 = 5;
byte k3 = 14;
byte k4 = 13;
byte GND = 16;
byte buzz = 2;

int status[4] = { 0, 0, 0, 0 };
int key[4] = { 0, 0, 0, 0 };



void setup() {
  // put your setup code here, to run once:
  pinMode(k1, INPUT_PULLUP);
  pinMode(k2, INPUT_PULLUP);
  pinMode(k3, INPUT_PULLUP);
  pinMode(k4, INPUT_PULLUP);
  pinMode(GND, OUTPUT);
  pinMode(buzz, OUTPUT);

  Serial.begin(115200);
  digitalWrite(GND, LOW);
  digitalWrite(buzz, LOW);


}


void keybd() {
  key[0] = 0;
  key[1] = 0;
  key[2] = 0;
  key[3] = 0;

  for (byte i = 0; i < 50; i++) {
    key[0] = key[0] + digitalRead(k1);
    key[1] = key[1] + digitalRead(k2);
    key[2] = key[2] + digitalRead(k3);
    key[3] = key[3] + digitalRead(k4);
  }
  if (key[0] < 1 && status[0] == 0) {
    Serial.print("A1");
    status[0] = 1;
  }
  if (key[1] < 1 && status[1] == 0) {
    Serial.print("B1");
    status[1] = 1;
  }
  if (key[2] < 1 && status[2] == 0) {
    Serial.print("C1");
    status[2] = 1;
  }
  if (key[3] < 1 && status[3] == 0) {
    Serial.print("D1");
    status[3] = 1;
  }
  if (key[0] > 48 && status[0] == 1) {
    Serial.print("A0");
    status[0] = 0;
  }
  if (key[1] > 48 && status[1] == 1) {
    Serial.print("B0");
    status[1] = 0;
  }
  if (key[2] > 48 && status[2] == 1) {
    Serial.print("C0");
    status[2] = 0;
  }
  if (key[3] > 48 && status[3] == 1) {
    Serial.print("D0");
    status[3] = 0;
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  keybd();
}
