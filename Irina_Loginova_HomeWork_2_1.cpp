#include <cstdint>
#include <iostream>

int main() {

  std::cout << "Inpot A= " << std::endl;
  int a{};
  std::cin >> a;
  double x = a % 10;
  double sum{0};
  int i{0};
  while (x != 0) {
    std::cout << "x= " << x << std::endl;
    sum += x;
    ++i;
    a = (a - x) / 10;
    x = a % 10;
  }
  std::cout << "The sum of numbers is " << sum << std::endl;
  std::cout << "The average is " << sum / i << std::endl;
  return 0;
}
