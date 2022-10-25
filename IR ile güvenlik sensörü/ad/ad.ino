#include <IRremote.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;

int led1 = 8;
int buzzer=3;

void setup() 
{
  lcd.init(); 
    
  pinMode(led1, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  digitalWrite(led1,HIGH);
  Serial.println("KIZILOTESI KORUMA ETKIN");

  
}
void loop() 
{


  if (irrecv.decode(&results)) 
  {
      if(results.value)
      {
        irrecv.resume();
        Serial.println("DİKKAT GUVENLIK IHLALI");
        digitalWrite(buzzer,HIGH);
        delay(1000);
        digitalWrite(buzzer,LOW);
        lcd.backlight();
        lcd.setCursor(1,0);
        lcd.print("TEHLIKE ALGILANFI!!!");
        lcd.setCursor(1,1);
        lcd.print("ALARM !!!");
       
      } 

  }

  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("DURUM NORMAL");
  lcd.setCursor(1,1);
  lcd.print(":D :D");

}
