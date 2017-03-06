#include <iostream>
#include "13.externtemplate.h"

extern int templateCaller(int arg);

int main ()
{
    std::cout << templateFunction<int>(10) << " " << templateCaller(15) << std::endl;
    return 0;
}



