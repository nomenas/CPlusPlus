#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>

namespace my {
    template <typename T>
    class Vector : public std::vector<T>
    {
    public:
        using std::vector<T>::vector;

        // test method from dynamic library
        const char* type() const;
    };
}

#endif //CONTAINER_H