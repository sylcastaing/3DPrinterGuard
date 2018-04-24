#include "GuardDisplay.h"

Adafruit_SSD1306 display(4);

GuardDisplay::GuardDisplay() {

}

void GuardDisplay::displayTemperature(float temperature) {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(20,20);
  display.print(temperature);
  display.display();
}