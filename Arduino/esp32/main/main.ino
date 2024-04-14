#include <Arduino.h>
#include <WiFi.h>

const int trigPin_1 = 4;
const int echoPin_1 = 2;
const int trigPin_2 = 18;
const int echoPin_2 = 5;
const int trigPin_3 = 23;
const int echoPin_3 = 22;

const char ssid[] = "rede";
const char password[] = "senha";

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

void connectionWifi(const char *ssid, const char *password){
  WiFi.mode(WIFI_STA);
  Serial.println();
  Serial.println("Conectando a rede Wi-Fi...");
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Tentando conectar a rede Wi-Fi...");
  }
  Serial.println("Conectado a rede Wi-Fi com sucesso!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  connectionWifi(ssid, password);

  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(trigPin_2, OUTPUT);
  pinMode(echoPin_2, INPUT);
  pinMode(trigPin_3, OUTPUT);
  pinMode(echoPin_3, INPUT);
}

void loop() {

  defaultHC_SR04(trigPin_1, echoPin_1, 1);
  defaultHC_SR04(trigPin_2, echoPin_2, 2);
  defaultHC_SR04(trigPin_3, echoPin_3, 3);
  Serial.println();

  delay(1000);

}
