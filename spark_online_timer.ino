#include "Adafruit_ssd1306syp.h"

#define SDA_PIN 0
#define SCL_PIN 1
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);
void setup()
{
  delay(1000);
  display.initialize();
}
void loop()
{
  display.clear();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Online timer!!");
  display.update();
  delay(2000);
  display.clear();
}
