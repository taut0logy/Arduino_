void setup()
{
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    if (Serial.available() > 0)
    {
        char c = Serial.read();
        if (c == '1')
        {
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
        }
        else if (c == '2')
        {
            digitalWrite(4, LOW);
            digitalWrite(5, HIGH);
            digitalWrite(6, LOW);
        }
        else if (c == '3')
        {
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, HIGH);
        }
    }
}