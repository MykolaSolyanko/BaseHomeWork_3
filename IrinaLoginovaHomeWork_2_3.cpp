#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdexcept>

int main() {
  std::cout << "Enter the number --> ";
  int32_t number;
  std::cin >> number;
  if (number < 0)
    std::cout << "-";
  int x = abs(number) % 10;
  while (x != 0) {
    std::cout << x;
    number = (abs(number) - x) / 10;
    x = abs(number) % 10;
  }
  return 0;
}
