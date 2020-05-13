#include <cmath>
#include <iostream>

enum TASKS { TREE = 1, NUMOFBITS, SETBITCHECK, BUILDNUMBER };

void treeConstruction() {
  std::cout << "Enter a number:"
            << "\n";
  int number;
  std::cin >> number;
  if (number % 2 == 0) {
    number += 1;
  }
  int spaces = number / 2;
  for (size_t stars = 1; stars <= number; stars += 2, spaces--) {
    for (size_t i = 0; i < spaces; i++) {
      std::cout << " ";
    }
    for (size_t j = 0; j < stars; j++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
}

void numberOfBits() {
  std::cout << "Enter a number:"
            << "\n";
  int number;
  std::cin >> number;
  int count{};
  size_t i{};
  constexpr int kIntBit = sizeof(int) * 8;
  while (i < kIntBit) {
    if (number & (1 << ++i)) {
      ++count;
    }
  }
  std::cout << "The number of set bits is " << count << "\n";
}

void setBitCheck() {
  std::cout << "Enter a number:\n";
  int number;
  std::cin >> number;
  std::cout << "Enter a check number:\n";
  int checkNumber;
  std::cin >> checkNumber;
  bool bitSet = number & (1 << checkNumber);
  if (bitSet) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}

void buildNumber() {
  std::cout << "How many numbers do you want to be checked?\n";
  int quantity;
  std::cin >> quantity;
  int total{};
  for (size_t i = 0; i < quantity; i++) {
    std::cout << "Enter a number:\n";
    int number;
    std::cin >> number;
    int sum{};
    while (number != 0) {
      int digit = number % 10;
      number = number / 10;
      sum += digit;
    }
    total += sum;
  }
  if ((total % 3) == 0) {
    std::cout << "Yes\n";
  } else
    std::cout << "No\n";
}

int main() {
  std::cout << "Choose a program:\n";
  std::cout << TREE << ". Constructing a tree\n";
  std::cout << NUMOFBITS << ". Number of set bits\n";
  std::cout << SETBITCHECK << ". Set bit check\n";
  std::cout << BUILDNUMBER << ". Building a number\n";
  std::cout << "Press any other key to exit\n";
  while (true) {
    std::cout << "Enter the desired number from " << TREE << " to "
              << BUILDNUMBER << "\n";
    int chosenProgram;
    std::cin >> chosenProgram;
    switch (chosenProgram) {
    case TREE:
      treeConstruction();
      break;
    case NUMOFBITS:
      numberOfBits();
      break;
    case SETBITCHECK:
      setBitCheck();
      break;
    case BUILDNUMBER:
      buildNumber();
      break;
    default:
      return 0;
    }
  }
}
