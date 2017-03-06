#include <iostream>

void process(const std::string& lvalArg)
{
    std::cout << "process(const Widget& lvalArg)\n";
}

void process(std::string&& rvalArg)
{
    std::cout << "process(Widget&& rvalArg)\n";
}

template<typename T>
void logAndProcess(T&& param)
{
    std::cout << typeid(param).name() << ": " << param;
    process(std::forward<T>(param));
}

int main()
{
    std::string arg = "argument";
    logAndProcess(arg);
    logAndProcess(std::move(arg));
}
