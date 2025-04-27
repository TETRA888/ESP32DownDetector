#include "ServerStatusGraphics.hpp"
#include "WebsiteExtraction.hpp"
const unsigned long long DAY = 86400000;
static volatile unsigned long long previousupdate = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/*
  Available functions programmed
  printOnlineStatus()
  printOfflineStatus()
  drawWebsiteLogo()
  drawScrollingHeart()
  printCredits()
  setupDisplay()
*/

bool websiteOnline = false;

void setup(){
  setupDisplay();
  //drawWebsiteLogo();
  EstablishWifiConnect();
  websiteOnline = SendRequestToServer();
  display.clearDisplay();
}

void loop(){
  drawWebsiteLogo();

  if(websiteOnline){
    printOnlineStatus();
  }
  else{
    printOfflineStatus();
  }
  delay(1000*60*60*12); // Delay for 12 hours

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,8);       
  display.println(F("ESP going into deep sleep"));
  display.display();
  delay(5000);
  esp_sleep_enable_timer_wakeup(DAY);
  esp_deep_sleep_start();
  websiteOnline = SendRequestToServer();
}