#include <iostream>
#include <limits>

int main(int argc, const char **argv) {

  int value{10.10};
  const int value_const{1};      // compile time / runtime
  constexpr int value_const_{2}; // compile time
  int const value{10};

  value = 10;

  std::cout << value << std::endl;
  ;

  std::cout << value_const << std::endl;
  ;

  value_const = 10;
  return 0;
}
