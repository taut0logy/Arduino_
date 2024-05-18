#include <Arduino.h>
#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\basic_relay\\basic_relay.ino"
#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\basic_relay\\basic_relay.ino"
void setup();
#line 9 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\basic_relay\\basic_relay.ino"
void loop();
#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Arduino\\basic_relay\\basic_relay.ino"
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
}

void loop()
{
    if (Serial.available() > 0)
    {
        char c = Serial.read();
        if (c == '1')
            digitalWrite(13, LOW);
        else if (c == '0')
            digitalWrite(13, HIGH);
    }
}
/* https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
https://arduino.esp8266.com/stable/package_esp8266com_index.json
https://dl.espressif.com/dl/package_esp32_index.json */
