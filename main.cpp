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

    std::cout << "Router connections: " << parser.getRouterConnections() << std::endl;


   return 0;
}