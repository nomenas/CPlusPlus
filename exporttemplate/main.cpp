#include <iostream>
#include "container.h"
extern template class my::Container<int>;

int main() {

    my::Container<int> obj;
    std::cout << "my::Container<int> contains items of type " << obj.type() << std::endl;

    my::Container<float> obj1;
    //std::cout << "my::Container<float> contains items of type " << obj1.type() << std::endl;

    return 0;
}