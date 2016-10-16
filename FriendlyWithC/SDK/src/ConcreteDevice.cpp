//
// Created by Naum Puroski on 15/10/2016.
//

#include "ConcreteDevice.h"


ConcreteDevice::ConcreteDevice(const std::string& ip, unsigned short port)
 : m_ip(ip)
 , m_port(port) {

}

const std::string& ConcreteDevice::ip() const {
    return m_ip;
}

unsigned short ConcreteDevice::port() const {
    return m_port;
}

const std::vector<std::unique_ptr<Connection>>& ConcreteDevice::connections() const {
    return m_connections;
}