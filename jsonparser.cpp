#include "jsonparser.h"

JSONParser::JSONParser(const char* path) {
    // TODO
    this->path = path;
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

bool JSONParser::isRouterConnectionEnabled() {
    JsonObject router_connection = doc["router_connection"];
    bool router_enabled = router_connection["enabled"];
    return router_enabled;
}
const char* JSONParser::getRouterSSID(){
    JsonObject router_connection = doc["router_connection"];
    const char* wifi_name = router_connection["wifi_name"];
    return wifi_name;
}

const char* JSONParser::getRouterPassword(){
    JsonObject router_connection = doc["router_connection"];
    const char* password = router_connection["password"];
    return password;
}

bool JSONParser::isControllerConnected() {
    JsonObject controller_connection = doc["controller_connection"];
    bool controller_connected = controller_connection["enabled"];
    return controller_connected;
}
const char* JSONParser::getControllerName(){
    JsonObject controller_connection = doc["controller_connection"];
    const char* name = controller_connection["name"];
    return name;
}

int JSONParser::getNumberOfStripes() {
    JsonArray stripes = doc["stripes"];
    int index = 0;
    for(JsonObject stripe : stripes) {
        index++;
    }
    return index;
}

int JSONParser::getNumberOfLeskConnections(){
    JsonArray connections = doc["lesk_connections"];
    int index = 0;
    for(JsonObject c : connections) {
        index++;
    }
    return index;
}


void JSONParser::setEffectNumber(int effectNumber) {
    this->doc["effect"] = effectNumber;
    // Need to think of the use of this function as we don't necessarily want to
    // write on the file everytime something happen
    // Wich means we might need to make doc static and public
    writeOnDoc(this->path);
}

void JSONParser::setBrightness(int brightness) {
    this->doc["brightness"] = brightness;
    writeOnDoc(this->path);
}

void JSONParser::setSpeed(int speed) {
    this->doc["speed"] = speed;
    writeOnDoc(this->path);
}

void JSONParser::setPalette(const char* palette) {
    this->doc["palette"] = palette;
    writeOnDoc(this->path);
}

void JSONParser::setActivated(bool activated) {
    this->doc["activated"] = activated;
    writeOnDoc(this->path);
}

void JSONParser::setTransition(int transition) {
    this->doc["transition"] = transition;
    writeOnDoc(this->path);
}

void JSONParser::setPlaylist(const char* playlist) {
    this->doc["playlist_playing"] = playlist;
    writeOnDoc(this->path);
}

void JSONParser::setRouterConnectionEnabled(bool enabled) {
    JsonObject router_connection = doc["router_connection"];
    if (router_connection["enabled"] != enabled)
        router_connection["enabled"] = enabled;
    writeOnDoc(this->path);
}

void JSONParser::setRouterSSID(const char* ssid) {
    JsonObject router_connection = doc["router_connection"];
    if (strcmp(router_connection["wifi_name"], ssid) != 0)
        router_connection["wifi_name"] = ssid;
    writeOnDoc(this->path);
}

void JSONParser::setRouterPassword(const char* password) {
    JsonObject router_connection = doc["router_connection"];
    if (strcmp(router_connection["password"], password) != 0)
        router_connection["password"] = password;
    writeOnDoc(this->path);

}

void JSONParser::setControllerConnectionEnabled(bool enabled) {
    JsonObject controller_connection = doc["controller_connection"];
    if (controller_connection["enabled"] != enabled)
        controller_connection["enabled"] = enabled;
    writeOnDoc(this->path);

}
void JSONParser::setControllerName(const char* name) {
    JsonObject controller_connection = doc["controller_connection"];
    if (strcmp(controller_connection["name"], name) != 0)
        controller_connection["name"] = name;
    writeOnDoc(this->path);

}

void JSONParser::writeOnDoc(const char* path) {

    int size = measureJson(this->doc);
    printf("size of JSON: %d\n", size);
    char* buffer = (char*) malloc(sizeof(char) * size + 1);
    serializeJson(this->doc, buffer, size + 1);
    buffer[size] = '\0';


    FILE* file = fopen(path, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    fputs(buffer, file);
    fclose(file);
}