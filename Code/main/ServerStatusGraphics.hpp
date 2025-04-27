#ifndef SERVER_STATUS_GRAPHICS_HPP
#define SERVER_STATUS_GRAPHICS_HPP

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

extern Adafruit_SSD1306 display;

void printOnlineStatus();
void printOfflineStatus();
void drawWebsiteLogo();
void drawScrollingHeart();
void printCredits();
void setupDisplay();

#endif