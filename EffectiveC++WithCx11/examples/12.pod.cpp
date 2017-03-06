#include <iostream>

struct N { // neither trivial nor standard-layout
   int i;
   int j;
    virtual ~N(){}
};

struct T { // trivial but not standard-layout
    int i;
private:
    int j; // All non-static data members must have the same access control
};

struct SL { // standard-layout but not trivial
    int i;
    int j;
    ~SL();
};

struct POD { // both trivial and standard-layout
    int i;
    int j;
};

int main ()
{
    N* n = new N(); // ERROR
    T* t = new T;
    return 0;
}
