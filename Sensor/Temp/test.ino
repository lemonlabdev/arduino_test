#include <DHT11.h>

//Signal 이 연결된 아두이노의 핀번호
int pin=7;       
DHT11 dht11(pin);    

    
void setup()
{
   Serial.begin(9600); //통신속도 설정
}

 
void loop()
{
  Serial.println("loop started");
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(10); //1초마다 측정
  Serial.println("test");
}