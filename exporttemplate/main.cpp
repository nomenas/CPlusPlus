#include <iostream>
#include <sstream>
#include "container"

int main() {

    my::Vector<int> obj;
    std::cout << "my::Vector<int> contains items of type " << obj.type() << std::endl;

    // check initialisation with initializer list
    my::Vector<int> obj1 = {1, 2, 3, 4, 5};
    // check coping
    my::Vector<int> obj2 = obj1;
    // check moving
    my::Vector<int> obj3 = std::move(obj2);

    // check interoperability with std::vector
    std::vector<int> vectorObj = {1, 2, 3, 4, 5};
    // check move syntax. It doesn't work because allocator is different
//    my::Vector<int> obj41(vectorObj);
//    my::Vector<int> obj42 = vectorObj;
//    my::Vector<int> obj43(std::move(vectorObj));
//    my::Vector<int> obj44 = std::move(vectorObj);

    auto intContainerValues = [](const std::vector<int>& container) -> std::string {
        std::stringstream ss;
        for (const auto item : container) {
            ss << item << " ";
        }
        ss << std::endl;

        return ss.str();
    };

    auto fooContainerValues = [](const std::vector<Foo>& container) -> std::string {
        std::stringstream ss;
        for (const auto item : container) {
            ss << item.m_value << " ";
        }
        ss << std::endl;

        return ss.str();
    };

    // but anyway we can use algorithms in order to create copies of this object
    my::Vector<int> obj4;
    obj4.insert(obj4.end(), vectorObj.begin(), vectorObj.end());
    std::cout << "values in copy of vector:\n" << intContainerValues(obj4);

    // or to move content from one to other
    std::vector<Foo> fooVector = {{1}, {2}, {3}, {4}, {5}};
    my::Vector<Foo> obj5;
    obj5.insert(obj5.end(), std::make_move_iterator(fooVector.begin()), std::make_move_iterator(fooVector.end()));
    std::cout << "values in new vector:\n" << fooContainerValues(obj5);
    std::cout << "values of moved vector:\n" << fooContainerValues(fooVector);

    // try to some not precompiled specialization of template class
    my::Vector<float> notGeneratedClass;
    //std::cout << "my::Vector<float> contains items of type " << notGeneratedClass.type() << std::endl;

    return 0;
}