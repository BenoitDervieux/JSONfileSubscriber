#ifndef SYSTEMEXAMPLE_H
#define SYSTEMEXAMPLE_H

#include <iostream>
#include "subscriberInterface.h"

class SystemExample : public SubscriberInterface {

    public:
    SystemExample() {_unique_id = ++_unique_subscribers;}
    virtual ~SystemExample() {}
    void Update(const std::string& message) override {
        std::cout << "SUBID: \"" << _unique_id << "\" received message -> " << message << std::endl;
    }
    private:
        int _unique_id = -1;
        static int _unique_subscribers;
};

int SystemExample::_unique_subscribers = 0;

#endif