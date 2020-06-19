#include <iostream>

enum TASKS { REVERSESTR = 1, ARRINSERT };

void reverseString() {
  std::cout << "Input a string:\n";
  char arr[255]{};
  std::cin >> arr;
  int length = strlen(arr);
  for (int ch = 0; ch < length/2; ch++) {
    int tmp = arr[length - ch - 1];
    arr[length - ch - 1] = arr[ch];
    arr[ch] = tmp;
  }
  std::cout << arr << "\n";
}

void insertInArray() {
  constexpr int length = 5;
  int arr[length]{};
  for (int countZero {0}; countZero < length, countZero++) {
    std::cout << "Input a number:\n";
    int number;
    std::cin >> number;
    arr[i] = number;
    for (int i = countZero; i > 0; i--;) {
      if (arr[i] < arr[i - 1]) {
        int temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
      }
    }
  }
  for (int i = 0; i < length; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

int main() {
  std::cout << "Choose a program:\n";
  std::cout << REVERSESTR << ". Reverse string\n";
  std::cout << ARRINSERT << ". Array construction\n";
  std::cout << "Press any other key to exit\n";
  while (true) {
    std::cout << "Enter the desired number from " << REVERSESTR << " to "
              << ARRINSERT << "\n";
    int chosenProgram;
    std::cin >> chosenProgram;
    switch (chosenProgram) {
    case REVERSESTR:
      reverseString();
      break;
    case ARRINSERT:
      insertInArray();
      break;
    default:
      return 0;
    }
  }
}
