int Led = 13;
int state = HIGH;
int interruptPin = 2;
void setup() {
  pinMode(Led, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  digitalWrite(Led, state);
  attachInterrupt(digitalPinToInterrupt(interruptPin), OFF, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay (20000);
}
 void OFF(){
  digitalWrite(Led, !state);
 }
