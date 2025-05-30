#ifndef MORSE_MANAGER_H
#define MORSE_MANAGER_H

enum MorseCode {
    NONE,
    DOT,
    DASH
};

class MorseManager
{
public:
    MorseManager();
    bool ButtonPressed();
    void ButtonPress();
    void ButtonRelease();
    MorseCode getLastInput(); 

private:
    bool _buttonPressed;
    unsigned long _buttonDownTime;
    unsigned long _buttonUpTime;
    MorseCode _lastInput;
    
};

#endif