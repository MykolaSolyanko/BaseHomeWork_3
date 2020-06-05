#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

void ArrayOut(int Array[], int ArraySize) {
  std::cout << " Array is - ";
  for (int i = 0; i < ArraySize; i++) {
    std::cout << " " << Array[i] << " ";
  }
}

void ArrayUser(int Array[], int ArraySize) {
  for (int i = 0; i < ArraySize; i++) {
    std::cout << "Enter the number --> ";
    std::cin >> Array[i];
  }
}

void ArrayRandom(int Array[], int ArraySize) {
  for (int i = 0; i < ArraySize; i++) {
    Array[i] = rand();
  }
}

void DelElementArray(int Array[], int ArraySize, int Number) {
  for (int i = 0; i < ArraySize; i++) {
    if (Array[i] == Number) {
      int Tmp = Array[i];
      Array[i] = Array[ArraySize - 1];
      Array[ArraySize - 1] = Tmp;
      break;
    }
  }
}

int main() //Программа удаления элемента из массива
{
  const size_t ArraySize = {4};
  int Array[ArraySize]{7, 13, 27, 29};
  std::cout << "Please select an array fill option." << std::endl;
  std::cout << "Enter 1 - if you enter the numbers manually." << std::endl;
  std::cout << "Enter 2 - random number generator." << std::endl;
  std::cout << "Enter 3 - ready list" << std::endl;
  std::cout << "---> ";
  int UserChoice{0};
  std::cin >> UserChoice;
  switch (UserChoice) {
  case 1:
    ArrayUser(Array, ArraySize);
    break;
  case 2:
    ArrayRandom(Array, ArraySize);
    break;
  case 3:
    break;
  default:
    std::cout << "You entered the wrong option. Try it next year." << std::endl;
    return 0;
  }
  ArrayOut(Array, ArraySize);
  int DelSize = ArraySize;
  for (int i = 0; i < ArraySize; i++) {
    // ArrayOut(Array, DelSize--);
    std::cout << "Choose a number to delete" << std::endl;
    std::cout << "--> ";
    int Number;
    std::cin >> Number;
    DelElementArray(Array, DelSize, Number);
    DelSize--;
    ArrayOut(Array, DelSize);
  }
  std::cout << "Thank you for your cooperation. Bye.";
  return 0;
}
