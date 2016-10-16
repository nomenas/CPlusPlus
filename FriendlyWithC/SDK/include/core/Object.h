//
// Created by Naum Puroski on 15/10/2016.
//

#ifndef FRIENDLYWITHC_OBJECT_H
#define FRIENDLYWITHC_OBJECT_H

#include <functional>
#include <map>

class Object {
public:
    using Observer = std::function<bool(int event, int property, void* data)>;

    enum Event {
        Created,
        Destroyed,
        PropertyChanged,
        Domain = 1000
    };

    virtual ~Object() {
        notify(Event::Destroyed);
    }

    int addObserver(Observer observer) {
        m_observers.insert({m_maxObserverID, observer});
        return m_maxObserverID++;
    }

    void removeObserver(int id) {
        m_observers.erase(id);
    }

    void notify(int event, int property = -1, void* data = nullptr) {
        for (auto iter : m_observers) {
            if (!iter.second(event, property, data)) {
                break;
            }
        }
    }

protected:
    template <typename T, typename V>
    void setProperty(T& property, const V& value) {
        property = value;
    }

private:
    unsigned int m_maxObserverID = 0;
    std::map<unsigned int, Observer> m_observers;
};

#endif //FRIENDLYWITHC_OBJECT_H
