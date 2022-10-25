#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  


int ledPin = 7;
int esikDegeri = 400;               //Gaz eşik değerini belirliyoruz.    
int buzzerPin = 9;                  //Buzzerın takılacağı pin
int deger;                          //Sensörden okunan değer

void setup() {
  pinMode(buzzerPin, OUTPUT);  //Buzzer pinimizi çıkış olarak ayarlıyoruz.
  pinMode(ledPin,OUTPUT);
  lcd.init(); 
  }

void loop() {
  deger = analogRead(A0);           //Sensörden analog değer okuyoruz.
  if(deger > esikDegeri){           //Sensörden okunan değer eşik değerinden büyükse çalışır.
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(buzzerPin, LOW);
    delay(100);
digitalWrite(ledPin, HIGH);
    delay(100);
 digitalWrite(ledPin, LOW);
    delay(100);
  
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("DIKKAT GAZ ");
  lcd.setCursor(1,1);
  lcd.print("ALGILANDI!!!");
  
  }
  else{                             //Sensörden okunan değer eşik değerinin altındaysa çalışır.
    digitalWrite(buzzerPin, LOW);
 
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("DURUM NORMAL :) "); 
 
  }
}
