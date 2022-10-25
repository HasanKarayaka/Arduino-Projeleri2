#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  

int esikDegeri=400;
int buzzerPin=9;
int deger;

void setup() {
pinMode(buzzerPin,OUTPUT);

lcd.init(); 

}

void loop() {
 deger=analogRead(A0)

  if(deger > esikDegeri){
  digitalWrite(buzzerPin,HIGH);
  delay(100);
  digitalWrite(buzzerPin,LOW);
  delay(100);

  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("DİKKAT GAZ ");
  lcd.setCursor(1,1);
  lcd.print("ALGILANDI!!!");
  
 }

 else
 {
   lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("DURUM NORMAL :) ");
  
  digitalWrite(buzzerPin,LOW);
 }
}
