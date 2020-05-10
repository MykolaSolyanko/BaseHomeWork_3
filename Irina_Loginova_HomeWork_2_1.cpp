#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdexcept>

int main() {

  std::cout << "Inpot A= " << std::endl;
  long long a{};
  std::cin >> a;
  int x = a % 10;
  int sum{0};
  int i{0};
  while (x != 0) {
    std::cout << "x= " << x << std::endl;
    sum += x;
    i = i++;
    a = (a - x) / 10;
    x = a % 10;
  }
  std::cout << "The sum of numbers is " << sum << std::endl;
  std::cout << "The average is " << sum / i << std::endl;
  return 0;
}
