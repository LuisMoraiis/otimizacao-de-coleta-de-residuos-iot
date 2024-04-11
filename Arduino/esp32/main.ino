#include <Arduino.h>

const int trigPin = 4; // Pino do trigger do sensor HC-SR04 (D4 no ESP32)
const int echoPin = 2; // Pino do echo do sensor HC-SR04 (D2 no ESP32)

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial com a velocidade de 115200 bps

  pinMode(trigPin, OUTPUT); // Define o pino do trigger como saída
  pinMode(echoPin, INPUT);  // Define o pino do echo como entrada
}

void loop() {
/*
  // Gera um pulso no pino do trigger do sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Mede o tempo que o echo leva para retornar
  long duration = pulseIn(echoPin, HIGH);

  // Calcula a distância em centímetros
  long distance = duration * 0.034 / 2;

  // Imprime a distância no terminal serial
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Aguarda um segundo antes de fazer a próxima leitura
*/
}
