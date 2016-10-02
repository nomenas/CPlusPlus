//
// Created by Naum Puroski on 10/2/16.
//

#ifndef EXPORTTEMPLATE_FOO_H
#define EXPORTTEMPLATE_FOO_H

struct Foo {

    Foo(int value) : m_value(value) {}

    Foo(Foo&& obj) {
        m_value = obj.m_value;
        obj.m_value = 0;
    }

    Foo(const Foo&) = default;
    Foo& operator=(const Foo&) = default;

    Foo& operator=(Foo&& obj) {
        if (this != &obj) {
            m_value = obj.m_value;
            obj.m_value = 0;
        }
        return *this;
    }

    int m_value = 0;
};

#endif //EXPORTTEMPLATE_FOO_H
