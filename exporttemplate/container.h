#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>

namespace my {
    template <typename T>
    class Container : public std::vector<T>
    {
    public:
        const char* type() const;
    };
}

#endif //CONTAINER_H