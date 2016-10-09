#include <iostream>

// Nice artical: http://articles.emptycrate.com/2016/05/14/folds_in_cpp11_ish.html
template<typename ... V>
auto sum_all(const V &... v) -> typename std::common_type<V...>::type {
    using CommonType = typename std::common_type<V...>::type;
    CommonType result = {};
    (void)std::initializer_list<int>{ (result += v, 0)... };
    return result;
}

int main() {
    std::cout << "\ncalculation" << std::endl;
    std::cout << sum_all(1,2,3.4,8.9) << '\n';
}