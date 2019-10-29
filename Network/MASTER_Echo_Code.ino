//MASTER
char buffer[100];

void setup(){
  Serial.begin(9600);
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    int no = Serial.readBytes(buffer, 99);
    buffer[no]='\0';
    Serial.print("Slave Echo : ");
    Serial.println(buffer);
  }

  if(Serial.available()){
    int no = Serial.readBytes(buffer, 99);
    buffer[no]='\0';
    Serial.println(buffer);
    Serial.write(buffer);
  }
}
