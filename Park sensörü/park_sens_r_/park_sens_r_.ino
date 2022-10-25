int trigPin = 3;
int echoPin = 4;
int ledPin1 = 8;
int ledPin2 = 9;
int ledPin3 = 10;
int ledPin4 = 11;
int buzzerPin = 12;

long sure;
long mesafe;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH);
  mesafe = (sure/2)/29.1;

  if(mesafe <= 10)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }
  else if(mesafe <= 15)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(100);
    digitalWrite(ledPin4, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(100);
  }
  else if(mesafe <= 20)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
    digitalWrite(buzzerPin, HIGH);
    delay(150);
    digitalWrite(ledPin3, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(150);
  }
  else if(mesafe <= 25)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(buzzerPin, HIGH);
    delay(200);
    digitalWrite(ledPin2, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }
  else
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}
