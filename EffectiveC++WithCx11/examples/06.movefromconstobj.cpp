#include <iostream>

class Annotation
{
public:
    explicit Annotation(const std::string text)
        : value(std::move(text))
    {
        std::cout << "What is output here ?\n";
        std::cout << value << " " << text << std::endl;
    }

   private:
     std::string value;
};


int main()
{
    std::string argument = "argument";
    Annotation annotation(argument);
    return 0;
}
