#include <Servo.h>

Servo s;

void setup()
{
    // put your setup code here, to run once:
    s.attach(9);
    s.write(90);
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    if (Serial.available() > 0)
    {
        char c = Serial.read();
        if (c == '1')
            s.write(0);
        else if (c == '0')
            s.write(180);
        else
            s.write(90);

        delay(500);
    }
}
