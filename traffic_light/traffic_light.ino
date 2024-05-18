int red = 4;
int yellow = 5;
int green = 6;
void setup()
{
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
}

void loop()
{
    digitalWrite(red, HIGH);
    delay(2000);
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    delay(2000);
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(1000);
    digitalWrite(yellow, LOW);
}