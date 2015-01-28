#include "Adafruit_ssd1306syp.h"
#include "TimeAlarms.h"

#define SDA_PIN 0
#define SCL_PIN 1
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);
int encoderPinA = D3;
int encoderPinB = D4;
int encoderBtn = D2;
int timerPointer = 0;
int timerCounter = 0;
bool timerActive = false;
int timerSecs[4] = {120,60,30,15};
char timerTitles[4][16] = {"Timer1", "Timer2", "Timer3", "Timer4"};


void setup()
{

  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);
  pinMode(encoderBtn, INPUT_PULLUP);
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
  attachInterrupt(encoderPinA, adjust_counter, FALLING);
  attachInterrupt(encoderBtn, encoderPressed, CHANGE);
}
void loop()
{
  Alarm.delay(1000);

}

void StartTimer(){

}
void encoderPressed(){
  displayText("encoder Pressed");
}

void adjust_counter(){


    if (digitalRead(encoderPinB)){
      displayText("encoder ++++");
    } else {
      displayText("encoder ----");
    }
}

void WelcomeScreen(){
  display.clear();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Online timer!! v8");
  display.update();
}

void displayText(String mytext){
  display.clear();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(mytext);
  display.update();
}

void Tick(){
  displayText("");
  /*
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
  display.update();*/
}
