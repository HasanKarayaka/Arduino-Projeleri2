char gelen;
const int yesil=2;
const int sari=3;
const int mavi=4;

void setup() {
  pinMode(yesil,OUTPUT);
  pinMode(sari,OUTPUT);
  pinMode(mavi,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0){  
  gelen =Serial.read();
  if(gelen=='0')
  {
    digitalWrite(yesil,HIGH);
  }
  else if(gelen=='1')
  {
    digitalWrite(yesil,LOW);
  }
  else if(gelen=='2')
  {
    digitalWrite(sari,HIGH);
  }
  else if(gelen=='3')
  {
    digitalWrite(sari,LOW);
  }
  else if(gelen=='4')
  {
    digitalWrite(mavi,HIGH);
  }
  else if(gelen=='5')
  {
    digitalWrite(mavi,LOW);
  }
  else if(gelen=='6')
  {
    digitalWrite(mavi,HIGH);
    digitalWrite(sari,HIGH);
    digitalWrite(yesil,HIGH);
  }
  else if(gelen=='7')
  {
    digitalWrite(mavi,LOW);
    digitalWrite(sari,LOW);
    digitalWrite(yesil,LOW);
  }
  }

}
