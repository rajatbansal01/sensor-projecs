#include <dht.h>
#define trigPin 13
#define echoPin 12

#define dht_apin A0 // Analog Pin sensor is connected to
 int led=8 ,led1=7;
dht DHT;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    long duration, distance;
  digitalWrite(trigPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance >= 200 || distance <= 0)
  {
    Serial.println("Out of range");
    digitalWrite(led,LOW);
    digitalWrite(led1,LOW);
  }
  else if(DHT.temperature>=28 && distance<=15)
  {
    digitalWrite(led,HIGH);
    digitalWrite(led1,HIGH);
    Serial.print(distance);
    Serial.println(" cm");
  }
  else 
  {
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(led,LOW);
    digitalWrite(led1,LOW);
  }
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
 
}
