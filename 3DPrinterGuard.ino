#include "GuardDisplay.h"
#include "GuardTemperature.h"

GuardDisplay guardDisplay;
GuardTemperature guardTemperature;

void setup() {

}

void loop() {
  float temp;

  if (guardTemperature.getTemperature(&temp)) {
    guardDisplay.displayTemperature(temp);
  }
}

