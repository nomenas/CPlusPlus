#include <iostream>

enum class A
{
    Item1,
    Item2,
    Item3
};

enum class B : unsigned long
{
    Item1 /* = -1 */,
    Item2,
    Item3
};

int main()
{
    std::cout << "A: " << (int) A::Item1 << " " << (int) A::Item2 << " "<< (int) A::Item3 << std::endl;
    std::cout << "B: " << (int) B::Item1 << " " << (int) B::Item2 << " "<< (int) B::Item3 << std::endl;
    std::cout << "sizes " << sizeof(A::Item1) << " " << sizeof(B::Item1) << std::endl;
    std::cout << "types " << typeid(A::Item1).name() << " " << typeid(B::Item1).name() << std::endl;

//    bool b = A::Item1 == B::Item2;
//    bool b = Item1 == Item2;
}
