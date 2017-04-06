//
// Created by Naum Puroski on 06/04/2017.
//

#include "MyType.h"
#include "Pimpl.h"

struct MyTypeIntPriv : Priv {
    MyType<int> data = {1, 1};
};

template <typename T>
struct PrivTraits{
    using Type = T;
};

template<>
struct PrivTraits<MyType<int>> {
    using Type = MyTypeIntPriv;
};

template<typename T>
Pimpl<T>::Pimpl() : _priv{std::make_shared<typename PrivTraits<T>::Type>()}{
}

template<typename T>
int Pimpl<T>::method1() const {
    return static_cast<typename PrivTraits<T>::Type*>(_priv.get())->data.method1();
}

template<typename T>
int Pimpl<T>::method2() const {
    return static_cast<typename PrivTraits<T>::Type*>(_priv.get())->data.method2();
}

template class Pimpl<MyType<int>>;

