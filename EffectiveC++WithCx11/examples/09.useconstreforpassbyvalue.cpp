#include <iostream>
#include <set>

std::multiset<std::string> names;     // global data structure
void logAndAdd(const std::string& name)
{
    names.emplace(name);
}

void logAndAddByValue(std::string name)
{
    names.emplace("by value: " + std::move(name));
}

template <typename T>
void logAndAdd(T&& name)
{
    // do nothing
}

int main()
{
    std::string petName("Darla");
    logAndAdd(petName); // pass lvalue std::string
    logAndAdd(std::string("Persephone")); // pass rvalue std::string
    logAndAdd("Patty Dog");

    logAndAddByValue(petName); // pass lvalue std::string
    logAndAddByValue(std::string("Persephone")); // pass rvalue std::string
    logAndAddByValue("Patty Dog");

    for (auto item : names)
    {
        std::cout << item << std::endl;
    }

    return 0;
}
