#include <iostream>

struct Testable
{
    operator bool() const {
          return false;
    }
};
struct AnotherTestable
{
    operator bool() const {
          return true;
    }
};
int main (void)
{
  Testable a;
  AnotherTestable b;

  std::cout << (a == b) << std::endl;
  std::cout << (a < 0)  << std::endl;
  std::cout << (a) << std::endl;

  return 0;
}
