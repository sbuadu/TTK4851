void drive(){
if( Serial.available() >0){       // if data is available to read
    state = Serial.read();          // read it and store it in 'state'
    flag = 0; 
  }
  
  if( state == '0' ){               // State 0 turns motor off
    stopMotors();
    if( flag == 0){
      Serial.println("Motor:off");
      flag = 1;
      } 
    } 
  else if(state >= '1' && state <= '2') {         //State 1 will turn right for 
    temp = state*25;  
    turnRight(temp);                        
    if(flag == 0){
          Serial.println("Motor: right");
          flag=1;
        }
    state = '0';
    }
  else if(state >= '3' && state <= '4'){         //State 2 will turn left
   temp = state*20;
   turnLeft(temp);
    if(flag == 0){
          Serial.println("Motor: left");
          flag=1;
        }
    state = '0';
    Serial.println(state);
    }
  else if(state >= '4' && state <= '7'){
    temp = state*20;
    goForward(temp);
      if(flag == 0){
          Serial.println("Motor: forward");
          Serial.println(state);
          flag=1;
        }
    state = '0';
    Serial.println(state);
      }
    else if(state >= '8' && state <= '9'){
    temp = state*17;
    reverse(temp);
      if(flag == 0){
          Serial.println("Motor: Reverse");
          Serial.println(state);
          flag=1;
        }
    state = '0';
    Serial.println(state);
      }

}
