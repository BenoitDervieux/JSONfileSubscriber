#include <iostream>
#include <ArduinoJson.h>
#include "jsonparser.h"

int main() {


    JSONParser parser = JSONParser("config.json");
    std::cout << "Brightness: " << parser.getBrightness() << std::endl;
    std::cout << "Effect: " << parser.getEffectNumber() << std::endl;
    std::cout << "Speed: " << parser.getSpeed() << std::endl;
    std::cout << "Palette: " << parser.getPalette() << std::endl;
    std::cout << "Activated: " << parser.getActivated() << std::endl;
    std::cout << "Transition: " << parser.getTransition() << std::endl;
    std::cout << "Playlist: " << parser.getPlaylist() << std::endl;
    std::cout << "Connection Enabled : " << parser.isRouterConnectionEnabled() << std::endl;
    std::cout << "Router SSID : " << parser.getRouterSSID() << std::endl;
    std::cout << "Router password : " << parser.getRouterPassword() << std::endl;
    std::cout << "Is controller connected : " << parser.isControllerConnected() << std::endl;
    std::cout << "Name controller : " << parser.getControllerName() << std::endl;
    std::cout << "Nunber of stripes : " << parser.getNumberOfStripes() << std::endl;
    std::cout << "Number of lesk connections : " << parser.getNumberOfLeskConnections() << std::endl;

    parser.setEffectNumber(1);

   return 0;
}