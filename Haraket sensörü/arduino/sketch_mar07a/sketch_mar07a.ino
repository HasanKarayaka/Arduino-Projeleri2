#include <Servo.h>

int pirPin = 8;
int servoPin = 9;
int ledpin = 10; 
int haraket;
Servo motor;

void setup() {
 motor.attach(servoPin);
 pinMode (pirPin,INPUT);
 pinMode(10,OUTPUT);
}

void loop() {
 haraket =digitalRead(pirPin);
 if(haraket== HIGH)
 {
  motor.write(180);
  delay(250);
  motor.write(30);
  digitalWrite(10,HIGH);
  delay(50);
  digitalWrite(10,LOW);
 }
 else{
  motor.write(90);
 }
}
