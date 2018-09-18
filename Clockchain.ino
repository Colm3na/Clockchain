/*
 *  Colmena's Clock-chain
 * 
 *  13/9/18
*/

// Screen libaries
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include "Secrets.h"

// Wifi Libraries
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>// To connect throught HTTP
#include <ArduinoJson.h>      // To handle the Json

// Other libraries
#include <stdlib.h>           // To convert hex strings to int
#include <time.h>             // To handle time and date variables

// Display definitions
#define PINCS D2              // CS (chip select) pin
#define HDISPS 4              // Number of horizontal displays
#define VDISPS 4              // Number of vertical displays
#define spacer 1              // Space between letters
#define brightness 5          // Choose a number between 0 and 15
#define WAIT 40               // Step (ms) for block number scrolling. 0 is fastest.

// Get the configuration from "Secrets.h"
const char* ssid  = SECRET_SSID;
const char* password = SECRET_PASS;
const char* blockURL = BLOCKURL;

unsigned long int blockNumber = 0;

Max72xxPanel matrix = Max72xxPanel(PINCS, HDISPS, VDISPS);

void setup() {
  // Display setup
  matrix.setIntensity(brightness);
  // Adjust the rotation for our module
  for(int i=0; i<16; i++)
  {
    matrix.setRotation(i, 1);
  }

  // Wifi setup
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)  {
    scrollText(((matrix.height() - 8) / 2),10,"Connecting...");
  }
  matrix.fillScreen(LOW);
  scrollText(0,10,"Connected!");

  // Date & Time setup
  scrollText(((matrix.height() - 8) / 2),20,"Getting time...");
  configTime(2 * 3600, 0, "pool.ntp.org", "time.nist.gov");  
}

void loop() {
  displayBlock(3);  // Display 3 blocks
  displayTime(5);   // Display the time for 5 seconds
}

void displayBlock(int times)
{
  matrix.fillScreen(LOW);
  drawText(8,0,"ETH");
  drawText(2,8,"Block");
  matrix.write(); 
  String blk = "";
  for(int i=0;i<times;i++)
  {
    getBlock(); // Refresh the block 
    blk = "#" + String(blockNumber);
    scrollText(20, WAIT, blk);
  }
}

void displayTime(int times)
{
  // Refresh the time
  time_t now = time(nullptr);
  struct tm * timeinfo;
  timeinfo = localtime (&now);

  // Get the strings to render
  String hour = String(timeinfo->tm_hour);
  String minute = String(timeinfo->tm_min);
  String day = String(timeinfo->tm_mday);
  String month = String(timeinfo->tm_mon + 1);
  String year = String(timeinfo->tm_year - 100); // tm_year returns the number of years since 1900

  // Adjust one-digit number to two-digits number adding a zero
  hour = (hour.length()<2)?("0"+hour):(hour);
  minute = (minute.length()<2)?("0"+minute):(minute);
  month = (month.length()<2)?("0"+month):(month);
  
  matrix.fillScreen(LOW);
  drawText(1,20,String(day+"/"+month)); // Prints date

  // Prints time with blinking dots
  for(int i=0;i<times;i++)
  {
    //matrix.setTextSize(2);
    drawText(1,4,String(hour + ":" + minute));
    matrix.write();
    delay(500);
    drawText(1,4,String(hour + " " + minute));
    matrix.write();
    delay(500);
  }
}











