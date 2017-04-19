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
int state = 0;
int flag = 0;
int temp = 0;

int maximumRange1 = 1000; // Maximum range needed
int minimumRange1 = 10; // Minimum range needed

int maximumRange2 = 20; // Maximum range needed
int minimumRange2 = 0; // Minimum range needed

long duration1, duration2, distance1, distance2; // Duration is used to calculate distance

void setup() {
  //  Scheduler.startloop(loop1);
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

  //Setup Speaker
  Serial.begin(9600);       // start serial communication at 9600bps

  //For startup sound
  myMP3.begin(9600);

  delay(500);//Wait chip initialization is complete
  sendCommand(CMD_SEL_DEV, DEV_TF);//select the TF card
  delay(200);//wait for 200ms
  mp3_5bytes(0X31, 0X10);
  playStart();
  delay(3000);
}


void loop() {

  distance1 = checkObstacle1();
  distance2 = checkObstacle2();

  if (distance1 <= minimumRange1 || distance2 >= maximumRange2) {
    handleObstacle(distance1, distance2, minimumRange1, maximumRange2 );
  }
  drive();
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
  digitalWrite(breakLeft, HIGH);
  digitalWrite(directionRight, HIGH);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorA, 100);
  delay(timelaps);
}

void turnLeft(int timelaps) {

  digitalWrite(breakRight, HIGH);

  digitalWrite(directionLeft, LOW);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorB, 100);

  delay(timelaps);

}

void goForward() {
  digitalWrite(directionLeft, HIGH);
  digitalWrite(breakLeft, LOW);
  analogWrite(speedMotorA, 70);

  digitalWrite(directionRight, LOW);
  digitalWrite(breakRight, LOW);
  analogWrite(speedMotorB, 70);

}
