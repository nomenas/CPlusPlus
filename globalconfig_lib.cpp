#include <iostream>

struct GlobalInitilizer
{
    GlobalInitilizer()
    {
        std::cout << "global init" << std::endl;
    }

    ~GlobalInitilizer()
    {
        std::cout << "uninit" << std::endl;
    }
};

static GlobalInitilizer _init;

int libFunction()
{
    return 0;
}
