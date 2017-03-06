#include <iostream>
#include <vector>

class Foo
{
public:
    void method() {}
};

int foo()
{
    return 0;
}

template<typename T> class CheckType;

class NoCopyable {
public:
    NoCopyable(const NoCopyable&) = delete;
    NoCopyable& operator=() = delete;
};

const NoCopyable& method() {
    static NoCopyable instance;
    return instance;
}

int main()
{
    const std::vector<int> v(1);
    auto a = v[0];        // a has type int
    std::cout << "type of a is " << typeid(a).name() << std::endl;
    auto c = 0;           // c has type int
    std::cout << "type of c is " << typeid(c).name() << std::endl;
    auto functPtr = foo;
    //CheckType<decltype(functPtr)> test;
    std::cout << "type of functPtr is " << typeid(functPtr).name() << std::endl;
    auto methodPtr = &Foo::method;
    std::cout << "type of methodPtr is " << typeid(methodPtr).name() << std::endl;
    auto obj = Foo();
    std::cout << "type of obj is " << typeid(obj).name() << std::endl;
    auto lambda = [](){};
    std::cout << "type of lambda is " << typeid(lambda).name() << std::endl;

    int& ref = a;
    auto autoFromRef = ref;
    std::cout << "type of autoFromRef is " << typeid(autoFromRef).name() << std::endl;
    int&& rref = std::move(a);
    auto autoFromRValue = rref;
    std::cout << "type of autoFromRValue is " << typeid(autoFromRValue).name() << std::endl;
    const int constValue = a;
    auto autoFromConst = constValue;
    std::cout << "type of autoFromConst is " << typeid(autoFromConst).name() << std::endl;

//    auto nonCopyable = method();

    return 0;
}
