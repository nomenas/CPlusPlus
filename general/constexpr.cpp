#include <iostream>
#include <array>

constexpr int literalType = 0;
constexpr int unifiedInitilizedArray[] = {1, 2, 3, 4, 5, 6};

constexpr int constExprFunction(int input)
{
    // for this you will be faced with compile error
    // auto temp = std::make_unique<int>(1);

    // C++14 is much more liberal and allow much more C++ normal code into these functions
    switch (input)
    {
    case 0: return 1;
    case 1: return 2;
    default: return 3;
    }
}

constexpr int constExpresionFunctionResult = constExprFunction(literalType);

template <int N>
struct CacheArray
{
    constexpr CacheArray()
    {
        for (int i = 0; i < N; ++i)
        {
            array[N - i - 1] = i;
        }
    }

    int array[N] = {};
};


int main()
{
    std::cout << constExpresionFunctionResult << std::endl;
    static_assert(constExpresionFunctionResult == 1, "it should be 1");

    constexpr CacheArray<10> cache;
    std::cout << cache.array[0] << " " << cache.array[1] << std::endl;

    return 0;
}
