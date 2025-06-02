#include <Arduino.h>
#include "config.h"
#include "MorseManager.h"

void PrintInput();

MorseManager morseManager;
bool buttonDown;

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println("Awaiting button press.");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW){
    buttonDown = true;
  } else {
    buttonDown = false;
  }

  //This makes sure the corresponding method is only called when state is changed.
  if (buttonDown and !morseManager.IsButtonPressed()){
    morseManager.ButtonPress();
  } else if (!buttonDown and morseManager.IsButtonPressed()){
    morseManager.ButtonRelease();
    PrintInput();
    delay(50); //Stupid way to avoid button bounce. Change.
  }
}

void PrintInput(){
  MorseCode symbol = morseManager.getLastInput();
  switch (symbol){
    case MorseCode::DOT: 
      Serial.println("DOT");
      break;
    case MorseCode::DASH: 
      Serial.println("DASH");
      break;
    case MorseCode::NONE: 
      Serial.println("Uh oh!");
      break;
  }
}