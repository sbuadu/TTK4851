//start definitions for sounds

#include <SoftwareSerial.h>
#define ARDUINO_RX 2//should connect to TX of the Serial MP3 Player module
#define ARDUINO_TX 6//connect to RX of the module
SoftwareSerial myMP3(ARDUINO_RX, ARDUINO_TX);

/*5 bytes commands*/
#define CMD_SEL_DEV 0X35
#define DEV_TF 0X01

/*6 bytes commands*/  
#define CMD_PLAY_W_INDEX   0X41
#define CMD_PLAY_FILE_NAME 0X42
#define CMD_INJECT_W_INDEX 0X43

/*Special commands*/
#define CMD_SET_VOLUME 0X31
#define CMD_PLAY_W_VOL 0X31

#define CMD_SET_PLAY_MODE 0X33

void sendCommand(int8_t command, int16_t dat );

//end definitions for sounds

 // variable to receive data from the serial port
int echoPin1 = 10;
int triggerPin1 = 7;
int echoPin2 = 5;
int triggerPin2 = 4;
int directionLeft = 12;
int breakLeft = 9;
int speedMotorA = 3;
int directionRight = 13;
int breakRight = 8;
int speedMotorB = 11;
int state=0;
int flag =0; 
int temp=0;

int maximumRange1 = 1000; // Maximum range needed
int minimumRange1 = 20; // Minimum range needed

int maximumRange2 = 20; // Maximum range needed
int minimumRange2 = 0; // Minimum range needed

long duration1, duration2, distance1, distance2; // Duration is used to calculate distance

void setup() {
    //Setup Ultrasonic Sensor upper
  pinMode(echoPin1, INPUT); //Initiates Echo Pin 1
  pinMode(triggerPin1, OUTPUT); //Initiates Trigger Pin 1
  
  //Setup Ultrasonic Sensor lower
  pinMode(echoPin2, INPUT); //Initiates Echo Pin 2
  pinMode(triggerPin2, OUTPUT); //Initiates Trigger Pin 2

  pinMode(directionLeft, OUTPUT); //Initiates Motor Channel A pin
  pinMode(breakLeft, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(directionRight, OUTPUT); //Initiates Motor Channel B pin
  pinMode(breakRight, OUTPUT);  //Initiates Brake Channel B pin
  Serial.begin(9600);       // start serial communication at 9600bps

  //For startup sound
  myMP3.begin(9600);
  
  delay(500);//Wait chip initialization is complete
  sendCommand(CMD_SEL_DEV, DEV_TF);//select the TF card  
  delay(200);//wait for 200ms
  
  setVolume(0X19); 
  playFile(0X0005);
}

void loop() {
  stopMotors();
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
  
while (distance1 >= minimumRange1 && distance2 <= maximumRange2){

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
  
  drive();

  }    
} 


void reverse(int timelaps) {
  digitalWrite(directionLeft, LOW);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorA, 90);

  digitalWrite(directionRight, HIGH);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorA, 90);

  delay(timelaps);
}

void stopMotors() {
  digitalWrite(breakLeft, HIGH);
  digitalWrite(breakRight, HIGH);
}

void turnRight(int timelaps) {
  digitalWrite(directionLeft, HIGH);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorB, 100);

  digitalWrite(directionRight, HIGH);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorA, 100);

  delay(timelaps);
   
}

void turnLeft(int timelaps) {
  digitalWrite(directionRight, LOW);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorA, 100);

  digitalWrite(directionLeft, LOW);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorB, 100);

  delay(timelaps);
   
}

void goForward() {
  digitalWrite(directionLeft, HIGH);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorA, 100);

  digitalWrite(directionRight, LOW);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorB, 100);

}
