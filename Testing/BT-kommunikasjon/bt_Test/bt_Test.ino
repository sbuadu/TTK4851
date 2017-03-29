
#include <SoftwareSerial.h>


int state;  


void setup() {
  Serial.begin(9600);  
}

void loop() {
 if( Serial.available() >0){       // if data is available to read
 state = Serial.read();// read it and store it in 'state'

 Serial.println(state);

  
  }
}
  


