#include<dht11.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
dht11 DHT11;
#define DHT11PIN 2
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
void setup() 
{
    lcd.init(); 

}

void loop() 
{
  lcd.backlight();
  int deger= DHT11.read(DHT11PIN); 
  lcd.setCursor(1,0);
  lcd.print("Sicaklik: ");
  lcd.println((float)DHT11.temperature);
  lcd.setCursor(1,1);
  lcd.print("Nem: ");
  lcd.println((float)DHT11.humidity);


}
