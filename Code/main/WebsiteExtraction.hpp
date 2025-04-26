#ifndef WEBSITE_EXTRACTION_HPP
#define WEBSITE_EXTRACTION_HPP

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <string.h>
#include "ServerStatusGraphics.hpp"

void EstablishWifiConnect();
void SendRequestToServer();

#endif // WEBSITE_EXTRACTION_HPP
