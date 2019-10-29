//SLAVE
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(A1, A0);

char buffer[100];

void setup(){
  BTSerial.begin(9600);
}

void loop(){
  if(BTSerial.available()){
    int no = BTSerial.readBytes(buffer, 99);
    buffer[no] = '\0';
    BTSerial.write(buffer);
  }
}
