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
  int countZero = length;
  while (countZero > 0) {
    std::cout << "Input a number:\n";
    int number;
    std::cin >> number;
    if (number == 0) {
      continue;
    }
    int i = 0;
    while (arr[i] != 0) {
      if (number < arr[i]) {
        break;
      } else {
        i++;
      }
    }
    int newVal = length - 1;
    while (newVal > i) {
      arr[newVal] = arr[newVal - 1];
      newVal--;
    }
    arr[i] = number;
    countZero--;
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
