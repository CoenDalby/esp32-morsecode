#ifndef ESP32_H
#define ESP32_H

class Esp32
{
public:
    /**
     * @brief Esp32 constructor method.
     */
    Esp32(int buttonPin, int baudRate);
    /**
     * @brief Called when device boots up.
     */
    void Setup();
    /**
     * @brief Called every loop of the main program.
     */
    void Loop();
    /**
     * @brief Gets physical state of morse button.
     * @return bool, true if button is pressed.
     */
    bool GetButtonState();

private:
    bool _buttonDown;   // Current state of physical button; true if pressed.
    int _buttonPin;     // Pin used to take input from button.
    int _baudRate;      // Speed data is transmitted over serial channel.

};

#endif