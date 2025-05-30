#include <Arduino.h>
#include "config.h"
#include "MorseManager.h"

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println("Awaiting button press.");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW){
    Serial.println("Doink!");
    delay(1000);
  }
}
