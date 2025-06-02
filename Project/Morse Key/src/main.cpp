#include <Arduino.h>
#include "config.h"
#include "MorseManager.h"
#include "Esp32.h"

void UpdateButtonState();
void PrintInput();

MorseManager morseManager;
Esp32 esp32(BUTTON_PIN, BAUD_RATE);

void setup() {
  esp32.Setup();
}

void loop() {
  esp32.Loop();
  UpdateButtonState();
}

void UpdateButtonState(){
  //This makes sure the corresponding method is only called when state is changed.
  if (esp32.GetButtonState() and !morseManager.IsButtonPressed()){
    morseManager.ButtonPress();
  } else if (!esp32.GetButtonState() and morseManager.IsButtonPressed()){
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