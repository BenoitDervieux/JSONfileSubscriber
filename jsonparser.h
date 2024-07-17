#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <iostream>
#include <ArduinoJson.h>


class JSONParser {

    public:
        JSONParser(const char* path);

        // The get methods
        int getEffectNumber();
        int getBrightness();
        int getSpeed();
        const char* getPalette();
        bool getActivated();
        int getTransition();
        const char* getPlaylist();

        bool isRouterConnectionEnabled();
        const char* getRouterSSID();
        const char* getRouterPassword();

        bool isControllerConnected();
        const char* getControllerName();

        int getNumberOfStripes();
        int getNumberOfLeskConnections();


        // The set methods
        // Set single values
        void setEffectNumber(int effectNumber);
        void setBrightness(int brightness);
        void setSpeed(int speed);
        void setPalette(const char* palette);
        void setActivated(bool activated);
        void setTransition(int transition);
        void setPlaylist(const char* playlist);

        void setRouterConnectionEnabled(bool enabled);
        void setRouterSSID(const char* ssid);
        void setRouterPassword(const char* password);

        void setControllerConnectionEnabled(bool enabled);
        void setControllerName(const char* name);

        // Set multiple values


        

    
    private:
        // Need to change depending on the way of writing to a file
        void writeOnDoc(const char* path);
        JsonDocument doc;
        const char * path;

};

#endif
