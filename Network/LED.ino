#include <SoftwareSerial.h>
#define SW 12
#define LED 11
#define bounceTimer 200
u8 keyState = HIGH;
u8 bounceCount = 0;
SoftwareSerial BTSerial(2, 3);
int BTstates=0;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(SW, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  u8 key = digitalRead(SW);
  if(key == HIGH) {
    if(keyState == LOW) {
      if(bounceCount == 0) {
        bounceCount = bounceTimer;
        Serial.println("Push");
        BTSerial.write('1');
        digitalWrite(LED, HIGH);
        delay(100);
        digitalWrite(LED, LOW);
        keyState = key;
      }
      else {
        bounceCount --;
      }
    }
  }
  else{
    if(keyState == HIGH) {
      Serial.println("Pull");
      keyState = key; }
    }

    if(BTSerial.available())
    {
      char str=BTSerial.read();
      if(str=='1')
      {
        BTstates=!BTstates;
        Serial.println(str);
        digitalWrite(LED, BTstates);
      }
  }
}
