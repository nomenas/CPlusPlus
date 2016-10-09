#include <iostream>

template<typename T>
class Proxy {
private:
    T &m_ref;

    template<typename F>
    auto operator()(F f) const -> decltype(f(m_ref)) {

        return f(m_ref);
    }

public:
    Proxy(T &t_) : m_ref(t_) {}

    template<typename F>
    auto call(F f) -> decltype(std::bind(f, std::placeholders::_1)(m_ref)) {
        return (*this)(std::bind(f, std::placeholders::_1));
    };

    template<typename F, typename... Args>
    auto call(F f, Args &&... args) -> decltype(std::bind(f, std::placeholders::_1, std::forward<Args>(args)...)(m_ref)) {
        return (*this)(std::bind(f, std::placeholders::_1, std::forward<Args>(args)...));
    };
};

class Foo {
public:
    int method(int arg) {
        return arg;
    }

    int constMethod(int arg) const {
        return arg;
    }

    int constArgument(const int arg) const {
       return arg;
    }

    int referenceArgument(int& arg) {
        arg = 5;
        return arg;
    }
};

int main() {
    Foo foo;
    Proxy<Foo> fooProxy{foo};

    std::cout << "non-cost method call " << fooProxy.call(&Foo::method, 2000) << std::endl;
    std::cout << "cost method call " << fooProxy.call(&Foo::constMethod, 1000) << std::endl;
    std::cout << "cost argument method call " << fooProxy.call(&Foo::constArgument, 3000) << std::endl;
    int arg = 5000;
    std::cout << "reference argument method call " << fooProxy.call(&Foo::referenceArgument, std::ref(arg)) << std::endl;
    std::cout << arg << std::endl;
    return 0;
}