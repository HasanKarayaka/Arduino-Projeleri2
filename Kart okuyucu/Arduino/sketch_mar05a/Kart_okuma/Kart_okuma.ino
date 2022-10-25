
#include <MFRC522.h>
#include <SPI.h>


int RST_PIN = 9 ; // Haberlesme pinlerini tanimladik.
int SS_PIN = 10 ; // Haberlesme pinlerini tanimladik.
int redPin = 3 ; // kirmizi ledin bagli oldugu pin
int greenPin = 4 ; // yesil ledin bagli oldugu pin
MFRC522 rfid (SS_PIN, RST_PIN); // rfid objemizi olusturduk.
byte ID[4] = {25,119,80,71}; 

void setup() 
{
  Serial. begin ( 9600 ); // seri monitoru baslattik.
  SPI. begin (); // haberlesmeyi baslattik
  rfid. PCD_Init (); // rfid baslattik
  pinMode (redPin, OUTPUT); // led pinlerimizi cikis pini yaptik
  pinMode (greenPin, OUTPUT);
}

void loop()  {

      if (! rfid. PICC_IsNewCardPresent())
        return ;
      if (! rfid. PICC_ReadCardSerial()) 
        return ;
      if (rfid. uid.uidByte[0] == ID[0] &&  rfid. uid.uidByte[1] == ID[1] && rfid. uid.uidByte[2] == ID[2] && rfid. uid.uidByte[3] == ID[3])
      {
      Serial.println("Kart yetkili");
       digitalWrite (greenPin, HIGH);
       digitalWrite (redPin, LOW);
       delay(1000);
         digitalWrite (greenPin, LOW);
       digitalWrite (redPin, LOW);
      ekranaYazdir();
      }
      else{
         digitalWrite (greenPin, LOW);
         digitalWrite (redPin, HIGH);
           Serial.print("Yetkisiz kart");
            delay(3000);
            digitalWrite (greenPin, LOW);
            digitalWrite (redPin, LOW);
           ekranaYazdir();
          }
          rfid.PICC_HaltA();
}
void ekranaYazdir(){
  Serial.print("ID Numarası : ");
    for(int sayac=0;sayac<4;sayac++)
    { 
    Serial.print(rfid.uid.uidByte[sayac]);
    Serial.print("  ");
    }
Serial.println("");
}
