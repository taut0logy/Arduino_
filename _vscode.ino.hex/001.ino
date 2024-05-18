#include <Servo.h>
Servo S;
float dur;
float d;
int i=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  S.attach(9);
  pinMode (A0,OUTPUT);
  pinMode(A1,INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  //S.write(0);
  
  digitalWrite(A0,LOW);
  delay(10);
  digitalWrite(A0,HIGH);
  delayMicroseconds(10);
  digitalWrite(A0,LOW);
  dur=pulseIn(A1,HIGH);
  d=(348*(.000001*dur)/2)*100;
  Serial.print("Distance is   ");
  Serial.print(d);
  Serial.println("  cm.");
  delay(2);
  //S.write(0);
  if(d<=20)
  {
    if(i==180)
    {
      for(i=0;i<=180;i+=10)
      {
        S.write(i);
        delay(20);
      } 
    }
    else
    {
      for(i=180;i>=0;i-=10)
      {
        S.write(i);
        delay(20);
      }
    }
    delay(1000);
  }
}