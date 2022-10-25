#include<dht11.h>

dht11 DHT11;
#define DHT11PIN 2
void setup() 
{
  
Serial.begin(9600);

}

void loop() 
{

int deger= DHT11.read(DHT11PIN);
Serial.print("Sicaklik: ");
Serial.println((float)DHT11.temperature);
Serial.print("Nem: ");
Serial.println((float)DHT11.humidity);

}
