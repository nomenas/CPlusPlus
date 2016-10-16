//
// Created by Naum Puroski on 16/10/2016.
//

#ifndef FRIENDLYWITHC_PROPERTY_H
#define FRIENDLYWITHC_PROPERTY_H

#include "Object.h"

template <class T, bool ReadOnly = false>
class Property {
public:
    Property(Object* object, int id, const T& value)
            : m_object(object)
            , m_id(id)
            , m_value(value) {}

    operator const T& () const {
        return m_value;
    }

    Property<T>& operator=(const T& value) {
        if (m_value != value) {
            m_value = value;
            m_object->notify(Object::PropertyChanged, m_id, nullptr);
        }
        return *this;
    }

    const T& value() const {
        return m_value;
    }

private:
    Object* m_object;
    int m_id;
    T m_value;
};

template <typename T>
class Property<T, true> {
    friend class Object;
public:
    Property(Object* object, int id, const T& value)
            : m_object(object)
            , m_id(id)
            , m_value(value) {}

    operator const T& () const {
        return m_value;
    }

    const T& value() const {
        return m_value;
    }

private:
    Property<T, true>& operator=(const T& value) {
        if (m_value != value) {
            m_value = value;
            m_object->notify(Object::PropertyChanged, m_id, nullptr);
        }
        return *this;
    }

    Object* m_object;
    int m_id;
    T m_value;
};

#endif //FRIENDLYWITHC_PROPERTY_H
