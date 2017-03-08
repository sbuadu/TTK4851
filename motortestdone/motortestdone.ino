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


  turnRight(830);
  stopMotors(800);
  turnLeft(810);
  stopMotors(3000);

}



//works fine
void goForward(int timelaps) {
  digitalWrite(directionLeft, HIGH);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorA, 100);

  digitalWrite(directionRight, LOW);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorB, 100);

  delay(timelaps);
}

//works fine
void stopMotors(int timelaps) {
  Serial.println("-1");
  digitalWrite(breakLeft, HIGH);
  digitalWrite(breakRight, HIGH);

  delay(timelaps);
}

//works fine
//timelaps 800 ~90 degree turn
void turnRight(int timelaps) {
  digitalWrite(directionLeft, HIGH);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorB, 100);

  digitalWrite(directionRight, HIGH);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorA, 100);

    delay(timelaps);
   
}

//works fine
//timelaps 800 ~90 degree turn
void turnLeft(int timelaps) {
    digitalWrite(directionRight, LOW);
   digitalWrite(breakRight, LOW);
   analogWrite(speedMotorA, 100);

  digitalWrite(directionLeft, LOW);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorB, 100);

    delay(timelaps);
   
}


//must wait for the new wheel before this can be tested. 
void reverse(int timelaps) {
  digitalWrite(directionLeft, LOW);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorA, 60);

  digitalWrite(directionRight, HIGH);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorA, 60);

  delay(timelaps);
}

