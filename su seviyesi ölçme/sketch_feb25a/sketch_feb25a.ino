


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define trig 7
#define echo 6
#define bazzer 8
#define led 5
float uzaklik;
float sure;
float litre;
float referance=1.845;
int minx=-1;
int maxx=3;
LiquidCrystal_I2C lcd(0x27,16,2);



void setup() 
{
   lcd.init();
   pinMode (trig,OUTPUT);
   pinMode (echo,INPUT);
   pinMode (bazzer,OUTPUT);

   pinMode (led,OUTPUT);
   Serial.begin(9600);
   
}

void loop() 
{
  digitalWrite (trig,LOW);
  delayMicroseconds (5);
  digitalWrite (trig,HIGH);
  delayMicroseconds (10);
  digitalWrite (trig,LOW);

  sure= pulseIn (echo ,HIGH);
  uzaklik=sure/29.1/2;
  litre= uzaklik* 11* 11/100000;
    Serial.print("Litre=");
   Serial.println(litre);
  delay (500);
  litre = referance-litre;
  Serial.print("Litre değeri=");
   Serial.println(litre);

  if(litre<=maxx && litre>=minx);
  {
    lcd.clear ();
    lcd.setCursor(0,0);
    lcd.print ("DEPO SU SEVİYESİ");
    lcd.setCursor (5,1);
    lcd.print (litre);
    delay(1000);
  }
    if(litre>=1,80);
    {
      lcd.clear();
      lcd.backlight();
      lcd.setCursor (3,0);
      lcd.print ("DİKKAT!");
      lcd.setCursor(2,1);
      lcd.print ("DEPO DOLU");
      digitalWrite (bazzer,HIGH);
      digitalWrite (led,HIGH);
      delay (500);

      digitalWrite (bazzer,LOW);
      digitalWrite (led,LOW);
      delay(500);
    }

  
   if(litre<=-0.8);
   {
       lcd.clear ();
       lcd.setCursor (3,0);
       lcd.print ("DİKKAT");
       lcd.setCursor (2,1);
       lcd.print ("DEPO BOS");
       delay (700);
    }

}
