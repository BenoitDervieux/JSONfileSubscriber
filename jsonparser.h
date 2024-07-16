#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <iostream>
#include <ArduinoJson.h>


class JSONParser {

    public:
        JSONParser(const char* file);

        // char* getEffectName();
        int getEffectNumber();
        int getBrightness();
        int getSpeed();
        const char* getPalette();
        bool getActivated();
        int getTransition();
        const char* getPlaylist();

        const char* getRouterConnections();



    
    private:
        JsonDocument doc;

};

#endif

    // "stripes": [
    //     {
    //         "length": 10,
    //         "direction": 1
    //     },
    //     {
    //         "length": 10,
    //         "direction": 1
    //     }
    // ],
    // "lesk_connections": [
    //     {
    //         "name": "lesk 2"
    //     },
    //     {
    //         "name": "lesk 3"
    //     },
    //     {
    //         "name": "lesk 4"
    //     },
    //     {
    //         "name": "lesk 5"
    //     }
    // ],
    // "router_connection": {
    //     "enabled": true,
    //     "wifi_name": "test",
    //     "password": "test"
    // },
    // "controller_connection": {
    //     "enabled": false
    // }