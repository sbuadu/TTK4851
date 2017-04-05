int checkObstacle1(){
   /* The following trigPin/echoPin 1 cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(triggerPin1, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin1, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  //Calculate the distance (in cm) based on the speed of sound.
  distance1 = (int) duration1 / 58.2;
return distance1;
}

int checkObstacle2(){
  /* The following trigPin/echoPin 2 cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(triggerPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin2, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.
  distance2 = (int) duration2 / 58.2;
  
return distance2;
}
