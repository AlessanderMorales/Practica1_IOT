#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trig, int echo) {
  trigPin = trig;
  echoPin = echo;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void UltrasonicSensor::trigger() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Asegura que el pin esté bajo por un breve momento
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Pulso de 10 microsegundos
  digitalWrite(trigPin, LOW);
}

float UltrasonicSensor::getDistance() {
  duration = pulseIn(echoPin, HIGH); // Lee el tiempo de duración del pulso
  float distance = duration / 58.2; // Calcula la distancia en cm
  return distance;
}
