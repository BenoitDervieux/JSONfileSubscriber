#include "jsonparser.h"

JSONParser::JSONParser(const char* path) {
    // TODO
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = (char*) malloc(sizeof(char) * size + 1);
    char c;
    size=0;
    while ((c = fgetc(file)) != EOF) {
        buffer[size] = c;
        size++;
    }

    DeserializationError error = deserializeJson(this->doc, buffer);
    if (error) {
        printf("deserializeJson() failed: ");
        return ;
    }

    // Close the file (optional, but a good practice)
    fclose(file);
}

int JSONParser::getEffectNumber() {
    int effect = this->doc["effect"].as<int>();
    return effect;
}

int JSONParser::getBrightness() {
    int brightness = this->doc["brightness"].as<int>();
    return brightness;
}

int JSONParser::getSpeed() {
    int speed = this->doc["speed"].as<int>();
    return speed;
}
const char* JSONParser::getPalette() {
    const char* palette = this->doc["palette"].as<const char*>();
    return palette;
}
bool JSONParser::getActivated() {
    bool activated = this->doc["activated"].as<bool>();
    return activated;
}
int JSONParser::getTransition() {
    int transition = this->doc["transition"].as<int>();
    return transition;
}
const char* JSONParser::getPlaylist() {
    const char* playlist = this->doc["playlist_playing"].as<const char*>();
    return playlist;
}

const char* JSONParser::getRouterConnections() {
    const char* routerConnections = this->doc["router_connection"].as<const char*>();
    return routerConnections;
}