#include <iostream>
#include <stdexcept>

int main() {
  int NumberTicket{};
  std::cout << "Please enter 6 numbers of your ticket." << std::endl;
  std::cout << "Number is --> " << std::endl;
  std::cin >> NumberTicket;
  int x = NumberTicket % 10;
  int sum_1{0};
  int sum_2{0};
  int i{0};
  while (x != 0) {
    i++;
    if (i > 0 && i < 4) {
      sum_1 += x;
    }
    if (i > 3 && i < 7) {
      sum_2 += x;
    }
    NumberTicket = (NumberTicket - x) / 10;
    x = NumberTicket % 10;
  }
  if (sum_1 != sum_2) {
    std::cout << "Congratulations! You NO have a lucky ticket." << std::endl;
  } else {
    std::cout << "Congratulations! You have a lucky ticket." << std::endl;
  }
  return 0;
}
