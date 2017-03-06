#include <iostream>

template <class T>
std::string copy(T&& value)
{
    return std::forward<T>(value);
}

int main()
{
    std::string str = "Hello";

    // lvalue object
    {
        std::string strcopy = copy(str);
        std::cout << "After copy, str is \"" << str << "\" str copy is \"" + strcopy + "\"\n";
    }

    // rvalue object
    {
        std::string strcopy = copy(std::move(str));
        std::cout << "After copy, str is \"" << str << "\" str copy is \"" + strcopy + "\"\n";
    }
}
