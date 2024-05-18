#include <Wire.h>
const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 11;
const int echoPin2 = 12;
const int irModulePin1 = A0;
const int irModulePin2 = A1;
const int irModulePin3 = A2;
const int irModulePin4 = A3;

void setup()
{
    Serial.begin(115200);
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
}

void loop()
{

    long ultrasonicDistance1 = measureDistance(trigPin1, echoPin1);
    long ultrasonicDistance2 = measureDistance(trigPin2, echoPin2);

    int irModule1Value = analogRead(irModulePin1);
    int irModule2Value = analogRead(irModulePin2);
    int irModule3Value = analogRead(irModulePin3);
    int irModule4Value = analogRead(irModulePin4);

    Serial.print("U");
    Serial.println(ultrasonicDistance1);
    Serial.print("U");
    Serial.println(ultrasonicDistance2);
    Serial.print("I1");
    Serial.println(irModule1Value);
    Serial.print("I2");
    Serial.println(irModule2Value);
    Serial.print("I3");
    Serial.println(irModule3Value);
    Serial.print("I4");
    Serial.println(irModule4Value);

    Wire.write((byte *)&ultrasonicDistance1, sizeof(ultrasonicDistance1));
    Wire.write((byte *)&ultrasonicDistance2, sizeof(ultrasonicDistance2));
    Wire.write((byte *)&irModule1Value, sizeof(irModule1Value));
    Wire.write((byte *)&irModule2Value, sizeof(irModule2Value));
    Wire.write((byte *)&irModule3Value, sizeof(irModule3Value));
    Wire.write((byte *)&irModule4Value, sizeof(irModule4Value));
    delay(100);
}

long measureDistance(int trigPin, int echoPin)
{

    long duration, distance;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration / 2) / 35;

    return distance;
}
