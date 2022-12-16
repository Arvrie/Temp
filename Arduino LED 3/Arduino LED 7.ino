#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include "WaveShare_MLX90614.h"

#define LED_PIN    6
#define LED_COUNT 144
#define DELAYVAL 50

float Temp = 0;
int Temp_map=0;
int old_temp_map=0;
//int fadeAmount = 5; 

WaveShare_MLX90614   MLX90614 = WaveShare_MLX90614();
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(10); // Set BRIGHTNESS to about 1/5 (max = 255)
  MLX90614.begin(); 
}

void loop() {
  strip.clear();

  Temp = MLX90614.readObjectTemp();
  old_temp_map = Temp_map;
  Temp_map = map(Temp*10,180, 360, 0, LED_COUNT );
  if (old_temp_map > Temp_map){
    while (old_temp_map > Temp_map) {
    strip.clear();
    strip.fill(strip.Color(255,0,0,0),0,old_temp_map-1);
    strip.show();
    old_temp_map--;
    delay(5);
  }
  }
  else if (old_temp_map < Temp_map){
    while (old_temp_map < Temp_map) {
    strip.clear();
    strip.fill(strip.Color(255,0,0,0),0,old_temp_map-1);
    strip.show();
    old_temp_map++;
    delay(5);
  }
  }
  else {
    strip.clear();
    strip.fill(strip.Color(255,0,0,0),0,old_temp_map-1);
    strip.show();
  }

// Serial.print(" \tObject Temp: "); Serial.print(MLX90614.readObjectTemp()); Serial.println(" C");
//Serial.println();

}





