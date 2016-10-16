//
// Created by Naum Puroski on 15/10/2016.
//

#ifndef FRIENDLYWITHC_CONNECTION_H
#define FRIENDLYWITHC_CONNECTION_H

#include <core/Object.h>
#include <core/Property.h>

class Device;

class Connection : public Object {
    enum PropertyID {
        Port
    };

    Connection(Device* device) {}

    Property<unsigned short, true> port{this, Port, 0};
};

#endif //FRIENDLYWITHC_CONNECTION_H
