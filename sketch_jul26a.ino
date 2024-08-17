
const int fp1=13; //1==right
const int bp1=12;
const int fp2=8;  //2==left
const int bp2=7;

void setup() {
  Serial.begin(9600);
  pinMode(fp1,OUTPUT);
  pinMode(bp1,OUTPUT);
  pinMode(fp2,OUTPUT);
  pinMode(bp2,OUTPUT);
}

void loop() {
  //right
  digitalWrite(fp2,HIGH);
  digitalWrite(bp2,LOW);
  digitalWrite(bp1,HIGH);
  digitalWrite(fp1,LOW);
  Serial.println("moving to right");
  delay(1000);
  
  //left
  digitalWrite(bp2,HIGH);
  digitalWrite(fp2,LOW);
  digitalWrite(fp1,HIGH);
  digitalWrite(bp1,LOW);
  Serial.println("moving to left");
  delay(1000);
  
  //forward
  digitalWrite(fp2,HIGH);
  digitalWrite(bp2,LOW);
  digitalWrite(fp1,HIGH);
  digitalWrite(bp1,LOW);
  Serial.println("moving to fwd");
  delay(1000);
  
  //backward
  digitalWrite(bp2,HIGH);
  digitalWrite(fp2,LOW);
  digitalWrite(bp1,HIGH);
  digitalWrite(fp2,LOW);
  Serial.println("moving to bwd");
  delay(1000);
  

}
