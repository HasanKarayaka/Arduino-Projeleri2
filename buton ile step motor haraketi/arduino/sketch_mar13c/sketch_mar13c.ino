int button1 = 9;
int button2 = 10;
int button3 = 11;
const int motorPin1 = 2;
const int motorPin2 = 3;
const int motorPin3 = 4;
const int motorPin4 = 5;

const int k_led = A5;
const int y_led = A4;
const int m_led = A3;


int bekleme = 2;

int buttondurum1;
int buttondurum2;
int buttondurum3;
void setup() {
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
    
 pinMode(9,INPUT);
 pinMode(10,INPUT);
 pinMode(11,INPUT);
Serial.begin(9600);


pinMode(k_led,OUTPUT);
pinMode(y_led,OUTPUT);
pinMode(m_led,OUTPUT);

}

void loop() {
Serial.println(buttondurum1 );
  Serial.println(buttondurum2 );
  Serial.println(buttondurum3 );
 buttondurum1 = digitalRead(button1);
 buttondurum2 = digitalRead(button2);
 buttondurum3 = digitalRead(button3);

if(buttondurum1 == 0)
{
 digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);


 //kırmızı
 digitalWrite(k_led,LOW);
 digitalWrite(m_led,HIGH);
 digitalWrite(y_led,LOW);

}
if(buttondurum2 == 0)
{
 digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, LOW);

//yeşil
 digitalWrite(k_led,LOW);
digitalWrite(m_led,LOW);
digitalWrite(y_led,HIGH);

}
if(buttondurum3 == 0)
{
 digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW);

 //mavi
 digitalWrite(k_led,HIGH);
 digitalWrite(m_led,LOW);
 digitalWrite(y_led,LOW);

}

}
