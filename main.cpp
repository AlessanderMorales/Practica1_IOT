#include <Wire.h>
#include "UltrasonicSensor.h"
#include "LED.h"

// Definir los pines
int trigPin = 12;
int echoPin = 13;

UltrasonicSensor sensor(trigPin, echoPin);
LED ledGreen(14);
LED ledYellow(27);
LED ledRed(26);
LED ledBlue(25);

unsigned long previousMillis = 0;
const long interval = 1000;  // Intervalo de 1 segundo

void setup() {
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    sensor.trigger();
    float distance = sensor.getDistance(); // Cambiado a float

    Serial.print("Distance: ");
    Serial.print(distance, 2); // Muestra con 2 decimales
    Serial.println(" cm");

    // Controlar los LEDs según la distancia
    if (distance <= 10) {
      ledRed.turnOn();
      ledYellow.turnOff();
      ledGreen.turnOff();
      ledBlue.turnOff();
    } else if (distance <= 20) {
      ledRed.turnOff();
      ledYellow.turnOn();
      ledGreen.turnOff();
      ledBlue.turnOff();
    } else if (distance <= 30) {
      ledRed.turnOff();
      ledYellow.turnOff();
      ledGreen.turnOn();
      ledBlue.turnOff();
    } else if (distance <= 40) {
      ledRed.turnOff();
      ledYellow.turnOff();
      ledGreen.turnOff();
      ledBlue.turnOn();
    } else {
      ledRed.turnOff();
      ledYellow.turnOff();
      ledGreen.turnOff();
      ledBlue.turnOff();
    }
  }
}
