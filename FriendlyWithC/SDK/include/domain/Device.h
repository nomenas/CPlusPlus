//
// Created by Naum Puroski on 15/10/2016.
//

#ifndef FRIENDLYWITHC_DEVICE_H
#define FRIENDLYWITHC_DEVICE_H

#include <string>

#include <core/Object.h>
#include <core/Property.h>

class Connection;

class Device : public Object {
public:
    enum Event {
        Connected = Object::Domain,
        Disconnected
    };

    enum PropertyID {
        Name,
        ReadOnly
    };

    virtual bool connect() = 0;
    virtual bool disconnect() = 0;

    Property<std::string> name{this, Name, ""};
    Property<std::string, true> readOnly{this, ReadOnly, ""};
};

#endif //FRIENDLYWITHC_DEVICE_H
