void setup() {
pinMode(0,OUTPUT); //arduino nun bacaklarını tanımladık
pinMode(1,OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
}

void loop() {
 digitalWrite(0,HIGH);// "1. ledin yanması komutunu verdik ve ne kadar süre yanması gerektiğini söyledik
delay(100);
digitalWrite(0,LOW);
delay(100);
digitalWrite(1,HIGH);
delay(100);
digitalWrite(1,LOW);
delay(100);
digitalWrite(2,HIGH);
delay(100);
digitalWrite(2,LOW);
delay(100);
digitalWrite(3,HIGH);
delay(100);
digitalWrite(3,LOW);
delay(100);
}
