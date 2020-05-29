#include "Functions.h"

int main() {
  enum Tasks {
    ExitProgram = 0,
    TaskOneSortCompare,
    TaskTwoSortForUint,
    TaskTwoSortForDouble,
    TaskTwoSortForChar,
    TaskThreeEncryption
  };

  while (true) {
    int loop_state{};
    std::cout << "Choose your task:\n";
    std::cout << "1. Homework task one sort comparsion\n";
    std::cout << "2. Homework task two sort for uint\n";
    std::cout << "3. Homework task two sort for double\n";
    std::cout << "4. Homework task two sort for char\n";
    std::cout << "5. Homework task three Encrypt message\n";
    std::cout << "0. Exit\n";
    std::cin >> loop_state;
    switch (loop_state) {
    case Tasks::ExitProgram:
      return 0;
    case Tasks::TaskOneSortCompare:
      TaskOneSortComparsion();
      break;
    case Tasks::TaskTwoSortForUint:
      TaskTwoSortUint();
      break;
    case Tasks::TaskTwoSortForDouble:
      TaskTwoSortDouble();
      break;
    case Tasks::TaskTwoSortForChar:
      TaskTwoSortChar();
      break;
    case Tasks::TaskThreeEncryption:
      EncryptionTask();
      break;
    }
  }
}