#include <iostream>

// abstraction

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

class C : public A {
public:
    virtual void do_c() = 0;

    virtual C* clone() const = 0;
};

class D : public B {
public:
    virtual void do_d() = 0;

    virtual D* clone() const = 0;
};

class BC : public B, public C {
public:
    virtual void do_bc() = 0;

    virtual BC* clone() const = 0;
};

// base implementation

template <typename Interface>
class ABase : public Interface {
public:
    void do_a() override {
        std::cout << "ABase::do_a" << std::endl;
    }
};

using AImpl = ABase<A>;

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
        return nullptr;
    }
};

using BImpl = BBase<B>;

template <typename Interface>
class CBase : public ABase<C> {
public:
    void do_c() override {
        std::cout << "CBase::do_c" << std::endl;
    }

    void do_c_private() {
        std::cout << "CBase::do_c_private" << std::endl;
    }

    Interface* clone() const override {
        std::cout << "Interface* CBase::clone" << std::endl;
        return nullptr;
    }
};

using CImpl = CBase<C>;

// concrete implementation

class DImpl : public BBase<D> {
public:
    void do_d() override {
        std::cout << "DImpl::do_d" << std::endl;
    }

    D* clone() const override {
        std::cout << "D* DImpl::clone" << std::endl;
        return nullptr;
    }
};

// multiple inheritance

class BCImpl
    : public BBase<BC>
    , public CBase<BC> {
public:
    using B = BBase<BC>;
    using C = CBase<BC>;

    void do_bc() override {
        std::cout << "Interface_AB_AImpl::do_Interface_AB_A" << std::endl;
    }

    void do_b() override {
        B::do_b();
    }

    void do_c() override {
        C::do_c();
    }

    BC* clone() const override {
        std::cout << "BC* BCImpl::clone" << std::endl;
        return nullptr;
    }
};

template <typename Type, typename Direction, typename T>
Type* static_multi_cast(T* obj) {
    return static_cast<Type*>(static_cast<Direction*>(obj));
};

void testConcreteImpl() {
    std::cout << "\n*** Concrete Implementation ***\n" << std::endl;
    BImpl test;
    test.do_a();
    test.do_b();
    test.do_b_private();
    std::cout << typeid(test.clone()).name() << " expected B*" << std::endl;
}

void testExtendingConcreteImpl() {
    std::cout << "\n*** Concrete Implementation ***\n" << std::endl;
    DImpl test;
    test.do_a();
    test.do_b();
    test.do_d();
    test.do_b_private();
    std::cout << typeid(test.clone()).name() << " expected D*" << std::endl;
}

void testCasts() {
    std::cout << "\n*** Test Casts ***\n" << std::endl;
    DImpl test;
    auto interface = static_cast<B*>(&test);
    std::cout << typeid(interface->clone()).name() << " expected D*" << std::endl;
    auto impl = static_cast<BImpl*>(interface);
    impl->do_b_private();
    std::cout << typeid(impl->clone()).name() << " expected D*" << std::endl;
}

void testMultipleInheritance() {
    std::cout << "\n*** Multiple Inheritance Test ***\n" << std::endl;
    BCImpl test;
    test.do_b();
    test.do_c();
    test.do_bc();
    std::cout << typeid(test.clone()).name() << " expected BC*" << std::endl;
}

void testMultipleInheritanceUpCast() {
    std::cout << "\n*** Multiple Inheritance Up Cast Test ***\n" << std::endl;
    BCImpl test;
    auto interface = static_multi_cast<B, BCImpl::B>(&test);
    std::cout << typeid(interface->clone()).name() << " expected BC*" << std::endl;
}

void testMultipleInheritanceDownCast() {
    std::cout << "\n*** Multiple Inheritance Down Cast Test ***\n" << std::endl;
    BCImpl test;
    auto b_interface = static_multi_cast<B, BCImpl::B>(&test);
    auto bc_interface = static_cast<BC*>(b_interface);
    std::cout << typeid(bc_interface->clone()).name() << " expected BC*" << std::endl;
}

int main() {
    testConcreteImpl();
    testExtendingConcreteImpl();
    testCasts();
    testMultipleInheritance();
    testMultipleInheritanceUpCast();
    testMultipleInheritanceDownCast();

    return 0;
}