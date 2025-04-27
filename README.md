# <div align = "center"> ` ESP 32 Server Status Detector `</div>

### Creating a simple portable down detector that you can place on your shelf to monitor your server status live!

1. The required hardware components are as follows
  - ESP 32 WROOM (Wireless Room) Development Board
  - Simple Monochrome 128x64 OLED Graphic Display
  - Wires
  - Breadboard or PCB

## Setting up the Hardware
### On the OLED connect
1.  GND -> GND
2. VDD -> 3V3
3. SCK -> D13 or D21
4. SDA -> D14 or D22

## Setting Up the Software
1. Install the ESP32 espressif systems board into the Arudino IDE by pasting the link below into the additonal boards URL (Inside the Arduino IDE go to -> File -> Preferences -> Additional boards manager URLS)
```
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```
3. In the Arduino Libarary Manager, install the additional following libraries for the display:
```
Adafruit BusIO
Adafruit GFX Library
Adafruit SSD 1306 
```
2. Clone the repository
```bash
$ git clone https://github.com/TETRA888/Profilometer.git
$ cd Profilometer
```
2. Open the WebsiteExtraction.cpp file using Arduino and change the following parameters
```c++
const char* ssid = "XXXX"; // Your Wifi SSID

const char* password = "XXXX"; // Your Wifi Password

const char*  server = "XXXX.com";  // Server URL

const char* Jaysa_Root_CA = \
"-----BEGIN CERTIFICATE-----\n" \
" Your certificate "
"-----END CERTIFICATE-----\n";

client.println("GET https://blog.jaysa.net/ HTTP/1.1");
client.println("Host: blog.jaysa.net");
```
4. Connect and Upload it to your ESP 32 

5. Next to make the display more visually appealing include the website icon/favicon/logo

## Converting the website logo into a Xbitmap using GIMP
![image](https://github.com/user-attachments/assets/0ccf18a0-7d0a-41d5-9bee-53ce1166b987)
![image](https://github.com/user-attachments/assets/247fc7ff-2364-4bc6-86be-90f9761bbfc7)

### After refining the raw Xbitmap with GIMP and down scaling it to fix onto the 128x64 pixel display I get something like this:
![image](https://github.com/user-attachments/assets/504ba6d7-181e-454e-8082-d2c6c1363dd3)

### Rendering it on the monochrome display yields the following result:
![image](https://github.com/user-attachments/assets/e76d8206-620f-41c5-989f-af7a30287563)

## Including a custom Xbitmap
### Paste your custom Xbitmap in the following array
```c++
static const unsigned char PROGMEM web_xbmp[]{...}
```
# Final Result
![image](https://github.com/user-attachments/assets/eba61323-a466-4cea-b53b-1da81a691251)
