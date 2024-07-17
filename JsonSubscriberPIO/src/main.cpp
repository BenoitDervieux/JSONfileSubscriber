#include <Arduino.h>
#include <ArduinoJson.h>
#include "jsonparser.h"
#include "ESPAsyncWebServer.h"



#include "../.variables/variables.h" //Modify path according to your need
// #include "putvariables.h"

const char* ssid; 
const char* password;

AsyncWebServer server(80);

void setup() {

  Serial.begin(9600);

  const char* ssid = SSID; //Enter your WiFi Name here
  const char* password = SSID_PASSWORD; // Enter your WiFi Password here

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });
  
  // Route to load style.css file
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css", "text/css");
  });

  JSONParser parser = JSONParser("config.json");
 
}

void loop() {
  // put your main code here, to run repeatedly:
}
