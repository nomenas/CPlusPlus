#include <iostream>

void foo(char*)
{
    std::cout << "foo(char*)\n";
}

void foo(int)
{
    std::cout << "foo(int)\n";
}

int main()
{
    char *pc = nullptr;     // OK
    int  *pi = nullptr;     // OK
    bool   b = nullptr;     // OK. b is false.
//    int    i = nullptr;     // error

    foo(nullptr);           // calls foo(nullptr_t), not foo(int);
}
