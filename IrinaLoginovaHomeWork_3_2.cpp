#include <algorithm>
#include <iostream>
#include <stdexcept>
void ArrayOut(int Array[], int ArraySize) {
  std::cout << " Array is - ";
  for (int i = 0; i < ArraySize; i++) {
    std::cout << " " << Array[i];
  }
}

int main() { // Задача сортировки по возрастанию при вводе элемента

  const size_t ArraySize = {4};
  int Array[ArraySize]{};
  std::cout << "Please enter the integer number to Array for sort array "
               "elements ascending. "
            << std::endl;
  for (size_t i = 0; i < ArraySize; i++) {
    std::cout << " Number is ---> ";
    std::cin >> Array[0];
    ArrayOut(Array, ArraySize);
    std::sort(Array, Array + ArraySize);
    ArrayOut(Array, ArraySize);
  }
  return 0;
}
