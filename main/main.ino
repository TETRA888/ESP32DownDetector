#include "ServerStatusGraphics.hpp"
#include "WebsiteExtraction.hpp"
#include <math.h>

/*
  Down detector is a program written by TETRA888 for his current gf
  - It checks if her server is online 
  - Has a deep sleep mode
  - Prints out hearts
*/

/*
  Available functions programmed in ServerStatusGraphics.cpp
  printOnlineStatus()
  printOfflineStatus()
  drawWebsiteLogo()
  drawScrollingHeart()
  printCredits()
  setupDisplay()

  Avilable functions programmed in WebsiteExtraction.cpp
  EstablishWifiConnect()
  SendRequestToServer()
*/

/*
  Global variables
*/
static volatile bool IsWebsiteOnline = false;
static volatile bool touchDetected = false;
static volatile bool touchDetected2 = false;
static volatile bool touchDetected3 = false;

/*
  Function declarations
*/
void DeepSleepSequence();
void proceduralHearts(int offset);
void touched();
void touched2();
void touched3();

/*
  Setup function where we enable the interrupts, pins, display, and wifi connection

  @param None
  @return None
*/
void setup(){
  touchSleepWakeUpEnable(4, 30); // Enable wake up by touch  on pin 4 to exit deep sleep mode
  touchAttachInterrupt(33, touched, 20); // Interrupt on pin 33
  touchAttachInterrupt(27, touched2, 20); // Interrupt on pin 27
  touchAttachInterrupt(32, touched3, 20); // Interrupt on pin 32
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  setupDisplay();
  EstablishWifiConnect();
  IsWebsiteOnline = SendRequestToServer();
  display.clearDisplay();
}

void loop(){
  /*
    Parametric heart sequence
  */
  if (touchDetected){
    touchDetected = false;
    display.clearDisplay();
    proceduralHearts(32, 1);
    proceduralHearts(64, -1);
    proceduralHearts(96, 1);
    delay(2000);
    digitalWrite(2, LOW);
    display.clearDisplay();
    touchDetected = false;
  }

  /*
    None Optimized Heart
  */
  if(touchDetected3){
    drawScrollingHeart();
    display.clearDisplay();
    touchDetected3 = false;
  }

  /*
    Sleep Sequence
  */
  if(touchDetected2){
    display.clearDisplay();
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(8,24);       
    display.println(F("Deep Sleep"));
    display.display();
    delay(1000);
    touchDetected2 = false;
    esp_deep_sleep_start();
  }

  /*
    Default standby wallpaper
  */
  drawWebsiteLogo();
  if(IsWebsiteOnline){
    printOnlineStatus();
  }
  else{
    printOfflineStatus();
  }
}

/*
  Interrupt function 1
  @param None
  @return None
*/
void touched(){
  touchDetected = true;
}

/*
  Interrupt function 2
  @param None
  @return None
*/
void touched2(){
  touchDetected2 = true;
}

/*
  Interrupt function 3
  @param None
  @return None
*/
void touched3(){
  touchDetected3 = true;
}

/*
  From https://mathworld.wolfram.com/HeartCurve.html
  I found the following parametric equations that give a really cute looking heart
  X = 16(sin(t))^3
  Y = 13cos(t) - 5cos(2t) - 2cos(3t) - cos(4t)

  In order to generate a cool procedural patterns, we could adjust the t parameter randomly based
  on the temperature obtained from the ESP32 double double format for true randomness

  It turns out that I cannot include a randomness factor because that somehow messes up the interrupts
  on the ESP32

  @param offset is the X offset for the heart location, flip: set to 1 for a flipped heart or -1 for a non flipped heart
  @return None
*/
void proceduralHearts(int offset, int flip){
  for(int i = 0; i < 64; i++){
    digitalWrite(2, HIGH);
    int XCoordinate = (int)(16*(pow(sin(i),3))) % 64;
    int YCoordinate = flip*(int)(13*cos(i) - 5*cos(2*i) - 2*cos(3*i) - cos(4*i)) % 64;
    display.drawPixel(XCoordinate + offset, YCoordinate + 32, SSD1306_WHITE);
    digitalWrite(2, LOW);
    display.display();
  }
}