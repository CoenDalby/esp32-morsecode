#ifndef MORSE_MANAGER_H
#define MORSE_MANAGER_H

enum class MorseCode {
    NONE,
    DOT,
    DASH
};

class MorseManager
{
public:
    /**
     * @brief MorseManager constructor method.
     */
    MorseManager();

    /**
     * @brief Gets the status of the button.
     * @return Bool, true if button is pressed.
     */
    bool IsButtonPressed();

    /**
     * @brief Sets _buttonPressed to True and records time pressed.
     */
    void ButtonPress();

    /**
     * @brief Sets _buttonPressed to False and calculates input symbol.
     */
    void ButtonRelease();

    /**
     * @brief Gets the last input morse symbol.
     * @return enum MorseCode, can be NONE, DOT, or DASH.
     */
    MorseCode getLastInput(); 

private:
    bool _buttonPressed;            // Current state of button; true if pressed.
    unsigned long _buttonDownTime;  // Time button was last pressed down.
    unsigned long _buttonUpTime;    // Time button was last released.
    MorseCode _lastInput;           // The last input morse symbol.
    
};

#endif