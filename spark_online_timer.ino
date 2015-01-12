#include "Adafruit_ssd1306syp.h"
#include "TimeAlarms.h"

#define SDA_PIN 0
#define SCL_PIN 1
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);

int timerPointer = 0;
int timerCounter = 0;
bool timerActive = false;
int timerSecs[4] = {120,60,30,15};
char timerTitles[4][16] = {"Timer1", "Timer2", "Timer3", "Timer4"};


void setup()
{
  Time.zone(-4);
  Serial.begin(9600);
  delay(1000);
  display.initialize();
  Alarm.timerRepeat(1, Tick);
  timerPointer = 1;
  timerCounter = timerSecs[timerPointer];
  WelcomeScreen();
  delay(5000);
  timerActive = true;
}
void loop()
{
  Alarm.delay(1000);

}

void StartTimer(){

}


void WelcomeScreen(){
  display.clear();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Online timer!! v7");
  display.update();
}

void Tick(){
  if(timerCounter == 0){
    timerActive = false;
  }
  if(timerActive){
    timerCounter = timerCounter - 1;
  }
  Serial.println("This timer only triggers once");
  display.clear();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(timerTitles[1]);
  display.setCursor(0,15);
  display.println(timerCounter);
  display.setCursor(0,30);
  if(timerActive){
    display.println("Activo");
  } else {
    display.println("Pausado");
  }
  display.update();
}
