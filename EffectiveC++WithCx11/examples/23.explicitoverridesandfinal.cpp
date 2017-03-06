#include <iostream>

class A
{
public:
    virtual void method1()
    {
        std::cout << "A::method1()\n";
    }

    virtual void method2()
    {
        std::cout << "A::method2()\n";
    }
};

class B : public A
{
public:
    virtual void method1() override
    {
        std::cout << "B::method1()\n";
    }

    virtual void method2() override final
    {
        std::cout << "B::method2()\n";
    }
};

class C : public B
{
public:
    virtual void method1() override
    {
        std::cout << "C::method1()\n";
    }

//    virtual void method2() override final
//    {
//        std::cout << "C::method2()\n";
//    }
};

int main()
{
    // they are not language keyworeds
    int final = 2;
    int override = 3;
}
