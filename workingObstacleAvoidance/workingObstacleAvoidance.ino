//this file should always be working.. Test in another file and add the functionality here 

int echoPin1 = 10;
int triggerPin1 = 7;
int echoPin2 = 5;
int triggerPin2 = 4;

//defining pins for the motors
int directionLeft = 12;
int breakLeft = 9;
int speedMotorA = 3;

int directionRight = 13;
int breakRight = 8;
int speedMotorB = 11;


//defining min/max range
int maximumRange1 = 10000; // Maximum range needed
int minimumRange1 = 15; // Minimum range needed

int maximumRange2 = 10; // Maximum range needed
int minimumRange2 = 0; // Minimum range needed

long duration1, duration2, distance1, distance2; // Duration is used to calculate distance



void setup() {
    Serial.begin (9600);
  
  //Setup Ultrasonic Sensor upper
  pinMode(echoPin1, INPUT); //Initiates Echo Pin 1
  pinMode(triggerPin1, OUTPUT); //Initiates Trigger Pin 1
  
  //Setup Ultrasonic Sensor lower
  pinMode(echoPin2, INPUT); //Initiates Echo Pin 2
  pinMode(triggerPin2, OUTPUT); //Initiates Trigger Pin 2

  //Setup Channel A
  pinMode(directionLeft, OUTPUT); //Initiates Motor Channel A pin
  pinMode(breakLeft, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(directionRight, OUTPUT); //Initiates Motor Channel B pin
  pinMode(breakRight, OUTPUT);  //Initiates Brake Channel B pin

}



/* 
this works fine when upper sensor does as it should.. 
TO DO - implement functionality for lower sensor and reverse */
void loop(){

  digitalWrite(triggerPin1, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin1, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);

  digitalWrite(triggerPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin2, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);

  //Calculate the distance (in cm) based on the speed of sound. 
  distance1 = duration1 / 58.2;
  distance2 = duration2 / 58.2;
  
  if(safePassage(distance1, distance2)){
    goForward(); 
  }else{
    stopMotors(); 

    maneuver(distance1, distance2); 
  }
  

}

bool safePassage(int distance1, int distance2) {
  if (distance1 >= minimumRange1 && distance1 <= maximumRange1 ) {

    return true;
  } else {
    return false;
  }
}

void maneuver(int distance1, int distance2){
  if(distance1<=minimumRange1){
   turnRight(); 
  }
}


void goForward() {
  digitalWrite(directionLeft, HIGH);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorA, 60);

  digitalWrite(directionRight, LOW);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorB, 70);

  delay(200); 
}

void stopMotors() {
  digitalWrite(breakLeft, HIGH);
  digitalWrite(breakRight, HIGH);
 
}

void turnRight() {

  digitalWrite(breakLeft, HIGH);

  digitalWrite(directionRight, HIGH);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorA, 70);

    delay(500);
   
}
void turnLeft() {
  digitalWrite(breakRight, HIGH);
  digitalWrite(directionLeft, LOW);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorB, 70);

    delay(500);
   
}

