
int speedMotorB = 11;
int speedMotorA = 3; 

int echoPin1 = 10;
int triggerPin1 = 7;
int echoPin2 = 5;
int triggerPin2 = 4;

int maximumRange1 = 20; // Maximum range needed
int minimumRange1 = 0; // Minimum range needed

int maximumRange2 = 10; // Maximum range needed
int minimumRange2 = 0; // Minimum range needed

long duration, distance; // Duration used to calculate distance

void setup() {
  Serial.begin (9600);
  //Setup Ultrasonic Sensor upper
  pinMode(echoPin1, INPUT); //Initiates Echo Pin 1
  pinMode(triggerPin1, OUTPUT); //Initiates Trigger Pin 1
  pinMode(echoPin2, INPUT); //Initiates Echo Pin 2
  pinMode(triggerPin2, OUTPUT); //Initiates Trigger Pin 2
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel B pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel B pin
  
}

void loop(){
  
  /* The following trigPin/echoPin 1 cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(triggerPin1, LOW); 
 delayMicroseconds(2); 

 digitalWrite(triggerPin1, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(triggerPin1, LOW);
 duration = pulseIn(echoPin1, HIGH);

  /* The following trigPin/echoPin 2 cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(triggerPin1, LOW); 
 delayMicroseconds(2); 

 digitalWrite(triggerPin1, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(triggerPin1, LOW);
 duration = pulseIn(echoPin1, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;

 
 
 if (distance >= maximumRange1 || distance <= maximumRange2){
  Serial.println(distance);
  
 
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(speedMotorA, 123);   //Spins the motor on Channel A at half speed

  //Motor B backward @ half speed
  digitalWrite(13, LOW);  //Establishes forward direction of Channel B
  digitalWrite(8, LOW);   //Disengage the Brake for Channel B
  analogWrite(speedMotorB, 123);    //Spins the motor on Channel B at half speed

 }
  
 else{
  Serial.println("-1");
    digitalWrite(9, HIGH);  //Engage the Brake for Channel A
    digitalWrite(8, HIGH);  //Engage the Brake for Channel B
  
  
 }
  delay(100);
  
}
