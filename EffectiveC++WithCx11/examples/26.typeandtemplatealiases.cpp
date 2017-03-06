#include <iostream>

using OtherType = long;

template <typename First, typename Second, int Third>
class SomeType {};

//template <typename Second>
//typedef SomeType<OtherType, Second, 5> TypedefName; // Illegal

template <typename Second>
using TypedefName = SomeType<OtherType, Second, 5>;

typedef void (*FunctionType)(double);       // Old style
using FunctionType = void (*)(double); // New introduced syntax

void test(double) {}

int main()
{
    OtherType foo = 5;
    FunctionType funct = test;
    TypedefName<int> obj;

    return 0;
}
