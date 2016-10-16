//
// Created by Naum Puroski on 15/10/2016.
//

#ifndef FRIENDLYWITHC_OBJECT_H
#define FRIENDLYWITHC_OBJECT_H

#include <functional>

class Object {
public:
    using Delegate = std::function<void(int event, int property, void* data)>;

    enum Event {
        Created,
        Destroyed,
        DomainSpecific = 1000
    };

    virtual ~Object() {
        notify(Event::Destroyed);
    }

    void setDelegate(Delegate delegate) {
        m_delegate = delegate;
    }

protected:
    void notify(int event, int property = -1, void* data = nullptr) {
        if (m_delegate) {
            m_delegate(event, property, data);
        }
    }

private:
    Delegate m_delegate;
};

#endif //FRIENDLYWITHC_OBJECT_H
