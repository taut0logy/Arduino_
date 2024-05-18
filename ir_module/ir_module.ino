#include <AFMotor.h>


const int ledPin = 11;     // LED connected to digital pin 5
const int irSensorPin = 7; // IR Sensor connected to digital pin 2

void setup()
{
    pinMode(ledPin, OUTPUT); // Set the LED pin as output
    pinMode(irSensorPin, INPUT);
    digitalWrite(ledPin, LOW); // Set the IR sensor pin as input
}

void loop()
{
    int sensorState = digitalRead(irSensorPin); // Read the state from the IR sensor

    // The sensor outputs LOW when it detects an obstacle
    if (sensorState == LOW)
    {
        digitalWrite(ledPin, HIGH); // Turn the LED on
    }
    else
    {
        digitalWrite(ledPin, LOW); // Turn the LED off
    }
}