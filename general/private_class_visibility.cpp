#include <iostream>

class Foo {
public:
    class Private {
    public:
        Private(Foo* foo)
                : _foo(foo) {
            _foo->_value = 5;
        }

    private:
        Foo* _foo = nullptr;
    };

    Foo() : _private(new Private(this)){
    }

    int value() const {
        return _value;
    }

private:
    int _value = 0;
    Private* _private = nullptr;
};

int main(int argc, char** argv) {

    Foo foo;
    std::cout << foo.value() << std::endl;
    return 0;
}
