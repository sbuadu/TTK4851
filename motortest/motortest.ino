/* defining pins for the distance sensors
  Pin1 - top sensor
  Pin2 - bottom sensor
*/
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
int maximumRange1 = 1000; // Maximum range needed
int minimumRange1 = 20; // Minimum range needed

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

void loop() {

  /* The following trigPin/echoPin 1 cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(triggerPin1, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin1, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);

  /* The following trigPin/echoPin 2 cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(triggerPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin2, HIGH);
  delayMicroseconds(10);

  digitalWrite(triggerPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.
  distance1 = duration1 / 58.2;
  distance2 = duration2 / 58.2;


  //checking for obstacles og the edge of the table
  //this is actually the operation of the vehicle. Must add more sentences 
  if (safePassage(distance1, distance2)) {
    Serial.println(distance1);
    Serial.println(distance2);
    goForward(2000);
  }  else {
    stopMotors(2000);
    reverse(2000);
   }
}


bool safePassage(int distance1, int distance2) {
  if (distance1 >= minimumRange1 && distance1 <= maximumRange1 && distance2 <= maximumRange2 && distance2 >= minimumRange2) {

    return true;
  } else {
    return false;
  }
}

//works when the wheels do as they are supposed to
void goForward(int timelaps) {
  digitalWrite(directionLeft, HIGH);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorA, 60);

  digitalWrite(directionRight, LOW);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorB, 70);

  delay(timelaps);
}

//not tested
void turnRight(int timelaps) {

  digitalWrite(directionLeft, HIGH);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorA, 50);


  digitalWrite(directionRight, HIGH);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorA, 90);

  delay(timelaps);
}

//having trouble with the back wheel.. 
void reverse(int timelaps) {
  digitalWrite(directionLeft, LOW);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorA, 60);

  digitalWrite(directionRight, HIGH);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorA, 60);

  delay(timelaps);
}

//works fine
void stopMotors(int timelaps) {
  Serial.println("-1");
  digitalWrite(breakLeft, HIGH);
  digitalWrite(breakRight, HIGH);

  delay(timelaps);
}

