#include <Servo.h>
const int sensorLeftPin = A4;
const int sensorRightPin = A5;
const int servoPin = 11;
Servo myservo;
int servoPos = 0;
int sensorLeftAO = 0;
int sensorRightAO = 0;
int deadband = 20;

void setup() {

  Serial.begin(9600);
  myservo.attach(servoPin);
  myservo.write(0);
  
}

void loop() {
  
  sensorLeftAO = analogRead(sensorLeftPin);
  sensorRightAO = analogRead(sensorRightPin);
  Serial.print("Left: ");
  Serial.print(sensorLeftAO);
  Serial.print(" Right: ");
  Serial.print(sensorRightAO);
  Serial.println();

  // Compare left right value
  if(sensorLeftAO < sensorRightAO){// Rotate left
    if(sensorRightAO- sensorLeftAO > deadband && servoPos > 0){//range 0 to 180
      servoPos--;
      myservo.write(servoPos);
      delay(15);
    }
  }else if(sensorRightAO < sensorLeftAO){// Rotate right
    if(sensorLeftAO- sensorRightAO > deadband && servoPos<180){
      servoPos++;
      myservo.write(servoPos);
      delay(15);
    }
  }
}