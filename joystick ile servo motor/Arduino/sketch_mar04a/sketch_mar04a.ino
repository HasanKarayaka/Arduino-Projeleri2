#include <Servo.h>
Servo motor;
int deger;
int derece;

int xPin = A0; 

int yPin = A1; 

int ledK=10; int ledM=11; int ledY=12; int ledS=13;

 

int xPozisyon = 0;

int yPozisyon = 0;


void setup() {
 motor.attach(3);

pinMode(xPin, INPUT);

pinMode(yPin, INPUT);

pinMode(ledK,OUTPUT); pinMode(ledM,OUTPUT); 

pinMode(ledY,OUTPUT); pinMode(ledS,OUTPUT);
}

void loop() {
  deger=analogRead(A0);
  deger=analogRead(A1);
  derece=map(deger,0,1023,0,180);
  motor.write(derece);


xPozisyon = analogRead(xPin);

yPozisyon = analogRead(yPin);

if(xPozisyon<10){digitalWrite(ledK,HIGH);}else{digitalWrite(ledK,LOW);}

if(xPozisyon>1000){digitalWrite(ledM,HIGH);}else{digitalWrite(ledM,LOW);} 

if(yPozisyon<10){digitalWrite(ledY,HIGH);}else{digitalWrite(ledY,LOW);}

if(yPozisyon>1000){digitalWrite(ledS,HIGH);}else{digitalWrite(ledS,LOW);}

}
