//
// Created by Naum Puroski on 06/04/2017.
//

#ifndef EXPORTTEMPLATE_PIMPL_H
#define EXPORTTEMPLATE_PIMPL_H

#include <memory>

struct Priv {
    virtual ~Priv() = default;
};

template <typename T>
struct Pimpl {
    Pimpl();

    int method1() const;
    int method2() const;

    std::shared_ptr<Priv> _priv;
};




#endif //EXPORTTEMPLATE_PIMPL_H
