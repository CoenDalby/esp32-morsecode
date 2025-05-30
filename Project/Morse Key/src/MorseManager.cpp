#include "MorseManager.h"
#include "config.h"
#include <Arduino.h>

MorseManager::MorseManager(){
    _buttonPressed = false;
    _buttonDownTime = 0;
    _buttonUpTime = 0;
    _lastInput = NONE;
}

bool MorseManager::ButtonPressed(){
    return _buttonPressed;
}

void MorseManager::ButtonPress()
{
    _buttonPressed = true;

    _buttonDownTime = millis();
    Serial.println(String("Button pressed at: ") + _buttonDownTime);
}

void MorseManager::ButtonRelease()
{
    _buttonPressed = false;

    _buttonUpTime = millis();
    Serial.println(String("Button released at: ") + _buttonUpTime);

    unsigned long pressDuration = _buttonUpTime - _buttonDownTime;
    Serial.println(String("Press duration: ") + pressDuration);
    
    if (pressDuration > DOT_LIMIT){
        _lastInput = DASH;
    }else{
        _lastInput = DOT;
    }
}

MorseCode MorseManager::getLastInput()
{
    return _lastInput;
}