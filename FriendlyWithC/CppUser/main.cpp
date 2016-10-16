//
// Created by Naum Puroski on 15/10/2016.
//
#include <iostream>

#include <Device.h>

int main() {
    auto deviceDelegate = [](int event, int property, void* data) {
        std::cout << "Event received: " << event << ", property = " << property << ", data = " << (long) data << std::endl;
    };
    // test creation of device object with valid configuration
    std::unique_ptr<Device> device{DeviceFactory::Create(Device::Config{"192.168.1.100", 50}, deviceDelegate)};
    std::cout << "successfully created device listening on " << device->ip() << ":" << device->port() << std::endl;

    // test creation of device object with invalid object
    std::unique_ptr<Device> invalidDevice{DeviceFactory::Create(Device::Config{}, deviceDelegate)};
    std::cout << "this pointer should be null becouse it is created with not valid parameters " << (long) invalidDevice.get() << std::endl;

    return 0;
}