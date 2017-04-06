//
// Created by Naum Puroski on 31/03/2017.
//

#ifndef EXPORTTEMPLATE_MYTYPE_H
#define EXPORTTEMPLATE_MYTYPE_H

#include "api.h"

template <typename T>
struct MyType {
    T _offset;
    T _value;

    int method1() const {
        return _value;
    }

    int method2() const {
        return _value + 5;
    }
};

extern template class API MyType<int>;

#endif //EXPORTTEMPLATE_MYTYPE_H
