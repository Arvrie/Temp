
#include <Wire.h>
#include "WaveShare_MLX90614.h"

WaveShare_MLX90614   MLX90614 = WaveShare_MLX90614();

void setup() {
  
  Serial.begin(115200);
  MLX90614.begin();  
  
}

void loop() {
  
  Serial.print("Ambient Temp: "); Serial.print(MLX90614.readAmbientTemp()); 
  Serial.print(" C\tObject Temp: "); Serial.print(MLX90614.readObjectTemp()); Serial.println(" C");
  Serial.println();
  delay(500);
  
}
