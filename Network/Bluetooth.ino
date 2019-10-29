#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(2, 3);
void setup()
{
  Serial.begin(9600);
  BT_Serial.begin(9600);
}
void loop()
{
  if(BT_Serial.available())
  Serial.write(BT_Serial.read());

  if(Serial.available())
  BT_Serial.write(Serial.read());
}
