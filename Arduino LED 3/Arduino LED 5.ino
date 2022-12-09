#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include "WaveShare_MLX90614.h"

#define LED_PIN    6
#define LED_COUNT 72
#define DELAYVAL 50
float Temp = 0;
int Temp_map=0;

WaveShare_MLX90614   MLX90614 = WaveShare_MLX90614();
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int pin5 = 5; // Test if sensor is working

void setup() {

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(100); // Set BRIGHTNESS to about 1/5 (max = 255)
  MLX90614.begin(); 
  pinMode(pin5, OUTPUT); // Test if sensor is working
}

void loop() {
  //colorWipe(strip.Color(255,   0,   0), 50); // Red
  strip.clear();
  Temp = MLX90614.readObjectTemp();
  Temp_map = map(Temp,17, 25, 0, LED_COUNT );
  if(Temp>=20.00){digitalWrite(pin5,HIGH);}
  else digitalWrite(pin5, LOW);
  strip.fill(strip.Color(255,0,0,100),0,Temp_map-1);
  strip.show();


  Serial.print(" \tObject Temp: "); Serial.print(MLX90614.readObjectTemp()); Serial.println(" C");
  Serial.println();
  delay(10);

  if(MLX90614.readObjectTemp()>=20.00){digitalWrite(pin5,HIGH);}
  else digitalWrite(pin5, LOW);
}





