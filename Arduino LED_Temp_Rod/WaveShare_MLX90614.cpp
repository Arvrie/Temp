#include "WaveShare_MLX90614.h"





WaveShare_MLX90614::WaveShare_MLX90614(uint8_t i2caddr) {
  _addr = i2caddr;
}


boolean WaveShare_MLX90614::begin(void) {
  Wire.begin();
  return true;
}


double WaveShare_MLX90614::readObjectTemp(void) {
  return readTemp(OBJECT_TEMP);
}


double WaveShare_MLX90614::readAmbientTemp(void) {
  return readTemp(AMBIENT_TEMP);
}

float WaveShare_MLX90614::readTemp(uint8_t reg) {
  float  temp;
  uint16_t  tempData;
  uint8_t   pec;
  
    
  Wire.beginTransmission(_addr); 
  Wire.write(reg); 
  Wire.endTransmission(false);  // the param must be "false" to restart the communication
  
  Wire.requestFrom(_addr, (uint8_t)3);
  tempData = Wire.read(); 
  tempData |= Wire.read() << 8; 
  pec = Wire.read();
  
  temp = tempData;
  temp *= 0.02;
  temp  -= 273.15;
  return temp;
}
