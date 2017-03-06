#include <functional>
#include <iostream>

class Foo
{
public:
    Foo(int value) : m_value(value), m_valuePtr(&m_value){}

    void show()
    {
        std::cout << "obj: " << (long) this << " with value "  << m_value <<
                     " stored at " << (long) &m_value << ", initilized at " <<
                     (long) m_valuePtr << std::endl;
    }

private:
    int m_value;
    int* m_valuePtr;
};

int main()
{
    std::function<double(double)> f0 = [](double x) -> decltype(x) {return x;};
    auto f1 = [](double x) -> decltype(x) {return x;};
    std::cout << typeid(f0).name() << " " << typeid(f1).name() << std::endl;

    // test modify local variables
    int foo = 0;
    [&](){ foo = 5; }();
    std::cout << "new value is " << foo << std::endl;

    // test what will happen when object has no copy operator and mutable
    Foo obj(5);
    obj.show();
    [=]() mutable {obj.show();}();

    return 0;
}
