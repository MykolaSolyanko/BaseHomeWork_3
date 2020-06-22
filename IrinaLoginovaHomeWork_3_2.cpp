#include <algorithm>
#include <iostream>

void ArrayOut(int Array[], int ArraySize) {
  std::cout << " Array is - ";
  for (int i = 0; i < ArraySize; i++) {
    std::cout << " " << Array[i];
  }
}
void SortArray(int Array[], int ArraySize) { // сортировка пузырьком
  for (int i = 0; i < ArraySize - 1; i++) {
    for (int j = 0; j < ArraySize - i - 1; j++) {
      if (Array[j] > Array[j + 1]) {
        int temp = Array[j];
        Array[j] = Array[j + 1];
        Array[j + 1] = temp;
      }
    }
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
    SortArray(Array, ArraySize);
    ArrayOut(Array, ArraySize);
  }
  return 0;
}
