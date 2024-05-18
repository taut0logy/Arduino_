#include <Arduino.h>
#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\nodemcu_basic\\nodemcu_basic.ino"
#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\nodemcu_basic\\nodemcu_basic.ino"
void setup();
#line 7 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\nodemcu_basic\\nodemcu_basic.ino"
void loop();
#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\nodemcu_basic\\nodemcu_basic.ino"
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(D4, OUTPUT);
}
void loop()
{
    if (Serial.available() > 0)
    {
        char c = Serial.read();
        if (c == '0')
            digitalWrite(D4, LOW);
        else if (c == '1')
            digitalWrite(D4, HIGH);
    }
}
