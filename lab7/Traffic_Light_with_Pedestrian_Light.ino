int green = 2; // this number indicates the pin number of the Arduino board
int yellow = 3;
int red = 4;
int pRed = 5;
int pGreen = 6;
void setup() {
pinMode(green, OUTPUT);
pinMode(yellow, OUTPUT);
pinMode(red, OUTPUT);
pinMode(pRed, OUTPUT);
pinMode(pGreen, OUTPUT);
}
void loop() {
 // add FSM by calling state sub-routines here
  state_1();
  state_2();
  state_3();
  state_4();
}
void state_1() { // definition of State 1
 // add codes here to light up the LEDs and provide time delays
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  digitalWrite(pRed, LOW);
  digitalWrite(pGreen, HIGH);
  delay(5000);
}
// add more states here 
void state_2() {
  digitalWrite(red, HIGH);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(pRed, LOW);
  // Flash
  for (int i = 0; i < 3; i++) {
    digitalWrite(pGreen, HIGH);
    delay(500);
    digitalWrite(pGreen, LOW);
    delay(500);
    
  }
}

void state_3() {
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(pRed, HIGH);
  digitalWrite(pGreen, LOW);
  delay(5000);
}

void state_4() {
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(pRed, HIGH);
  digitalWrite(pGreen, LOW);
  delay(3000);
}
