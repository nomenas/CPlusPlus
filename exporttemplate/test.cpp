//
// Created by Naum Puroski on 01/04/2017.
//

#include <iostream>
#include "MyType2.h"

void test_my_type2_size() {
    std::cout << "size of MyType<int> is " << sizeof(MyType<int>) << std::endl;
}

void test_my_type2_method() {
    std::cout << "method1 = " << MyType<int>{1}.method() << std::endl;
    std::cout << "method2 = " << MyType<int>{1}.method2() << std::endl;
}