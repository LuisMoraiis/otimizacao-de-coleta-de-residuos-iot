#include <Arduino.h>

const int trigPin_1 = 4;
const int echoPin_1 = 2;
const int trigPin_2 = 18;
const int echoPin_2 = 5;

void defaultHC_SR04(int trigPin, int echoPin, int numSensor){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  long distance = duration * 0.034 / 2;
  Serial.print("Sensor ");
  Serial.print(numSensor);
  Serial.print("  Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

void setup() {
  Serial.begin(9600);

  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(trigPin_2, OUTPUT);
  pinMode(echoPin_2, INPUT);
}

void loop() {

  defaultHC_SR04(trigPin_1, echoPin_1, 1);
  defaultHC_SR04(trigPin_2, echoPin_2, 2);

  delay(1000);

}
