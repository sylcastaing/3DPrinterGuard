#ifndef GuardDisplay_h
#define GuardDisplay_h

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class GuardDisplay {

  public:
    GuardDisplay();
    void displayTemperature(float temperature);

};

#endif
