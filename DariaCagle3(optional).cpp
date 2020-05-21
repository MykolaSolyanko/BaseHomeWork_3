#include <ctime>
#include <iostream>
#include <random>

enum TASKS { DELETE = 1, UPPER, DIGIT, LOWER };

constexpr int kCodeDif{32};

void deleteItem() {
  constexpr int length{5};
  int array[length]{};
  constexpr int min{1};
  constexpr int max{20};
  std::mt19937 gen(time(0));
  std::uniform_int_distribution<> num(min, max);
  for (int i{0}; i < length; i++) {
    array[i] = num(gen);
  }
  int count = length;
  do {
    std::cout << "Input a number from " << min << " to " << max << std::endl;
    int number{};
    std::cin >> number;
    for (int i{0}; i < length; i++) {
      if (number == array[i]) {
        array[i] = 0;
        count--;
      }
    }

  } while (count > 0);
  std::cout << "You guessed all the numbers! The array is empty.\n";
}

void toUpper() {
  std::cout << "Enter a sentence:\n";
  char sentence[255]{};
  std::cin >> sentence;
  int length{0};
  for (length; sentence[length] != '\0'; length++)
    ;
  for (int i = 0; i < length; i++) {
    int code = static_cast<int>(sentence[i]);
    if ((code > 96) && (code < 123)) {
      std::cout << char(code - kCodeDif);
    } else {
      std::cout << sentence[i];
    }
  }
  std::cout << '\n';
}

bool isDigit(char letter) {
  int code = static_cast<int>(letter);
  if ((code > 47) && (code < 58)) {
    return true;
  } else {
    return false;
  }
}

void findDigit() {
  std::cout << "Enter a sentence:\n";
  char sentence[255]{};
  std::cin >> sentence;
  int length{0};
  for (length; sentence[length] != '\0'; length++)
    ;
  for (int i = 0; i < length; i++) {
    bool digit = isDigit(sentence[i]);
    if (digit == true) {
      std::cout << sentence[i] << " ";
    }
  }
  std::cout << '\n';
}

void toLower() {
  std::cout << "Enter a sentence:\n";
  char sentence[255]{};
  std::cin >> sentence;
  int length{0};
  for (length; sentence[length] != '\0'; length++)
    ;
  for (int i = 0; i < length; i++) {
    int code = static_cast<int>(sentence[i]);
    if ((code > 64) && (code < 91)) {
      std::cout << char(code + kCodeDif);
    } else {
      std::cout << sentence[i];
    }
  }
  std::cout << '\n';
}

int main() {
  std::cout << "Choose a program:\n";
  std::cout << DELETE << ". Delete an item\n";
  std::cout << UPPER << ". Make it uppercase\n";
  std::cout << DIGIT << ". Find a digit\n";
  std::cout << LOWER << ". Make it lower\n";
  std::cout << "Press any other key to exit\n";
  while (true) {
    std::cout << "Enter the desired number from " << DELETE << " to " << LOWER
              << "\n";
    int chosenProgram;
    std::cin >> chosenProgram;
    switch (chosenProgram) {
    case DELETE:
      deleteItem();
      break;
    case UPPER:
      toUpper();
      break;
    case DIGIT:
      findDigit();
      break;
    case LOWER:
      toLower();
      break;
    default:
      return 0;
    }
  }
}
