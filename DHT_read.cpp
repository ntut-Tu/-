#include "DHT.h"

#define dhtPin 8      // 讀取DHT11 Data
#define dhtType DHT11 // 選用DHT11

DHT dht(dhtPin, dhtType); // Initialize DHT sensor

void setup() {
  Serial.begin(9600); // 設定鮑率9600
  dht.begin(); // 啟動DHT

  float h = dht.readHumidity(); // 讀取濕度
  float t = dht.readTemperature(); // 讀取攝氏溫度
  float f = dht.readTemperature(true); // 讀取華氏溫度

  Serial.print(h);
}

void loop() {
  // 空的loop函數，讓程式不會重複執行
}
