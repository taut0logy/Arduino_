#include <Servo.h>
Servo S;
float dur;
float d;
int i = 0, trig = 2, echo = 3;
void setup()
{
    // put your setup code here, to run once:
    S.attach(0);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(13, OUTPUT);
}

void loop()
{

    // put your main code here, to run repeatedly:
    // S.write(0);
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    dur = pulseIn(echo, HIGH);
    d = dur * 0.034 / 2;
    if (d < 10)
    {
        S.write(0);
    }
    else if (d < 20)
    {
        S.write(45);
    }
    else if (d < 30)
    {
        S.write(90);
    }
    else if (d < 40)
    {
        S.write(135);
        digitalWrite(13, HIGH);
    }
    else if (d < 50)
    {
        S.write(180);
    }
    else
    {
        S.write(0);
    }
}