#include <iostream>

class A {
public:
    virtual ~A() = default;
    virtual void do_a() = 0;
};

class AImpl : public A {
public:
    void do_a() override {
        std::cout << "AImpl::do_base" << std::endl;
    }
};

class B : public A {
public:
    virtual void do_b() = 0;
};

class BImpl : public AImpl, public B {
public:
    void do_b() override {
        std::cout << "BImpl::do_interface_A" << std::endl;
    }

    void do_a() override {
        AImpl::do_a();
    }
};

int main() {
    BImpl test;
    test.do_a();
    test.do_b();
    // TODO

    A* a_interface = static_cast<A*>(&test);
    return 0;
}