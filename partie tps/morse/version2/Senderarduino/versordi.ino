bool laststate=0;
void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  if(digitalRead(2)==LOW && laststate==0){
    //pour reduir les signaux indesirables on verifie après 10ms si le boutton est toujours enfoncé
    delay(10);
    if(digitalRead(2)==LOW){
    Serial.println('1');
    laststate=1;  
    }
  }else if(digitalRead(2)==HIGH && laststate==1){
     //pour reduir les signaux indesirables on verifie après 10ms si le boutton est toujours relaché
    delay(10);
    if(digitalRead(2)==HIGH){
      Serial.println('0');
      laststate=0;
    }
  }
delay(10);

  
}