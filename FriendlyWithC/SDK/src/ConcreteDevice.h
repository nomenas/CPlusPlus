//
// Created by Naum Puroski on 15/10/2016.
//

#ifndef FRIENDLYWITHC_CONCRETEDEVICE_H
#define FRIENDLYWITHC_CONCRETEDEVICE_H

#include <Device.h>
#include <Connection.h>

class ConcreteDevice : public Device {
public:
    explicit ConcreteDevice(const std::string& ip, unsigned short port);

    const std::string& ip() const override;
    unsigned short port() const override;
    const std::vector<std::unique_ptr<Connection>>& connections() const override;

private:
    std::string m_ip;
    unsigned short m_port;
    std::vector<std::unique_ptr<Connection>> m_connections;
};


#endif //FRIENDLYWITHC_CONCRETEDEVICE_H
