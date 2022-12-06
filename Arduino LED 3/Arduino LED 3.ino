#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include "WaveShare_MLX90614.h"

WaveShare_MLX90614   MLX90614 = WaveShare_MLX90614();

int pin5 = 5;

#define PIN        6 
#define NUMPIXELS 72 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 50 

void setup() {

  pixels.begin(); 
  MLX90614.begin(); 
  pinMode(pin5, OUTPUT); 
}

void loop() {

pixels.clear(); // Set all pixel colors to 'off'

  for(int i=0; i<NUMPIXELS; i++) { 

    pixels.setPixelColor(i, pixels.Color(25, 25, 25));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  
  
  //Serial.print("Ambient Temp: "); Serial.print(MLX90614.readAmbientTemp()); Serial.print(" C");
  Serial.print(" \tObject Temp: "); Serial.print(MLX90614.readObjectTemp()); Serial.println(" C");
  Serial.println();
  delay(500);

  if(MLX90614.readObjectTemp()>=22.00){digitalWrite(pin5,HIGH);}
  else digitalWrite(pin5, LOW);
  
/*float T     = MLX90614.readObjectTemp();
  float Tmin  = 10;
  float Tmax  = 35;
 
  float r = 0;
  float g = 0;
  float b = 0;
   
  // Linearer Verlauf:
  // - Bei Tmin ist die Farbe nur blau
  // - Bei Tmax ist die Farbe nur rot
  // - Unter Tmin ist die Farbe weiﬂ
  // - ‹ber Tmax ist die Farbe gelb
   
  if (T < Tmin) { r = 1; g = 1; b = 1; } else if (T > Tmax) {
    r = 1;
    g = .5;
    b = 0;
  } else {
    r = (T - Tmin) / (Tmax - Tmin);
    g = 0;
    b = (T - Tmax) / (Tmin - Tmax);
  }
*/

}

}

