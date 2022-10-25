const int lm35 = A0;

float voltaj_deger = 0;
float sicaklik = 0;
int gelen_veri = 0;

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2);
  pinMode(lm35, INPUT);
}

void loop()
{
  gelen_veri = analogRead(lm35);
  voltaj_deger = (gelen_veri / 1023.0) * 5000;
  sicaklik = voltaj_deger / 100.0;
  lcd.clear();
  lcd.home();
  lcd.print("sicaklik = ");
  lcd.setCursor(0, 1);
  lcd.print(sicaklik);
  lcd.print(" derece");
  delay(1000);

}
