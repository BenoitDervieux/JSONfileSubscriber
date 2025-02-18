#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <iostream>
#include <ArduinoJson.h>
#include "SPIFFS.h"
#include "parserSubjectInterface.h"
#include <list>
#include <string>


class JSONParser : public ParserSubjectInterface {

    public:
        // Pattern implementation
        void Add(SubscriberInterface* sub) override {
            _subs.push_back(sub);
        }

        void Remove(SubscriberInterface* sub) override {
            _subs.remove(sub);
        }

        void Notify() override {
            if (_subs.empty()) {
                return;
            }
            std::list<SubscriberInterface*>::iterator it = _subs.begin();
            while (it != _subs.end()) {
                (*it)->Update(_latest_message);
                it++;
            }
        }
        void AdvanceAndUpdateAll();

        // Normal implementation
        JSONParser();

        void setup(const char* path);

        void printDoc();

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
        void increaseEffectNumber();
        void decreaseEffectNumber();
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
        void writeOnDoc(const char* path) const;
        JsonDocument doc;
        const char * path;


        std::list<SubscriberInterface*> _subs;
        std::string _latest_message;

};

#endif
