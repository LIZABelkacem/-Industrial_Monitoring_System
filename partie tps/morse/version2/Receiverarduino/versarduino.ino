bool laststate=0;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available()) {
    char state = Serial.read();
    Serial.print(state);
    if (state == '1')
    {
      digitalWrite(13, 1);
    } else if(state == '0'){
      digitalWrite(13, 0);
    }
  }
  
}