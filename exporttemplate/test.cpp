//
// Created by Naum Puroski on 01/04/2017.
//

#include <iostream>
#include "MyType2.h"
#include "Pimpl.h"

void test_my_type2_size() {
    std::cout << "size of MyType2<int> is " << sizeof(MyType<int>) << std::endl;
    std::cout << "size of Priv<MyType2<int> is " << sizeof(Pimpl<MyType<int>>) << std::endl;
}

void test_my_type2_method() {
    std::cout << "method1 = " << MyType<int>{1}.method1() << std::endl;
    std::cout << "method2 = " << MyType<int>{1}.method2() << std::endl;
    std::cout << "pimpl<type2>.method1 = " << Pimpl<MyType<int>>().method1() << std::endl;
    std::cout << "pimpl<type2>.method2 = " << Pimpl<MyType<int>>().method2() << std::endl;
}