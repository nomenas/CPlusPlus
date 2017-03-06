#include <iostream>
#include <vector>
#include <initializer_list>

template <typename T>
void templated_fn(T) {}

class MyClass
{
public:
    MyClass(int n, std::string m) : m_n(n), m_m(m){}

    int m_n;
    std::string m_m;
};


// POD
struct Object {
    float first;
    int second;
};

template<class T>
class MyVector
{
public:
    MyVector(std::initializer_list<T> l)
    {
        size = (int)l.size();
        arrayData = new int[size];
        std::copy(l.begin(), l.end(), arrayData);
    }

    T& operator[](int index) const
    {
        return arrayData[index];
    }

private:
    T* arrayData;
    int size;
};

int main()
{
    std::vector<int> s = {1, 2, 3, 4, 5}; // copy list-initialization
    s.insert(s.end(), {6, 7, 8});      // list-initialization in function call
    std::cout << "The vector size is now " << s.size() << " ints:\n";

    for (auto n : s)
        std::cout << n << ' ';
    std::cout << '\n';

    std::cout << "Range-for over brace-init-list: \n";

    for (int x : {-1, -2, -3}) // the rule for auto makes this ranged-for work
        std::cout << x << ' ';
    std::cout << '\n';

    auto al = {10, 11, 12};   // special rule for auto
    std::cout << "The list bound to auto has size() = " << al.size() << '\n';

//    templated_fn({1, 2, 3}); // compiler error! "{1, 2, 3}" is not an expression,
                             // it has no type, and so T cannot be deduced
    templated_fn<std::initializer_list<int> >({1, 2, 3}); // OK
    templated_fn<std::vector<int>>({1, 2, 3});           // also OK

    MyClass obj({3, "test"});
    std::cout << obj.m_n << " " << obj.m_m << std::endl;

    int primitiveType = {4};
    int primitiveArray[] = {4};
    const char* stringType{"something"};

    std::cout << primitiveType << " " << primitiveArray << " " << stringType;

    Object anArray[] = {{13.4f, 3}, {43.28f, 29}, {5.934f, 17}};
    for (auto anItem : anArray)
    {
        std::cout << anItem.first << " " << anItem.second << std::endl;
    }

    MyVector<int> temp({1, 2, 3, 4});
    for (int i = 0; i < 4; ++i)
    {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;
}
