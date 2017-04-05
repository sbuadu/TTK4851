void drive(){
  int time = 0; 
  if( Serial.available() >0){       // if data is available to read
    angle = Serial.read();          // read it and store it in 'state'

    if (angle <= 180){
      //right turn 
      time = 5.109266313*10^(-3)*angle^2 + 63.03130035*angle^(1/2) - 182.2983324; 
      turnRight(time); 
      
    }else{
     //left turn 
    time = 6.520934182*10^(-3)*angle^2 + 53.90658398*angle^(1/2) - 124.6841231; 
    turnLeft(time); 
  }
}
