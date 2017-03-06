#include <iostream>
#include <utility>

using namespace std;

/**** reference types ****/

int x;
int& lvalue() { return x;}
int prvalue() { return 15;}
int&& xvalue() { return static_cast<int&&>(15); }

void testReferenceTypes()
{
    // lvalue references
    {
        x = 1; // here, x is an lvalue
        lvalue() = 4; // here, getRef returns lvalue reference (it has address)
        int& ref = lvalue();
        int&& rref = static_cast<int&&>(lvalue());
        std::cout << "addresses:" << (long) &x << " " << (long) &ref << " " << (long) &rref << std::endl;
    }

    // prvalue references
    {
        // prvalue() = 4; // address is not accessable, compailer should return error here
        int result = prvalue(); // but it can be used as right-hand operand
        int&& resultAsRValue = prvalue();
        std::cout << result << " " << resultAsRValue << std::endl;
    }

    // xvalue references
    {
        int result = xvalue();
        int&& resultAsRValue = xvalue();
        std::cout << result << " " << resultAsRValue << std::endl;
    }
}

/**** reference life ****/

void testReferenceLife()
{
    int* value = new int;
    *value = 5;
    int& ref = *value;
    int&& rref = 5;
    const int& constref = 5;
    delete value;

    std::cout << ref << " " << rref << " " << constref << std::endl;
}

void testConversionFromConstToRValueReference()
{
    //const int constValue = 6;
    //int&& valueConstRef = constValue;
    //const int&& valueConstConstRef = constValue;
    //const int&& valueConstConstRef = static_cast<const int&&>(constValue);
}

/**** Universal References ****/

template<typename T> class CheckType;

void testUniversalReferences()
{
    auto&& lvalueRef = lvalue();
    auto&& prvalueRef = prvalue();
    auto&& xvalueRef = xvalue();

// check them in compile time
//    CheckType<decltype(lvalueRef)> lValueRefTypeChecker;
//    CheckType<decltype(prvalueRef)> prvalueRefTypeChecker;
//    CheckType<decltype(xvalueRef)> xvalueRefTypeChecker;

// check them in runtime
    std::cout << typeid(lvalueRef).name() << " " << typeid(prvalueRef).name() << " " << typeid(xvalueRef).name() << std::endl;
}

/**** Questions ****/

class Foo
{
public:
    Foo(int value) : m_value(value) {std::cout << "concstructor\n";}
    ~Foo() {std::cout << "destructor\n";}

    Foo(Foo& obj) {std::cout << "copy constructor\n";}
    Foo(Foo&& obj) {std::cout << "move constructor\n";}
    Foo& operator= (Foo& obj) {std::cout << "copy operator\n"; return *this;}
    Foo& operator= (Foo&& obj) {std::cout << "move operator\n"; return *this;}

    int value() const {return m_value;}
private:
    int m_value;
};

Foo foo() {return Foo(5);}
Foo&& fooRValue() {return static_cast<Foo&&>(Foo(15));}

void questions()
{
    Foo&& fooRValueReference1 = foo();
    Foo&& fooRValueReference2 = fooRValue();
    Foo foo1 = foo();
    Foo foo2 = fooRValue();

/*** Qusetions ***/
// 1. What is expected output ?
// 2. what is best approach ?
// 3. what will happen if we will bind fooFactory output into a const reference?
// 4. what will happen if we will bind fooFactory output into a reference?
// 5. What will happen if fooFactory return reference?
}

int main()
{
    testReferenceTypes();
    testReferenceLife();
    testConversionFromConstToRValueReference();
    testUniversalReferences();
    questions();

    return 0;
}

