//
// Created by Naum Puroski on 15/10/2016.
//

#ifndef FRIENDLYWITHC_DEVICE_H
#define FRIENDLYWITHC_DEVICE_H

#include <string>
#include <vector>
#include <memory>

#include "Object.h"
#include "Factory.h"

class Connection;

class Device : public Object {
public:
    virtual const std::string& ip() const = 0;
    virtual unsigned short port() const = 0;
    virtual const std::vector<std::unique_ptr<Connection>>& connections() const = 0;

    struct Config {
        std::string ip;
        unsigned short port;
    };
};

using DeviceFactory = Factory<Device, Device::Config>;

#endif //FRIENDLYWITHC_DEVICE_H
