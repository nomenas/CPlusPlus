#include <iostream>

class A {
public:
    virtual ~A() = default;
    virtual void do_a() = 0;
};

class BaseImplementation : /* virtual */ public A {
public:
    void do_a() override {
        std::cout << "BaseImplementation::do_base" << std::endl;
    }
};

class Interface_A : /* virtual */ public A {
public:
    virtual void do_b() = 0;
};

class ExtensionImplementation : public BaseImplementation, public Interface_A {
public:
    void do_b() override {
        std::cout << "ExtensionImplementation::do_interface_A" << std::endl;
    }
};

int main() {
    ExtensionImplementation test;
    test.do_a();
    test.do_b();

    return 0;
}