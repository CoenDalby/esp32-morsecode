#ifndef MORSE_CONFIG_H
#define MORSE_CONFIG_H
#include <cstdint>

// ESP32 Settings
constexpr std::uint8_t BUTTON_PIN =     4;       // Pin taking button signal
constexpr unsigned long BAUD_RATE =     115200;

// Morse Settings
constexpr unsigned long DOT_LIMIT =     500;     // Maximum time you can press button for a dot
constexpr unsigned long IDLE_TIMEOUT =  3000;    // Idle time before letter is submitted

#endif