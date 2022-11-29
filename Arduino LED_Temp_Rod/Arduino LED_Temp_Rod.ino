#include <Wire.h>
#include "WaveShare_MLX90614.h"

WaveShare_MLX90614   MLX90614 = WaveShare_MLX90614();
int pin2 = 2;
int pin3 = 3;
int pin4 = 4;


void setup() {
  
  Serial.begin(115200);
  MLX90614.begin();  
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  
}

void loop() {
  
  //Serial.print("Ambient Temp: "); Serial.print(MLX90614.readAmbientTemp()); Serial.print(" C");
  Serial.print(" \tObject Temp: "); Serial.print(MLX90614.readObjectTemp()); Serial.println(" C");
  Serial.println();
  delay(500);

  if(MLX90614.readObjectTemp()>=23.00){digitalWrite(pin2,HIGH);}
  else digitalWrite(pin2, LOW);
  if(MLX90614.readObjectTemp()>=26.00){digitalWrite(pin3,HIGH);}
  else digitalWrite(pin3, LOW);
  if(MLX90614.readObjectTemp()>=30.00){digitalWrite(pin4,HIGH);}
  else digitalWrite(pin4, LOW);


  
}
