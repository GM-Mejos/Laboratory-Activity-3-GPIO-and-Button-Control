#include <Arduino.h>

// Pin Definitions for DOIT ESP32 DEVKIT V1
const int buttonPin = 4;   // Pushbutton connected to GPIO 4 (D4)
const int led1Pin   = 18;  // Status LED connected to GPIO 18 (D18)
const int led2Pin   = 19;  // Opposite State LED connected to GPIO 19 (D19)

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);

  // Active-LOW input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    // Button is PRESSED
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
  } else {
    // Button is RELEASED
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
  }

  delay(10);
}
