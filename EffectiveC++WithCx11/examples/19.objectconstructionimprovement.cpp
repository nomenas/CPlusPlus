#include <iostream>

class FooMember
{
public:
    FooMember(int arg) : value(arg) {}
    int value;
};

class BaseClass {
public:
    explicit BaseClass(int value) : m_value(value) {}
    BaseClass() : BaseClass(10) {}

    int value() const { return m_value;}
    int valueInH() const {return m_initValueInH;}
    FooMember* getObject() const {return m_pPtr;}

private:
    int m_value;
    int m_initValueInH = 20;
    FooMember* m_pPtr = new FooMember(12);
};

class DerivedClass : public BaseClass {
public:
    using BaseClass::BaseClass;
};

int main()
{
    // DerivedClass object initilized properly although it has no constructor which gets int argument
    DerivedClass foo1(5), foo2;
    std::cout << foo1.value() << " " << foo2.value() << std::endl;
    std::cout << foo1.valueInH() << " " << foo2.valueInH() << std::endl;
    std::cout << foo1.getObject()->value << " " << foo2.getObject()->value << std::endl;
}
