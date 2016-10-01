#include <iostream>
#include <array>

template<class Function, std::size_t... Indices>
constexpr auto make_array_helper(Function f, std::index_sequence<Indices...>)
-> std::array<typename std::result_of<Function(std::size_t)>::type, sizeof...(Indices)>
{
    return {{ f(Indices)... }};
}

template<int N, class Function>
constexpr auto make_array(Function f)
-> std::array<typename std::result_of<Function(std::size_t)>::type, N>
{
    return make_array_helper(f, std::make_index_sequence<N>{});
}

constexpr int fun(int x) { return x * x; }

int main()
{
    constexpr auto N = 10;
    constexpr auto a = make_array<N>(fun);

    std::copy(std::begin(a), std::end(a), std::ostream_iterator<double>(std::cout, ", "));
    std::cout << std::endl;

    return 0;
}
