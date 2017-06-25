#include <string>
#include <iostream>
#include <typeinfo>
#include <experimental/optional>

template <typename T>
using optional = std::experimental::optional<T>;

// optional can be used as the return type of a factory that may fail
optional<std::string> create(bool b) {
    if(b)
        return std::string("Godzilla");
    else
        return {};
}

class Foo {
public:
    const optional<int>& int_value() const {
        return _int_value;
    }

    const optional<std::string>& string_value() const {
        return _string_value;
    }

private:
    optional<int> _int_value;
    optional<std::string> _string_value;
};

template <typename T>
void print_type_properties() {
    std::cout << typeid(T).name()
              << "    " << std::boolalpha << "is move-constructible? "
              << "    " << std::is_move_constructible<T>::value << '\n'
              << "    " << "is trivially move-constructible? "
              << "    " << std::is_trivially_move_constructible<T>::value << '\n'
              << "    " << "is nothrow move-constructible? "
              << "    " << std::is_nothrow_move_constructible<T>::value << '\n'
              << "    " << "std::is_trivially_copy_assignable? "
              << "    " << std::is_trivially_copy_assignable<T>::value << '\n'
              << "    " << "is copy-assignable? "
              << "    " << std::is_copy_assignable<T>::value << '\n'
              << "    " << "nothrow copy-assignable? "
              << "    " << std::is_nothrow_copy_assignable<T>::value << '\n';
}

class Temp {
public:
    Temp(int value) : _value{value} {}

    int value() const {
        return _value;
    }
private:
    int _value;
};

Temp&& tempFactory(int value) {
    return Temp{value};
}

int main()
{
    auto optional_empty = create(false);
    std::cout << "create(false) returned "
              << optional_empty.value_or("empty") << " size " << sizeof(optional_empty) << '\n';

    // optional-returning factory functions are usable as conditions of while and if
    auto optional_filled = create(true);
    if(auto str = optional_filled) {
        std::cout << "create(true) returned " << *str << " size " << sizeof(optional_empty) << '\n';
    }

    print_type_properties<optional<std::string>>();
    print_type_properties<Foo>();
    print_type_properties<Temp>();

    Temp temp = tempFactory(10);
    std::cout << temp.value() << "\n";
}