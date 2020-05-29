#include "Functions.h"
#include <iomanip>
bool PredLess(int first, int second) { return first < second; }

bool PredGreater(int first, int second) { return first > second; }

bool PredLess(unsigned int first, unsigned int second) {
  return first < second;
}

bool PredGreater(unsigned int first, unsigned int second) {
  return first > second;
}

bool PredLess(double first, double second) { return first < second; }

bool PredGreater(double first, double second) { return first > second; }

bool PredLess(char first, char second) { return first < second; }

bool PredGreater(char first, char second) { return first > second; }

void swap(int &elOne, int &elTwo) {
  auto buf{elOne};
  elOne = elTwo;
  elTwo = buf;
}
void swap(unsigned int &elOne, unsigned int &elTwo) {
  auto buf{elOne};
  elOne = elTwo;
  elTwo = buf;
}
void swap(double &elOne, double &elTwo) {
  auto buf{elOne};
  elOne = elTwo;
  elTwo = buf;
}
void swap(char &elOne, char &elTwo) {
  auto buf{elOne};
  elOne = elTwo;
  elTwo = buf;
}

void output_array_range(unsigned int *begin, unsigned int *end) {
  if (begin == nullptr || end == nullptr)
    return;
  for (auto it = begin; it != end; ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}
void output_array_range(int *begin, int *end) {
  if (begin == nullptr || end == nullptr)
    return;
  for (auto it = begin; it != end; ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}
void output_array_range(double *begin, double *end) {
  if (begin == nullptr || end == nullptr)
    return;

  for (auto it = begin; it != end; ++it)
    std::cout << std::fixed << std::setprecision(2) << *it << " ";
  std::cout << std::endl;
}
void output_array_range(char *begin, char *end) {
  if (begin == nullptr || end == nullptr)
    return;
  for (auto it = begin; it != end; ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void fill_array(int *begin, int *end) {
  if (begin == nullptr || end == nullptr)
    return;
  int kMinRandomRange = 0;
  int kMaxRandomRange = 10;
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 rnd(seed);
  std::uniform_int_distribution<> rand_distribution(kMinRandomRange,
                                                    kMaxRandomRange);

  for (int *it{begin}; it != end; ++it) {
    *it = rand_distribution(rnd);
  }
}
void fill_array(unsigned int *begin, unsigned int *end) {
  if (begin == nullptr || end == nullptr)
    return;
  int kMinRandomRange = 0;
  int kMaxRandomRange = 10;
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 rnd(seed);
  std::uniform_int_distribution<> rand_distribution(kMinRandomRange,
                                                    kMaxRandomRange);

  for (auto *it{begin}; it != end; ++it) {
    *it = rand_distribution(rnd);
  }
}
void fill_array(double *begin, double *end) {
  if (begin == nullptr || end == nullptr)
    return;
  double kMinRandomRange = 0.0;
  double kMaxRandomRange = 10.0;
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 rnd(seed);
  std::uniform_real_distribution<> rand_distribution(kMinRandomRange,
                                                     kMaxRandomRange);

  for (auto *it{begin}; it != end; ++it) {
    *it = rand_distribution(rnd);
  }
}
void fill_array(char *begin, char *end) {
  if (begin == nullptr || end == nullptr)
    return;
  char kMinRandomRange = 65;
  char kMaxRandomRange = 122;
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 rnd(seed);
  std::uniform_int_distribution<> rand_distribution(kMinRandomRange,
                                                    kMaxRandomRange);

  for (auto it{begin}; it != end; ++it) {
    char letter = rand_distribution(rnd);
    if (letter <= 'Z' || letter >= 'a')
      *it = letter;
    else
      --it;
  }
}

void buble_sort(int *begin, int *end, Pred pred) {
  if (begin == nullptr || end == nullptr)
    return;
  int i = 1;
  for (auto outer_it = begin + 1; outer_it != end; ++outer_it, ++i) {
    for (auto inner_it = begin; inner_it != end - i; ++inner_it) {
      if (pred(*inner_it, *(inner_it + 1))) {
        swap(*inner_it, *(inner_it + 1));
      }
    }
  }
}
void buble_sort(unsigned int *begin, unsigned int *end, PredUI pred) {
  if (begin == nullptr || end == nullptr)
    return;
  int i = 1;
  for (auto outer_it = begin + 1; outer_it != end; ++outer_it, ++i) {
    for (auto inner_it = begin; inner_it != end - i; ++inner_it) {
      if (pred(*inner_it, *(inner_it + 1))) {
        swap(*inner_it, *(inner_it + 1));
      }
    }
  }
}
void buble_sort(double *begin, double *end, PredD pred) {
  if (begin == nullptr || end == nullptr)
    return;
  int i = 1;
  for (auto outer_it = begin + 1; outer_it != end; ++outer_it, ++i) {
    for (auto inner_it = begin; inner_it != end - i; ++inner_it) {
      if (pred(*inner_it, *(inner_it + 1))) {
        swap(*inner_it, *(inner_it + 1));
      }
    }
  }
}
void buble_sort(char *begin, char *end, PredC pred) {
  if (begin == nullptr || end == nullptr)
    return;
  int i = 0;
  for (auto outer_it = begin + 1; *outer_it != '\0'; ++outer_it, ++i) {
    for (auto inner_it = begin; *(inner_it + 1) != '\0'; ++inner_it) {
      if (pred(*inner_it, *(inner_it + 1))) {
        swap(*inner_it, *(inner_it + 1));
      }
    }
  }
}

void qSort(int *begin, int size, Pred pred) {
  if (begin == nullptr)
    return;
  auto checkingElement{*(begin + size / 2)};
  int i{0};
  int j{size - 1};
  do {
    while (pred(*(begin + i), checkingElement) &&
           *(begin + i) != checkingElement)
      ++i;
    while (!pred(*(begin + j), checkingElement) &&
           *(begin + j) != checkingElement)
      --j;
    if (i <= j) {
      if (*(begin + i) == *(begin + j)) {
        ++i;
        --j;
      } else {
        swap(*(begin + i), *(begin + j));
        ++i;
        --j;
      }
    }

  } while (i <= j);
  if (j > 0)
    qSort(begin, j + 1, pred);
  if (i < size)
    qSort((begin + i), size - i, pred);
}
void qSort(unsigned int *begin, int size, PredUI pred) {
  if (begin == nullptr)
    return;
  auto checkingElement{*(begin + size / 2)};
  int i{0};
  int j{size - 1};
  do {
    while (pred(*(begin + i), checkingElement) &&
           *(begin + i) != checkingElement)
      ++i;
    while (!pred(*(begin + j), checkingElement) &&
           *(begin + j) != checkingElement)
      --j;
    if (i <= j) {
      if (*(begin + i) == *(begin + j)) {
        ++i;
        --j;
      } else {
        swap(*(begin + i), *(begin + j));
        ++i;
        --j;
      }
    }

  } while (i <= j);
  if (j > 0)
    qSort(begin, j + 1, pred);
  if (i < size)
    qSort((begin + i), size - i, pred);
}
void qSort(double *begin, int size, PredD pred) {
  if (begin == nullptr)
    return;
  auto checkingElement{*(begin + size / 2)};
  int i{0};
  int j{size - 1};
  do {
    while (pred(*(begin + i), checkingElement) &&
           *(begin + i) != checkingElement)
      ++i;
    while (!pred(*(begin + j), checkingElement) &&
           *(begin + j) != checkingElement)
      --j;
    if (i <= j) {
      if (*(begin + i) == *(begin + j)) {
        ++i;
        --j;
      } else {
        swap(*(begin + i), *(begin + j));
        ++i;
        --j;
      }
    }

  } while (i <= j);
  if (j > 0)
    qSort(begin, j + 1, pred);
  if (i < size)
    qSort((begin + i), size - i, pred);
}
void qSort(char *begin, int size, PredC pred) {
  if (begin == nullptr)
    return;
  auto checkingElement{*(begin + size / 2)};
  int i{0};
  int j{size - 1};
  do {
    while (pred(*(begin + i), checkingElement) &&
           *(begin + i) != checkingElement)
      ++i;
    while (!pred(*(begin + j), checkingElement) &&
           *(begin + j) != checkingElement)
      --j;
    if (i <= j) {
      if (*(begin + i) == *(begin + j)) {
        ++i;
        --j;
      } else {
        swap(*(begin + i), *(begin + j));
        ++i;
        --j;
      }
    }

  } while (i <= j);
  if (j > 0)
    qSort(begin, j + 1, pred);
  if (i < size)
    qSort((begin + i), size - i, pred);
}

void TaskOneSortComparsion() {
  auto ArrayBegin = std::begin(ArrayToSort);
  auto ArrayEnd = std::end(ArrayToSort);
  int ArraySize = std::size(ArrayToSort);

  fill_array(ArrayBegin, ArrayEnd);

  output_array_range(ArrayBegin, ArrayBegin + kOutput);

  std::cout << "quick sort started: \n";
  auto start = std::chrono::high_resolution_clock::now();
  qSort(ArrayBegin, ArraySize, [](int a, int b) -> bool { return a < b; });
  auto stop = std::chrono::high_resolution_clock::now();

  std::cout
      << "Array sorted in  "
      << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count()
      << " seconds\n";
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
  std::cout << "\n\n";

  fill_array(ArrayBegin, ArrayEnd);
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
  std::cout << "Bubble sort started: \n";

  start = std::chrono::high_resolution_clock::now();
  buble_sort(ArrayBegin, ArrayEnd, PredGreater);
  stop = std::chrono::high_resolution_clock::now();

  std::cout
      << "Array sorted in  "
      << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count()
      << " seconds\n";
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
}

void TaskTwoSortUint() {
  auto ArrayBegin = std::begin(ArrayToSortUI);
  auto ArrayEnd = std::end(ArrayToSortUI);
  int ArraySize = std::size(ArrayToSortUI);

  fill_array(ArrayBegin, ArrayEnd);

  output_array_range(ArrayBegin, ArrayBegin + kOutput);

  std::cout << "quick sort started: \n";
  auto start = std::chrono::high_resolution_clock::now();
  qSort(ArrayBegin, ArraySize,
        [](unsigned a, unsigned b) -> bool { return a < b; });
  auto stop = std::chrono::high_resolution_clock::now();

  std::cout
      << "Array sorted in  "
      << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count()
      << " seconds\n";
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
  std::cout << "\n\n";

  fill_array(ArrayBegin, ArrayEnd);
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
  std::cout << "Bubble sort started: \n";

  start = std::chrono::high_resolution_clock::now();
  buble_sort(ArrayBegin, ArrayEnd, PredLess);
  stop = std::chrono::high_resolution_clock::now();

  std::cout
      << "Array sorted in  "
      << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count()
      << " seconds\n";
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
}

void TaskTwoSortDouble() {
  auto ArrayBegin = std::begin(ArrayToSortD);
  auto ArrayEnd = std::end(ArrayToSortD);
  int ArraySize = std::size(ArrayToSortD);

  fill_array(ArrayBegin, ArrayEnd);

  output_array_range(ArrayBegin, ArrayBegin + kOutput);

  std::cout << "quick sort started: \n";
  auto start = std::chrono::high_resolution_clock::now();
  qSort(ArrayBegin, ArraySize,
        [](double a, double b) -> bool { return a > b; });
  auto stop = std::chrono::high_resolution_clock::now();

  std::cout
      << "Array sorted in  "
      << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count()
      << " seconds\n";
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
  std::cout << "\n\n";

  fill_array(ArrayBegin, ArrayEnd);
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
  std::cout << "Bubble sort started: \n";

  start = std::chrono::high_resolution_clock::now();
  buble_sort(ArrayBegin, ArrayEnd, PredLess);
  stop = std::chrono::high_resolution_clock::now();

  std::cout
      << "Array sorted in  "
      << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count()
      << " seconds\n";
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
}

void TaskTwoSortChar() {
  auto ArrayBegin = std::begin(ArrayToSortC);
  auto ArrayEnd = std::end(ArrayToSortC);
  int ArraySize = std::size(ArrayToSortC);

  fill_array(ArrayBegin, ArrayEnd);

  output_array_range(ArrayBegin, ArrayBegin + kOutput);

  std::cout << "quick sort started: \n";
  auto start = std::chrono::high_resolution_clock::now();
  qSort(ArrayBegin, ArraySize, [](char a, char b) -> bool { return a < b; });
  auto stop = std::chrono::high_resolution_clock::now();

  std::cout
      << "Array sorted in  "
      << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count()
      << " seconds\n";
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
  std::cout << "\n\n";

  fill_array(ArrayBegin, ArrayEnd);
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
  std::cout << "Bubble sort started: \n";

  start = std::chrono::high_resolution_clock::now();
  buble_sort(ArrayBegin, ArrayEnd, PredGreater);
  stop = std::chrono::high_resolution_clock::now();

  std::cout
      << "Array sorted in  "
      << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count()
      << " seconds\n";
  output_array_range(ArrayBegin, ArrayBegin + kOutput);
}

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

void encrypt(char encryptMatrix[][kMatrixSize], char *string, int key) {
  const int kStringSize = strlen(string);
  int i{0};
  int j{0};
  int k{0};
  while (string[i] != '\0') {
    encryptMatrix[k][j] = string[i] ^ key;
    ++i;
    ++k;
    if (k > key - 1) {
      ++j;
      k = 0;
    }
  }
  j = 0;
  i = 0;
  k = 0;

  while (i != kStringSize) {

    while (encryptMatrix[k][j] != '\0') {
      string[i++] = encryptMatrix[k][j];
      j++;
    }

    j = 0;
    k++;
  }
  string[kStringSize] = '\0';
}

void decrypt(char encryptMatrix[][kMatrixSize], char *string, int key) {
  const int kStringSize = strlen(string);
  int i{0};
  int j{0};
  int k{0};

  while (i != kStringSize) {
    while (encryptMatrix[j][k] != '\0') {
      string[i++] = encryptMatrix[j][k] ^ key;
      j++;
    }

    j = 0;
    k++;
  }
}

void EncryptionTask() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  enum menu { Exit = 0, KeyEnter, Encrypt, Decrypt, Output };

  constexpr int kMaxStringSize{255};
  char string[kMaxStringSize]{};

  char cryptomatrix[kMatrixSize][kMatrixSize]{'\0'};
  std::cout << "Enter message\n";

  if (!checkString(string, kMaxStringSize)) {
    std::cout << "Error in string input\n";
    return;
  }

  int key{};
  while (true) {
    std::cout << "1. Enter key\n";
    std::cout << "2. Encrypt message\n";
    std::cout << "3. Decrypt message\n";
    std::cout << "4. Output message\n";
    std::cout << "0. Exit\n";
    int check{};
    std::cin >> check;
    switch (check) {
    case Exit:
      return;
    case KeyEnter:
      std::cin >> key;
      break;
    case Encrypt:
      encrypt(cryptomatrix, string, key);
      break;
    case Decrypt:
      decrypt(cryptomatrix, string, key);
      break;
    case Output:
      std::cout << string << std::endl;
    default:
      break;
    }
  }
}