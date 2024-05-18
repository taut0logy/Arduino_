#include <Servo.h>
#include <Wire.h>
#include <AFMotor.h>

Servo front, back;

int front_servo = 9;
int back_servo = 10;

AF_DCMotor M1_FL(1);
AF_DCMotor M2_BL(2);
AF_DCMotor M3_BR(3);
AF_DCMotor M4_FR(4);

void setup()
{

    Wire.begin();
    Serial.begin(9600);
    front.attach(front_servo);
    back.attach(back_servo);

    M1_FL.setSpeed(255);
    M2_BL.setSpeed(255);
    M3_BR.setSpeed(255);
    M4_FR.setSpeed(255);

    M1_FL.run(RELEASE);
    M2_BL.run(RELEASE);
    M3_BR.run(RELEASE);
    M4_FR.run(RELEASE);

    front.write(90);
    back.write(90);
}

void steerRIght()
{
    M1_FL.run(BACKWARD);
    M2_BL.run(BACKWARD);
    M3_BR.run(FORWARD);
    M4_FR.run(FORWARD);
    // delay(3000 * angle / 360);
}

void steerLeft()
{
    M1_FL.run(FORWARD);
    M2_BL.run(FORWARD);
    M3_BR.run(BACKWARD);
    M4_FR.run(BACKWARD);
    // delay(3000 * angle / 360);
}

void moveForward()
{
    M1_FL.run(FORWARD);
    M2_BL.run(FORWARD);
    M3_BR.run(FORWARD);
    M4_FR.run(FORWARD);
}
  
void moveBackward()
{
    M1_FL.run(BACKWARD);
    M2_BL.run(BACKWARD);
    M3_BR.run(BACKWARD);
    M4_FR.run(BACKWARD);
}

long ultrasonic1Distance = 0;
long ultrasonic2Distance = 0;
int irModule1Value = 0;
int irModule2Value = 0;
int irModule3Value = 0;
int irModule4Value = 0;


void loop()
{

    Wire.readBytes((byte *)&ultrasonic1Distance, sizeof(ultrasonic1Distance));
    Wire.readBytes((byte *)&ultrasonic2Distance, sizeof(ultrasonic2Distance));
    Wire.readBytes((byte *)&irModule1Value, sizeof(irModule1Value));
    Wire.readBytes((byte *)&irModule2Value, sizeof(irModule2Value));
    Wire.readBytes((byte *)&irModule3Value, sizeof(irModule3Value));
    Wire.readBytes((byte *)&irModule4Value, sizeof(irModule4Value));

    Serial.print(ultrasonic1Distance);
    Serial.print(",");
    Serial.print(ultrasonic2Distance);
    Serial.println();
    Serial.println(irModule1Value);
    Serial.println(irModule2Value);
    Serial.println(irModule3Value);
    Serial.println(irModule4Value);
    Serial.println();

    if (irModule1Value == 1 && irModule2Value == 0 && irModule3Value == 0 && irModule4Value == 0)
    {
        moveForward();
    }

    if (irModule1Value == 0 && irModule2Value == 1 && irModule3Value == 0 && irModule4Value == 0)
    {
        moveForward();
    }

    // put your main code here, to run repeatedly:

    M1_FL.run(FORWARD);
    M2_BL.run(FORWARD);
    M3_BR.run(FORWARD);
    M4_FR.run(FORWARD);

    delay(1000);

    M1_FL.run(RELEASE);
    M2_BL.run(RELEASE);
    M3_BR.run(RELEASE);
    M4_FR.run(RELEASE);


    delay(1000);
}