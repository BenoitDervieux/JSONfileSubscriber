#include <Arduino.h>
#include <ArduinoJson.h>
#include "jsonparser.h"
#include "ESPAsyncWebServer.h"
#include "../.variables/variables.h" //Modify path according to your need
#include "systemExample.h"

const char* ssid; 
const char* password;

AsyncWebServer server(80);
JSONParser parser = JSONParser();
SystemExample systemExample;



void setup() {
  Serial.begin(9600);
  parser.setup("/config.json");
  parser.Add(&systemExample);
  // JSONParser parser = JSONParser("/config.json");

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
  
  server.on("/", HTTP_POST, [](AsyncWebServerRequest *request){
        Serial.println("Received POST request");
        Serial.println(request->args());
        int params = request->params();
        for(int i = 0; i < params; i++){
            AsyncWebParameter* p = request->getParam(i);
            Serial.print("POST ");
            Serial.print(p->name());
            Serial.print(": ");
            Serial.println(p->value());
            if(strcmp(p->value().c_str(), "effectPlusPlus") == 0) {
                parser.increaseEffectNumber();
            }
            if(strcmp(p->value().c_str(), "effectMoinsMoins") == 0) {
                parser.decreaseEffectNumber();
            }
        }
        request->send(200, "text/plain", "Effect supposed to change ");
    });


  // Start server
  server.begin();
 
}

void loop() {
  // put your main code here, to run repeatedly:
}
