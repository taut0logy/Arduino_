#include <Arduino.h>
#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\basic_pir\\basic_pir.ino"
#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\basic_pir\\basic_pir.ino"
void setup();
#line 12 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\basic_pir\\basic_pir.ino"
void loop();
#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\basic_pir\\basic_pir.ino"
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(6, INPUT);
    pinMode(13, OUTPUT);
    //digitalWrite(13, HIGH);
}
int state = LOW;
int pir;

void loop()
{
    pir = digitalRead(6);
    //Serial.println(pir);
    if (pir == HIGH)
    {                           // check if the sensor is HIGH
        digitalWrite(13, HIGH); // turn LED ON
        //delay(100);             // delay 100 milliseconds

        if (state == LOW)
        {
            Serial.println("Motion detected!");
            state = HIGH; // update variable state to HIGH
        }
    }
    else
    {
        digitalWrite(13, LOW); // turn LED OFF
        //delay(100);            // delay 100 milliseconds

        if (state == HIGH)
        {
            Serial.println("Motion stopped!");
            state = LOW; // update variable state to LOW
        }
    }
}
