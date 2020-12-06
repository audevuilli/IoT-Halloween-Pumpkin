/*   Project: Halloween Pumpkin IoT Lights 
 *  :Author: Aude Vuilliomenet - GardenofThings
 *  :Date: 26/10/2020
 *  :License: Public Domain
 *  :Thanks to: Other IoT Open Projects -   
      "Bright Ball IoT" by Tiziano Bianchettin, 
      "WifiRTC & Sleep RTC Alarm" by Arturo Guadalupi   
*/

#include <SPI.h> // Library to communicate with SPI devices.
#include <WiFi101.h> // Library to connect Arduino MKR1000 to the Internet through WiFi.
#include <BlynkSimpleMKR1000.h>
#include <Adafruit_NeoPixel.h> // Library to control NeoPixel.

/***    Connect Arduino to WiFi and Blynk App    ***/
#include "auth_password.h"
int status = WL_IDLE_STATUS; // Check Wifi Status

/***    Defind NeoPixel Object    ***/
#define LED_PIN 4
#define LED_COUNT 12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
/***    Add Separated Tab - Color LEDs    ***/
#include "color_LEDs.h"


/*** ---- ARDUINO SETUP FUNCTION ---- ***/
void setup() { 
  Serial.begin(9600); 
  delay(1500); 
 
  /*** Check Wifi Status ***/
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  } 
  // Try to connect to WiFi network:
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network.
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }

  // Connection work. Print out the Wifi status.
  printWiFiStatus();
  
  /*** Blynk App Connection ***/
  Blynk.begin(auth, ssid, pass);

  /*** NeoPixel Initialise ***/
  pixels.begin();
  pixels.setBrightness(60);
  pixels.show(); // Initialize all pixels to 'off'
  Serial.print("LED Init.");
}

/*** ---- ARDUINO SETUP FUNCTION ---- ***/
void loop() {
    
    /*** Run Blynk App ***/
    Blynk.run();                     
    delay(100);
}


/*** Blynk - Connect to VirtualPin - Call Function ***/
BLYNK_WRITE(V1) {
  rainbow(20); }

BLYNK_WRITE(V2) {
  Harlequin(); } 

BLYNK_WRITE(V3) {
  RazzleDazzleRose(); }

BLYNK_WRITE(V4) {
  Pumpkin(); }

BLYNK_WRITE(V5) {
  VividSky(); }

BLYNK_WRITE(V6) {
  TwinkleRandom(50,5); }

/*** Wifi Status Function ***/
void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
