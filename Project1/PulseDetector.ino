const int ledPin = 2;
const int analogPin = A0;
bool pulseCounted = false;
int count = 0;
int rawPulseVal = 0;
int pulseRate = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  //pinMode(analogPin, INPUT);
  digitalWrite(ledPin, LOW);  
}

void loop() {

  rawPulseVal = analogRead(analogPin);
  if (rawPulseVal > 560) {
    digitalWrite(ledPin, HIGH);
    if (!pulseCounted) {
      count++;
      //Serial.println(millis());
      pulseCounted = true;
    }
  } else {
    pulseCounted = false;
    digitalWrite(ledPin, LOW);
  }

  pulseRate = count * 60000/ millis() ;

  // Print pulse
  Serial.print("Pulse:");
  Serial.print(rawPulseVal);
  Serial.print(", ");
  Serial.print("PulseRate:");
  Serial.println(pulseRate);
  delay(20);                             //  take a break
}
