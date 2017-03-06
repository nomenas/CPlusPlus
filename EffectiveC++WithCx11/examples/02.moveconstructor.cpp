#include <string>
#include <iostream>
#include <iomanip>
#include <utility>

struct A
{
    std::string s;
    A() : s("test") { std::cout << "A ctor\n"; }
    virtual ~A() {std::cout << "A destructor\n"; }
    A(const A& o) : s(o.s) { std::cout << "A copy ctor!\n"; }
    A(A&& o) noexcept : s(std::move(o.s)) { std::cout << "move A\n"; }
};

struct B : A
{
    std::string s2;
    int n;
    // implicit move constructor B::(B&&)
    // calls A's move constructor
    // calls s2's move constructor
    // and makes a bitwise copy of n
};

struct C : B
{
    ~C() { } // prefents generation of move ctor
};

struct D : B
{
    D() { }
    ~D() { }          // destructor would prevent implicit move ctor D::(D&&)
    D(D&&) = default; // force a move ctor anyway
};

A f(A a)
{
    return a;
}

int main()
{
    std::cout << "Trying to move A\n";
    A a1 = f(A());
    A a2 = std::move(a1);

    std::cout << "Trying to move B\n";
    B b1;
    std::cout << "Before move, b1.s = " << b1.s << "\n";
    B b2 = std::move(b1); // calls implicit move ctor
    std::cout << "After move, b1.s = " << b1.s << "\n";

    std::cout << "Trying to move C\n";
    C c1;
    C c2 = std::move(c1);

    std::cout << "Trying to move D\n";
    D d1;
    D d2 = std::move(d1);
}
