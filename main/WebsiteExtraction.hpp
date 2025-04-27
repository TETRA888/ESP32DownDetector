#ifndef WEBSITE_EXTRACTION_HPP
#define WEBSITE_EXTRACTION_HPP

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <string.h>
#include "ServerStatusGraphics.hpp"

extern Adafruit_SSD1306 display;

void EstablishWifiConnect();
bool SendRequestToServer();

#endif // WEBSITE_EXTRACTION_HPP
