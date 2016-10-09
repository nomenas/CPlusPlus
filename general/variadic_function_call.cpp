#include <iostream>


int concreteMethod(int arg1, double arg2) {
    std::cout << "concreteMethod call" << arg1 << " " << arg2 << std::endl;
    return arg1 + arg2;
}

template <typename... Args>
int callmethod(Args&&... args) {
    return std::bind(concreteMethod, std::forward<Args>(args)...)();
}

int main() {
    std::cout << callmethod(1, 2.) << std::endl;

    return 0;
}