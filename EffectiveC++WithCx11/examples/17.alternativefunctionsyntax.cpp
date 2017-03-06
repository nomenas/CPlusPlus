#include <iostream>

/**** syntax ****/
template<class T>
auto mul(T a, T b) -> decltype(a * b)
{
    return a * b;
}

void checkSyntax()
{
    auto result = mul(2, 3);
    std::cout << "result is " << result << " from type " << typeid(result).name() << std::endl;
}


/**** improved readability ****/

int (*(*foo())())()
{
    return 0;
}

auto fooTrailing() -> auto (*)() -> int(*)()
{
    return 0;
}

typedef int(*FunctRetInt)();
typedef FunctRetInt(*FunctRetFunct)();
FunctRetFunct fooOther()
{
    return 0;
}

void checkReadability()
{
    std::cout << foo() << " " << typeid(foo()).name() << std::endl;
    std::cout << fooTrailing() << " " << typeid(fooTrailing()).name() << std::endl;
    std::cout << fooOther() << " " << typeid(fooOther()).name() << std::endl;
}

/**** check omit trailing return type (in C++14) ****/

//int x = 1;
//auto f() { return x; } // return type is int
//const auto& f() { return x; } // return type is const int&

/*** attribute specifier sequence ****/

[[ noreturn ]] void testNoReturn()
{
//    return;
//    throw "error";
}

int main()
{
    checkSyntax();
    checkReadability();

    return 0;
}
