#include <iostream>

void onebyone() {}
template<typename Arg1Type, typename... Args>
void onebyone(Arg1Type arg, Args... args) {
    std::cout << arg << std::endl;
    onebyone(args...);
}

int main() {
    onebyone(1, 2, 3.1, "3");

    return 0;
}