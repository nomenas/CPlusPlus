#include <iostream>

template <class T>
void doSomethingAdditional(T&& param)
{
    T obj = std::forward<T>(param);
}

template <class T>
void doSomething(T&& param)
{
    doSomethingAdditional(std::move(param));
}

void doSomethingAdditionalWithRReference(std::string&& value)
{
    std::string obj = std::move(value);
}

void doSomethingWithRReference(std::string&& value)
{
    doSomethingAdditionalWithRReference(std::move(value));
}

int main()
{
    // check forward problem
    {
        std::string arg = "test";
        doSomething(arg);
        std::cout << "value now is " << arg << std::endl;
    }

    // check move problem
    {
        std::string arg = "test";
        doSomethingWithRReference(std::move(arg));
        std::cout << "value now is " << arg << std::endl;
    }

    return 0;
}
