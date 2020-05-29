#include <iostream>
#include <random>

bool checkString(char *string, int maxSize) {
  if (string != nullptr) {
    while (true) {
      if (!std::cin.getline(string, maxSize)) {
        std::cout << "Error in string range, try again\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      } else if (*string != 0)
        return true;
      std::cout << "Empty string try again\n";
    }
  }
  return false;
}

void outputArray(int *begin, int *end) {
  if (begin == nullptr || end == nullptr)
    return;
  while (begin != end)
    std::cout << *begin++ << " ";
}

void TaskOneReverse() {
  // clear cin buffer after last input
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  constexpr int kMaxStringSize{255};
  char string[kMaxStringSize]{};
  std::cout << "Enter string less than " << kMaxStringSize << " symbol\n";

  if (!checkString(string, kMaxStringSize)) {
    std::cout << "Error in string input\n";
    return;
  }

  int endOfString = strlen(string) - 1;

  for (size_t i = 0; i < endOfString; i++, endOfString--) {
    char buf = string[i];
    string[i] = string[endOfString];
    string[endOfString] = buf;
  }
  std::cout << "Result string: " << string;
}

void TaskTwoInsertion() {
  constexpr int arrayMaxSize{5};
  int MyArray[arrayMaxSize]{};

  std::cout << "Enter array elements\n";
  for (size_t i = 0; i < arrayMaxSize; i++) {
    std::cin >> MyArray[i];
    for (int j = i; j > 0; j--) {
      if (MyArray[j] > MyArray[j - 1]) {
        break;
      }
      int buf = MyArray[j];
      MyArray[j] = MyArray[j - 1];
      MyArray[j - 1] = buf;
    }
  }

  int *MyArrayBegin = std::begin(MyArray);
  int *MyArrayEnd = std::end(MyArray);
  std::cout << "Array: [ ";
  outputArray(MyArrayBegin, MyArrayEnd);
  std::cout << "]\n";
}

void DeleteElement(int *array, int &arraySize) {
  int finder{};
  std::cout << "Enter element to find \n";
  std::cin >> finder;
  if (arraySize > 0) {
    for (size_t i = 0; i < arraySize; i++) {
      if (array[i] == finder) {
        for (size_t n = i; n < arraySize; n++)
          array[n] = array[n + 1];
        arraySize--;
        i--;
      }
    }
  } else
    std::cout << "No elements left\n";
}

void TaskThreeDeleteElement() {
  constexpr int maxArraySize = 10;
  int ArraySize = maxArraySize;
  int MyArray[maxArraySize]{};
  int maxRange{};
  int minRange{};
  std::cout << "Enter element max range\n";
  std::cin >> maxRange;
  std::cout << "Enter element min range\n";
  std::cin >> minRange;

  std::mt19937 rnd;
  std::uniform_int_distribution<> rand_distribution(minRange, maxRange);
  for (size_t i = 0; i < maxArraySize; i++) {
    MyArray[i] = rand_distribution(rnd);
  }

  int *MyArrayBegin = std::begin(MyArray);
  int *MyArrayEnd = MyArray + ArraySize;
  std::cout << "Generated array: [ ";
  outputArray(MyArrayBegin, MyArrayEnd);
  std::cout << "]\n";

  enum oportunity { exit = 0, deleteElement };
  int choise{};
  bool menu = true;
  while (menu) {
    if (ArraySize == 0)
      break;
    std::cout << "Choose what to do: \n";
    std::cout << "1. Delete element \n";
    std::cout << "0. Exit \n";
    std::cin >> choise;
    switch (choise) {
    case exit:
      menu = false;
      break;
    case deleteElement:
      DeleteElement(MyArray, ArraySize);
      break;
    }
  }

  MyArrayBegin = std::begin(MyArray);
  MyArrayEnd = MyArray + ArraySize;
  std::cout << "Result array: [ ";
  outputArray(MyArrayBegin, MyArrayEnd);
  std::cout << "]\n";
}

void TaskFourToUpper() {
  // clear cin buffer after last input
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  constexpr int kMaxStringSize{255};
  char string[kMaxStringSize]{};
  std::cout << "Enter string less than " << kMaxStringSize << " symbol\n";

  if (!checkString(string, kMaxStringSize)) {
    std::cout << "Error in string input\n";
    return;
  }

  int i{0};
  while (string[i]) {
    if (string[i] >= 'a' && string[i] <= 'z') {
      string[i] -= 32;
    }
    i++;
  }
  std::cout << "Result string: " << string << std::endl;
}

void TaskFiveisDigit() {
  // clear cin buffer after last input
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  constexpr int kMaxStringSize{255};
  char string[kMaxStringSize]{};
  std::cout << "Enter string less than " << kMaxStringSize << " symbol\n";

  if (!checkString(string, kMaxStringSize)) {
    std::cout << "Error in string input\n";
    return;
  }

  std::cout << "Digits in string [ ";
  for (size_t i = 0; string[i] != '\0'; i++) {
    if (string[i] >= '0' && string[i] <= '9')
      std::cout << string[i] << " ";
  }
  std::cout << "]\n";
}

void TaskSixToLower() {
  // clear cin buffer after last input
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  constexpr int kMaxStringSize{255};
  char string[kMaxStringSize]{};
  std::cout << "Enter string less than " << kMaxStringSize << " symbol\n";

  if (!checkString(string, kMaxStringSize)) {
    std::cout << "Error in string input\n";
    return;
  }

  int i{0};
  while (string[i]) {
    if (string[i] >= 'A' && string[i] <= 'Z') {
      string[i] += 32;
    }
    i++;
  }
  std::cout << "Result string: " << string << std::endl;
}

int main() {
  enum Tasks {
    ExitProgram = 0,
    TaskOneReverseStr,
    TaskTwoInsertionSort,
    TaskThreeDeleteElementFromArray,
    TaskFourToUpperStr,
    TaskFiveIsDigit,
    TaskSixtoLower
  };
  while (true) {
    int loop_state{};
    std::cout << "Choose your task:\n";
    std::cout << "1. Homework task one reverse string\n";
    std::cout << "2. Homework task two insertion sort\n";
    std::cout << "3. Homework task three delete element from array\n";
    std::cout << "4. Homework task four to upper\n";
    std::cout << "5. Homework task five is digit\n";
    std::cout << "6. Homework task six to lower\n";
    std::cout << "0. Exit\n";
    std::cin >> loop_state;
    switch (loop_state) {
    case Tasks::ExitProgram:
      return 0;
    case Tasks::TaskOneReverseStr:
      TaskOneReverse();
      break;
    case Tasks::TaskTwoInsertionSort:
      TaskTwoInsertion();
      break;
    case Tasks::TaskThreeDeleteElementFromArray:
      TaskThreeDeleteElement();
      break;
    case Tasks::TaskFourToUpperStr:
      TaskFourToUpper();
      break;
    case Tasks::TaskFiveIsDigit:
      TaskFiveisDigit();
      break;
    case Tasks::TaskSixtoLower:
      TaskSixToLower();
      break;
    default:
      std::cout << "There's no such option\n";
      break;
    }
    std::cout << std::endl;
  }
}