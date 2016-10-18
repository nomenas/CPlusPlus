#include <iostream>

#include "../ObjectLibrary/FooObject.h"

int main() {
    FooObject foo;
    std::cout << foo.sayHello() << std::endl;
    return 0;
}