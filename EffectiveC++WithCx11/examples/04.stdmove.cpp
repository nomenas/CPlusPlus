#include <iostream>
#include <string>

int main()
{
    std::string str = "Hello";

    // copy object
    {
        std::string strcopy = str;
        std::cout << "After copy, str is \"" << str << "\" str copy is \"" + strcopy + "\"\n";
    }

    // move object
    {
        std::string strcopy = std::move(str);
        std::cout << "After copy, str is \"" << str << "\" str copy is \"" + strcopy + "\"\n";
    }
}
