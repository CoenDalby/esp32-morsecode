#ifndef MORSE_CONFIG_H
#define MORSE_CONFIG_H

// ESP32 Settings
#define BUTTON_PIN      4       // Pin taking button signal
#define BAUD_RATE       115200

// Morse Settings
#define DOT_LIMIT       500     // Maximum time you can press button for a dot
#define IDLE_TIMEOUT    3000    // Idle time before letter is submitted
#define BUFFER_SIZE     5 

#endif