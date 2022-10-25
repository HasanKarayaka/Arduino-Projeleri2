#define pinA 4
#define pinB 5
#define pinC 6
#define pinD 7
#define pinE 8
#define pinF 9
#define pinG 10

int azaltButon = 2; // Azaltma Butonu pini 2
int arttirButon = 3; // Arttırma Butonu pini 3
// Buton durumlarını bu değişkenlerde saklayacağız
int butonDurumuAzalt; 
int butonDurumuArttir;
// Sayaç değişkeni ile displayde arrtırma ya da azaltma işlemi tutulacak
int sayac = 0;

void setup()
{
// For döngüsü displayin pinlerini çıkış olarak tanımlıyor
  for (int i = 4; i < 11; i++) {
    pinMode(i, OUTPUT);


  }
  pinMode(azaltButon, INPUT); // Azaltma butonu giriş
  pinMode(arttirButon, INPUT); // Arttırma butonu çıkış
}

void loop()
{
  butonDurumuAzalt = digitalRead(azaltButon); 
  // Azaltma butonu basılınca değer, durum değişkeninde saklanacak
  if (butonDurumuAzalt == HIGH) { // Azaltma Butonu basılı mı?
    sayac--; // Sayacı 1 azalt
    if (sayac < 0) // Eğer sayaca 0'dan küçükse
      sayac = 9; // Sayaca 9 değerini ata
    while (1) { // Azaltma butonu basıldığı sürece sonsuz döngüye gir
      butonDurumuAzalt = digitalRead(azaltButon);
      if (butonDurumuAzalt == LOW)
        return;
    }
  }
  sevenSegment(sayac); // sevenSegment fonksiyonuna sayac parametresini gönder
  // Ve gönderilen parametre değeri ne ise ona göre LED'leri yak!!!

  butonDurumuArttir = digitalRead(arttirButon);
  // Arttırma butonu basılınca değer, durum değişkeninde saklanacak
  if (butonDurumuArttir == HIGH) { // Arttırma Butonu basılı mı?
    sayac++; // Sayacı 1 arttır
    if (sayac == 10) // Eğer sayaca 10'a eşitse
      sayac = 0; // Sayaca 0 değerini ata
    while (1) { // Arttırma butonu basıldığı sürece sonsuz döngüye gir
      butonDurumuArttir = digitalRead(arttirButon);
      if (butonDurumuArttir == LOW)
        return;
    }
  }
  sevenSegment(sayac);// sevenSegment fonksiyonuna sayac parametresini gönder
  // Ve gönderilen parametre değeri ne ise ona göre LED'leri yak!!!
}

// 7Segment displayde rakamları göstermek için bu fonksiyonu tanımladık
// digit parametresi loop içinden gönderilen sayacı ifade edecek
// Gelen sayac ne ise display onu gösterecek
// Switch-case ile bu çok basit bir şekilde uygulanabilir
void sevenSegment (int digit) {

  switch (digit) {
    case 0: // Gelen sayac yani digit 0 ise 0 rakamı yanacak
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);

      break; 
    case 1: // Gelen sayac yani digit 1 ise 1 rakamı yanacak
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);

      break;
    case 2: // Gelen sayac yani digit 2 ise 2 rakamı yanacak
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);

      break;
    case 3: // Gelen sayac yani digit 3 ise 3 rakamı yanacak
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);

      break;
    case 4: // Gelen sayac yani digit 4 ise 4 rakamı yanacak
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);

      break;
    case 5: // Gelen sayac yani digit 5 ise 5 rakamı yanacak
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);

      break;
    case 6: // Gelen sayac yani digit 6 ise 6 rakamı yanacak
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);

      break;
    case 7: // Gelen sayac yani digit 7 ise 7 rakamı yanacak
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);

      break;
    case 8: // Gelen sayac yani digit 8 ise 8 rakamı yanacak
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);

      break;
    case 9: // Gelen sayac yani digit 9 ise 9 rakamı yanacak
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);

      break;

  }
}
