#include <Servo.h>
int angle =0;     //to store servo angle
Servo servo;     //creat servo objet to control servo


void setup() {
  Serial.begin(9600);
  servo.attach(5);

}

void loop() {
  for(angle=0;angle<=60;angle += 1){     //angle += 1 or delay(30)  to control speed
    servo.write(angle);
    delay(30);
  }
  delay(2000);
    for(angle=0;angle>=60;angle -= 1){
    servo.write(angle);
    delay(30);
  }
}
