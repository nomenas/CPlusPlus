#include <iostream>

enum class os {
    Windows,
    Linux,
    MacOSX
};

struct entry {
    char const *name;
    os key;
};

constexpr entry map[] =
        {
                {"windows", os::Windows},
                {"linux",   os::Linux},
                {"mac",     os::MacOSX}
        };

constexpr bool same(char const *x, char const *y) {
    // C++11 return !*x && !*y ? true : (*x == *y && same(x + 1, y + 1));

    // since C++14
    bool returnValue = true;

    while (!*x && !*y && returnValue) {
        returnValue = (*x++ == *y++);
    }

    return returnValue;
}

constexpr os key(char const *name, entry const *entries) {
    return same(entries->name, name) ? entries->key : key(name, entries + 1);
}

constexpr char const *name(os key, entry const *entries) {
    return key == entries->key ? entries->name : name(key, entries + 1);
}

int main() {
    // here value is evaluated in compile time
    constexpr os temp = key("windows", map);
    // here value is called in runtime
    os temp1 = key("mac", map);

    std::cout << "constexp os temp = " << (int) temp << std::endl;
    std::cout << "os temp1 = " << (int) temp1 << std::endl;

    constexpr char const *winName = name(os::Windows, map);
    std::cout << "name of os::Windows = " << winName << std::endl;

    return 0;
}
