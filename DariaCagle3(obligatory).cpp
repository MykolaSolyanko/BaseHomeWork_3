#include <iostream>

enum TASKS { REVERSESTR = 1, ARRINSERT };

void reverseString() {
  std::cout << "Input a string:\n";
  char arr[255]{};
  std::cin >> arr;
  int length = strlen(arr);
  char revArr[255]{};
  for (int ch = 0; ch < length; ch++) {
    revArr[ch] = arr[length - ch - 1];
  }
  std::cout << revArr << "\n";
}

void insertInArray() {
  constexpr int length = 5;
  int arr[length]{};
  int countZero = 0;
  while (countZero < length) {
    std::cout << "Input a number:\n";
    int number;
    std::cin >> number;
    int i = countZero;
    arr[i] = number;
    while (i > 0) {
      if (arr[i] < arr[i - 1]) {
        int temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
      }
      i--;
    }
    countZero++;
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
