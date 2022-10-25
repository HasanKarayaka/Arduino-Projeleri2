#include <IRremote.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

int irsensor =A0;

int led1 = 3;
int buzzer = 4;
void setup() {
  lcd.init(); 

 Serial.begin(9600);

 pinMode(led1,OUTPUT);
 pinMode(buzzer,OUTPUT);
  
}

void loop() {
 int irdeger=analogRead(irsensor);
  Serial.print("Sensor degeri: ");
  Serial.println(irdeger);
  delay(500);
 
 if(irdeger>0)
 {
  digitalWrite(led1,HIGH);
  delay(50);
  digitalWrite(buzzer,HIGH);
   delay(50);
   
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("TEHLIKE ALGILANFI!!!");
  lcd.setCursor(1,1);
  lcd.print("ALARM !!!");
 }
 else
 {
  digitalWrite(led1,LOW);
  digitalWrite(buzzer,LOW);
  
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Durum NORMAL");
  lcd.setCursor(1,1);
  lcd.print(":D :D");
   
 }
}
