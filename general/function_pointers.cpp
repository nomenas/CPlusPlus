//
// Created by Naum Puroski on 06/12/2016.
//

#include <iostream>
#include <unordered_set>

class Foo {
public:
    int method(int value){
        return value;
    }

    int overloaded(int value) {
        return value;
    }

    int overloaded(char* value) {
        return 0;
    }
};

typedef int(Foo::*MethodType1)(int);
using MethodType2 = int (Foo::*)(int);
using MethodType3 = decltype((&Foo::method));

typedef int(Foo::*OverloadedType1)(int);
using OverloadedType2 = int (Foo::*)(int);
using OverloadedType3 = decltype((&Foo::method));

using Set = std::unordered_set<Foo*>;
typedef std::pair<Set::iterator, bool>(Set::*SetType1)(const Set::value_type&);
using SetType2 = std::pair<Set::iterator, bool>(Set::*)(const Set::value_type&);

int main(int argc, char** argv) {
    Foo temp;
    MethodType1 function1 = &Foo::method;
    MethodType2 function2 = &Foo::method;
    MethodType3 function3 = &Foo::method;

    OverloadedType1 o1 = &Foo::overloaded;
    OverloadedType2 o2 = &Foo::overloaded;
    OverloadedType3 o3 = &Foo::overloaded;

    Set set;
    SetType1 s1 = &Set::insert;
    (set.*s1)(&temp);
    SetType2 s2 = &Set::insert;
    (set.*s2)(&temp);

    std::cout << (temp.*function1)(1) << " " << (temp.*function2)(2) << " " << (temp.*function3)(3) << std::endl;
    std::cout << (temp.*o1)(1) << " " << (temp.*o2)(2) << " " << (temp.*o3)(3) << std::endl;
    std::cout << set.size() << std::endl;

    return 0;
}