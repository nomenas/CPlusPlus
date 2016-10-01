#include "container.h"
#include "apitype.h"

using namespace my;

template <typename T>
const char* Container<T>::type() const {
    return typeid(T).name();
}

template class API my::Container<int>;