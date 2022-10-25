#define potpin A3
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int deger=0;

void setup() {
   lcd.init(); 
  Serial.begin(9600);
  Serial.println("Pot Değer Okuma");

 

}

void loop() {

  deger = analogRead(potpin);
  float gerilim = (5.00/1024.00)*deger;
  Serial.println(gerilim);
  delay(300);


  if(deger<0.20)
{
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("ARDUINO");
  lcd.setCursor(1,1);
  lcd.print("PROJE");
  delay(5000);
  lcd.clear();
}
if(deger<1.80){
 lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("SELAMIN ALEYKUM");
  lcd.setCursor(1,1);
  lcd.print("YASIN ABI ");
  delay(5000);
   lcd.clear();
}
if(deger<3.12)
{
 lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("NASILSIN?");
  lcd.setCursor(1,1);
  lcd.print("NE YAPIYORSUN ");
  delay(5000);
  lcd.clear();
}

}
