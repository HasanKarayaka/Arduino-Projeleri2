#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int button1 = A0;
int button2 = A1;
int button3 = A2;

int buttondurum1;
int buttondurum2;
int buttondurum3;


void setup() {
 lcd.init();

 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 Serial.begin(9600);
}

void loop() {
  Serial.println(buttondurum1 );
  Serial.println(buttondurum2 );
  Serial.println(buttondurum3 );
 buttondurum1 = digitalRead(button1);
 buttondurum2 = digitalRead(button2);
 buttondurum3 = digitalRead(button3);

   

if(buttondurum1==1)
{
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("YASIN ELHAN");
  lcd.setCursor(1,1);
  lcd.print("NEU MEKATRONIK");
  
}
if(buttondurum2==1){
 lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("4. SINIF");
  lcd.setCursor(1,1);
  lcd.print("");
  
}
if(buttondurum3==1)
{
 lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("KONYALI");
  lcd.setCursor(1,1);
  lcd.print("22 YASINDA ");
}

 
}
