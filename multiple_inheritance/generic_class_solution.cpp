#include <iostream>

// abstraction
//      A
//     /
//    B
//    |
//    C

class A {
public:
    virtual ~A() = default;
    virtual void do_a() = 0;

    virtual A* clone() const = 0;
};

class B : public A {
public:
    virtual void do_b() = 0;

    virtual B* clone() const = 0;
};

class C : public B {
public:
    virtual void do_c() = 0;

    virtual C* clone() const = 0;
};

// base implementation

template <typename Interface>
class ABase : public Interface {
public:
    void do_a() override {
        std::cout << "ABase::do_a" << std::endl;
    }
};

template <typename Interface>
Interface* clone(const Interface* obj) {
    return obj->clone();
}

template <typename Interface>
class BBase : public ABase<Interface> {
public:
    void do_b() override {
        std::cout << "BBase::do_b" << std::endl;
    }

    void do_b_private() {
        std::cout << "BBase::do_b_private" << std::endl;
    }

    Interface* clone() const override {
        std::cout << "Interface* BBase::clone" << std::endl;
        return ::clone(static_cast<const Interface*>(this));
    }
};

using BImpl = BBase<B>;

template <>
B* clone(const B*) {
    return new BImpl{};
}

// concrete implementation

class CImpl : public BBase<C> {
public:
    void do_c() override {
        std::cout << "CImpl::do_c()" << std::endl;
    }

    C* clone() const override {
        std::cout << "C* CImpl::clone" << std::endl;
        return new CImpl{};
    }
};

void testConcreteImpl(BImpl& test) {
    std::cout << "\n*** Concrete Implementation ***\n" << std::endl;
    test.do_a();
    test.do_b();
    test.do_b_private();
    test.clone();
}

void testExtendingConcreteImpl(CImpl& test) {
    std::cout << "\n*** Concrete Implementation ***\n" << std::endl;
    test.do_a();
    test.do_b();
    test.do_c();
    test.do_b_private();
    test.clone();
}

void testCastToConcrete(B *interface) {
    std::cout << "\n*** Test Casts ***\n" << std::endl;
    interface->clone();

    auto impl = static_cast<BImpl*>(interface);
    impl->do_b_private();
    impl->clone();
}

int main() {
    BImpl b;
    CImpl c;
    testConcreteImpl(b);
    testExtendingConcreteImpl(c);
    testCastToConcrete(static_cast<B *>(&c));

    return 0;
}