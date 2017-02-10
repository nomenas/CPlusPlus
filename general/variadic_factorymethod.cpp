#include <iostream>

struct Foo {
    int arg1;
    double arg2;
};

template <typename T>
struct Factory {
    template <typename... Args>
    static T Create(Args&&... args) {
        return T{std::forward<Args>(args)...};
    }
};

int main() {
    auto foo = Factory<Foo>::Create(1, 2.);
    std::cout << "foo {" << foo.arg1 << ", " << foo.arg2 << "}" << std::endl;

    return 0;
}
