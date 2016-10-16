//
// Created by Naum Puroski on 16/10/2016.
//

#include <functional>
#include "ConcreteDevice.h"

struct ConcreteDeviceFactory {
    ConcreteDeviceFactory() {
        DeviceFactory::SetFactory([](const Device::Config& config) -> Device* {
            return (config.port && !config.ip.empty()) ?
                new ConcreteDevice(config.ip, config.port) : nullptr;
        });
    }
    ~ConcreteDeviceFactory() {
        DeviceFactory::SetFactory(nullptr);
    }
};

static const ConcreteDeviceFactory _concreteDeviceFactory;