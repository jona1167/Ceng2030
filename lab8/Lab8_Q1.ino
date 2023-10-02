int red = 13; // this number indicates the pin number of the Arduino board
int ir = 2;

void setup() {
  // set the input & output pins here
  pinMode(red, OUTPUT);
  pinMode(ir, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the output digital signal from the IR sensor
  // if an obstacle is detected, turn the red LED on
  // if there is no obstacle, turn the red LED off
  int value = digitalRead(ir);
  Serial.print("SensorPin Value: ");
  Serial.println(value);
  delay(10);
   if (value==HIGH){ // LOW MEANS Object Detected
    digitalWrite(red, HIGH);
  }
  else
  {
    digitalWrite(red, LOW); 
  }
  
  

  
}
