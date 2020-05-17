#include <iostream>

int main() {
  std::cout << "What task do you want to solve ?" << std::endl;

  int setNumber(0);

  while (setNumber < 1 || setNumber > 2) {
    std::cout << "1: Revers " << std::endl;
    std::cout << "2: Insert an element into an array " << std::endl;
    std::cin >> setNumber;
    if (setNumber == 1) {
      std::cout << "Enter a line to reverse" << std::endl;
      std::string s;
      std::cin >> s;
      for (int i = s.length() - 1; i >= 0; i--) {
        std::cout << s[i];
      }
      std::cout << "" << std::endl;
    } else if (setNumber == 2) {
      constexpr int arrayLength{5};
      int array[arrayLength] = {};
      int number(0);
      std::cout << "Enter 5 numbers to arrange them in order" << std::endl;

      for (int key(0); key < arrayLength; key++) {
        std::cin >> number;
        array[key] = number;
        int i = key;
        while (i > 0) {
          if (array[i] < array[i - 1]) {
            int replacement = array[i - 1];
            array[i - 1] = array[i];
            array[i] = replacement;
          }
          i--;
        }
      }
      for (int key(0); key < arrayLength; key++) {
        std::cout << array[key] << " ";
      }
      std::cout << "" << std::endl;
    }
  }
  return 0;
}
