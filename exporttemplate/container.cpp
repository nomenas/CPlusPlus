#include "container.h"
#include "apitype.h"
#include "foo.h"

using namespace my;

template <typename T>
const char* Vector<T>::type() const {
    return typeid(T).name();
}

template class API my::Vector<int>;
template class API my::Vector<Foo>;