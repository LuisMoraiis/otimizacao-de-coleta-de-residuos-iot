#include <Arduino.h>
#include <WiFi.h>
#include <SPIFFS.h>
#include <FS.h>

bool trash[3] = {false, false, false};
const int trigPin_1 = 4;
const int echoPin_1 = 2;
const int trigPin_2 = 18;
const int echoPin_2 = 5;
const int trigPin_3 = 23;
const int echoPin_3 = 22;

const char ssid[] = "rede";
const char password[] = "senha";

void dataEncapsulation(long distance, int sensorId){
  if(!SPIFFS.begin(true)){
    Serial.println("Erro ao montar sistema de arquivos");
  }
  File arquivo = SPIFFS.open("/arq.csv", FILE_WRITE);
  if(!arquivo){
    Serial.println("Erro ao criar arquivo CSV");
  }
  arquivo.println("Sensor 1, Sensor 2, Sensor 3");

  if(distance <= 10){
    if(sensorId == 1){
      arquivo.print(distance);
    }
    if(sensorid == 2){
      arquivo.print(",");
      arquivo.print(distance);
    }
    if(sensorId == 3){
      arquivo.print(",");
      arquivo.print(",");
      arquivo.print(distance);
    }
  }

  arquivo.close();
}

void checkTrash(long distance, int numSensor){
  if(distance <= 10){
    trash[numSensor - 1] = false;
  }else{
    trash[numSensor - 1] = true;
  }
}

long defaultHC_SR04(int trigPin, int echoPin, int numSensor){
  void checkTrash(long distance, int numSensor);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  long distance = duration * 0.034 / 2;
  
  checkTrash(distance, numSensor);
  
  Serial.print("Sensor ");
  Serial.print(numSensor);
  Serial.print("  Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  return distance;
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

  dataEncapsulation(defaultHC_SR04(trigPin_1, echoPin_1, 1), 1);
  dataEncapsulation(defaultHC_SR04(trigPin_2, echoPin_2, 2), 2);
  dataEncapsulation(defaultHC_SR04(trigPin_3, echoPin_3, 3), 3);

  Serial.println();

  delay(1000);
}
