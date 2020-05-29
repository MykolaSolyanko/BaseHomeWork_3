#include <cstdint>
#include <iostream>

int main() {

  std::cout << "Inpot A= ";
  int a{};
  std::cin >> a;
  double sum{0};
  int i{0};
  while (double x = a % 10) {
    sum += x;
    i = i++;
    a = (a - x) / 10;
    x = a % 10;
  }
  std::cout << "The sum of numbers is " << sum << std::endl;
  std::cout << "The average is " << sum / i << std::endl;
  return 0;
}
