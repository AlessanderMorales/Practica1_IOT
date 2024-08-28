#include "LED.h"

LED::LED(int pinNumber) {
  pin = pinNumber;
  pinMode(pin, OUTPUT);
}

void LED::turnOn() {
  digitalWrite(pin, HIGH);
}

void LED::turnOff() {
  digitalWrite(pin, LOW);
}
