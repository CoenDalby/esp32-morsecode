#include <Arduino.h>
#include "Esp32.h"

Esp32::Esp32(int buttonPin, int baudRate) :
    _buttonDown{false},
    _buttonPin{buttonPin},
    _baudRate{baudRate}
{}

void Esp32::Setup()
{
    Serial.begin(_baudRate);
    pinMode(_buttonPin, INPUT_PULLUP);
    Serial.println("Awaiting button press.");
}

void Esp32::Loop(){
  if (digitalRead(_buttonPin) == LOW){
    _buttonDown = true;
  } else {
    _buttonDown = false;
  }
}

bool Esp32::GetButtonState()
{
    return _buttonDown;
}