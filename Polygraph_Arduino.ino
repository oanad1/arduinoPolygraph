#include "DHT.h"
       
#define DHTTYPE DHT11 
#define DHTPIN 2                 // DHT sensor connected to digital pin 2
DHT dht(DHTPIN, DHTTYPE);        // Sets up DHT sensor

int PulseSensor = 0;             // Pulse sensor connected to analog pin 0 
int LED = 13;                    // LED that blinks whenever a heartbeat is detected
float Signal;                    // Value read from the pulse sensor
int Threshold = 520;             // The treshold for a heartbeat


void setup() {
  pinMode(LED,OUTPUT);           // Set up output LED
  Serial.begin(9600);            // Set up Serial communication
  dht.begin();                   // Initialize DHT sensor
}


void loop() {

   // Read the pulse sensor's value
   Signal = analogRead(PulseSensor); 

   // If the signal is above "520", then "turn-on" the LED.
   if(Signal > Threshold){                     
     digitalWrite(LED,HIGH);
   } else {
     digitalWrite(LED,LOW);               
   }

  // Read humidity data as %
  float h = dht.readHumidity();
  
  // Read temperature as Celsius
  float t = dht.readTemperature();
  
  // Check if read failed
  if (isnan(h) || isnan(t)) {
    return;
  }
  // Print data from sensors
  Serial.println(String(Signal) + ' ' + String(h) + ' ' + String(t));
  delay(50);


}
