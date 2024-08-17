int LDR_threshold;

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT); //BUZZER
  pinMode(A0,INPUT); //LDR
}
void loop() {
  LDR_threshold=digitalRead(A0);
  if (LDR_threshold>0){  //500 isn't working in tinkercad to chech replace it with 0.
    tone(8,680);
  }
  else
    noTone(8);
  

}
