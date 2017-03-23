
#include <dht.h>

dht DHT;

#define DHT11_PIN 2

int soilPin = 7;
int soilValue = 0;
int soilpre = 0;
int sensorPin = A5;
int lightValue = 0;
int lightpre = 0;
float temppre = 0;
float humpre = 0;
float temp = 0;
float hum = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  soilValue = analogRead(soilPin);
  int chk = DHT.read11(DHT11_PIN);
  lightValue = analogRead(sensorPin);
  soilValue = int(0.7*soilValue + 0.3*soilpre);//liukuvat keskiarvot
  soilpre = soilValue;
  hum = DHT.humidity;
  hum = 0.7*hum + 0.3*humpre;
  humpre = hum;
  temp = DHT.temperature;
  temp = 0.7*temp + 0.3*temppre;
  temppre = temp; 
  lightValue = int(0.7*lightValue + 0.3*lightpre);
  lightpre = lightValue;
  Serial.print(DHT.humidity, 1);
  Serial.print("\t");
  Serial.print(DHT.temperature, 1);
  Serial.print("\t");
  Serial.print(soilValue);
  Serial.print("\t");
  Serial.println(lightValue, DEC);
  delay(200);
}
