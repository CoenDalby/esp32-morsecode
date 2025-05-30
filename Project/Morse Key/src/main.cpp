#include <Arduino.h>
#include <config.h>

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.println("Awaiting button press.");
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}