#include "GuardTemperature.h"
#include <OneWire.h>

const int PIN_TEMP_EXT = 2;

OneWire ds(PIN_TEMP_EXT);

GuardTemperature::GuardTemperature() {
   
}

bool GuardTemperature::getTemperature(float *temp) {
  byte data[9], addr[8];

  if (!ds.search(addr)) {
    ds.reset_search();
    return false;
  }

  if (OneWire::crc8(addr, 7) != addr[7])
    return false;

  if (addr[0] != 0x28)
    return false;

  ds.reset();
  ds.select(addr);

  ds.write(0x44, 1);
  delay(800);
   
  ds.reset();
  ds.select(addr);
  ds.write(0xBE);
 
  for (byte i = 0; i < 9; i++)
   
  *temp = ((data[1] << 8) | data[0]) * 0.0625; 

  ds.reset_search();

  return true;
}
