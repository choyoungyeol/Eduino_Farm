#include "DHT.h"
#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);            // DHT 클래스 함수 선언

void setup() {
  Serial.begin(9600);               //PC와 아두이노간 시리얼 통신 속도를 9600bps로 설정
  dht.begin();                      //온습도 센서와 아두이노간의 통신 시작.
}
void loop() {
  int hum = dht.readHumidity();    // 습도 값을 hum 변수에 저장
  int temp = dht.readTemperature();// 온도 값을 temp 변수에 저장

  Serial.print("temp : "); 
  Serial.print(temp); 
  Serial.print(" °C, "); 
  Serial.print("hum : "); 
  Serial.print(hum); 
  Serial.println(" %");
  delay(1000);
}
