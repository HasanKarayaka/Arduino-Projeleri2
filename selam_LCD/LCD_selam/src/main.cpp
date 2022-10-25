#include <Arduino.h>
#include <DHT.h>                         // DHT.h kütüphane dosyası eklenir.

#include <Wire.h>                        // wire.h kütüphane dosyası eklenir.

#include <LiquidCrystal_I2C.h>    // I2C LCD kütüphane dosyası eklenir.

LiquidCrystal_I2C lcd(0x3f,16,2);

 

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);         // DHT pini ve tipi tanımlanır.

float nem_degeri, sicaklik_degeri;

 

void setup(){

 lcd.init();                    

 lcd.backlight();                

 dht.begin();

}

void loop(){

  float nem= dht.readHumidity();

  float sicaklik = dht.readTemperature();

     lcd.clear();

     lcd.setCursor(0, 0);

     lcd.print(“Nem: %”);

     lcd.print(nem);

     lcd.setCursor(0, 1);   

     lcd.print(“Sicaklik: “);

     lcd.print(sicaklik);

     delay(2000);               // 2 sn bekleme yapılır.

}