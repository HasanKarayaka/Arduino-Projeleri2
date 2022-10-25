void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
int isik = analogRead(A0);
delay(50);

if(isik > 900)
{
 digitalWrite(3,LOW);
}
if(isik < 750)
{
 digitalWrite(3,HIGH);
}

}
