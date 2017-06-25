#include <string>
#include <experimental/string_view>

struct A
{
//  compile error, it has to be constexpr
//    const static double x = 1.0;
    constexpr static double y = 1.0;
//  constexpr variable cannot have non-literal type
//    constexpr static std::string str{""};
};

int main()
{
    return 0;
}