//
// Created by Naum Puroski on 31/03/2017.
//

#ifndef EXPORTTEMPLATE_MYTYPE2_H_H
#define EXPORTTEMPLATE_MYTYPE2_H_H

#include "api.h"

template <typename T>
struct MyType {
    T _value;

    int method1() const {
        return 2;
    }

    // just defined, it should be loaded from library
    int method2() const;
};

extern template class API MyType<int>;

#endif //EXPORTTEMPLATE_MYTYPE2_H_H
