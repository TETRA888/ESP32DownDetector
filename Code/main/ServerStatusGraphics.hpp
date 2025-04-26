#ifndef SERVER_STATUS_GRAPHICS_HPP
#define SERVER_STATUS_GRAPHICS_HPP

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;

void printOnlineStatus();
void printOfflineStatus();
void drawWebsiteLogo();
void drawScrollingHeart();
void printCredits();
void setupDisplay();

#endif