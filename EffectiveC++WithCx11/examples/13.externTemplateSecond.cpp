#include <iostream>
#include "13.externtemplate.h"

// tell to compiler to not regeneraete this template method
extern template int templateFunction(int value);

int templateCaller(int arg)
{
    return templateFunction<int>(arg);
}
