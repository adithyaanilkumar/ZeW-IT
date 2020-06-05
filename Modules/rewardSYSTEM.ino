#include<Servo.h>
Servo nr;

void setup() {
 nr.write(9);
 

}

void loop() {
 for(int i=0;i<=180;i++)
 {
  nr.write(i);
  delay(15);
 }
 delay(3000);
 for(i=180;i<=0;i--)
 {
  nr.write(i);
  delay(15)
 }

}
