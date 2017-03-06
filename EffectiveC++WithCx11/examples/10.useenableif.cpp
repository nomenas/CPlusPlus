#include <iostream>
#include <type_traits>

class Foo {};

// 1. the return type (bool) is only valid if T is an integral type:
template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type is_odd (T i)
{
    return bool(i%2);
}

// 2. the second template argument is only valid if T is an integral type:
template < class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even (T i)
{
    return !bool(i % 2);
}

bool is_even (const Foo& foo)
{
    return false;
}

int main()
{
    short int i = 1;    // code does not compile if type of i is not integral
    Foo foo;

    // is_odd("String"); NOK it is not enabled
    std::cout << std::boolalpha;
    std::cout << "i is odd: " << is_odd(i) << std::endl;
    std::cout << "i is even: " << is_even(i) << std::endl;
    std::cout << "foo is even: " << is_even(foo) << std::endl;

    return 0;
}
