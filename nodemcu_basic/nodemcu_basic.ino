void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
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