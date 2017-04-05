void drive(){
  int time = 0; 
  if( Serial.available() >0){       // if data is available to read
    symbol = Serial.read();          // read it and store it in 'state'
    angle = (symbol-48)*5
    if (angle <= 36){
      //right turn 
      time = 5.109266313*10^(-3)*angle*^2 + 63.03130035*angle^(1/2) - 182.2983324; 
      turnRight(time); 
      goForward()
      
    }else if (angle == 47){
      stopMotors()
    }else{
      //left turn 
      time = 6.520934182*10^(-3)*angle^2 + 53.90658398*angle^(1/2) - 124.6841231; 
      turnLeft(time); 
      goForward()
  }
}
