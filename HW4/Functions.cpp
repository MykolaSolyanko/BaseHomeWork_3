#include "Constants.h"
#include "Functions.h"
#include "array_manupulations.h"
#include "encrypt.h"
#include "sort.h"
#include <chrono>
#include <iostream>

static bool PredLess(int first, int second) { return first < second; }

static bool PredGreater(int first, int second) { return first > second; }

static bool PredLess(unsigned int first, unsigned int second) {
  return first < second;
}

static bool PredGreater(unsigned int first, unsigned int second) {
  return first > second;
}

static bool PredLess(double first, double second) { return first < second; }

static bool PredGreater(double first, double second) { return first > second; }

static bool PredLess(char first, char second) { return first < second; }

static bool PredGreater(char first, char second) { return first > second; }

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

static bool checkString(char *string, int maxSize) {
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

void EncryptionTask() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  enum menu { Exit = 0, KeyEnter, Encrypt, Decrypt, Output };

  constexpr int kMaxStringSize{255};
  char string[kMaxStringSize]{};
  bool enc{};
  char cryptomatrix[kMatrixSize][kMatrixSize]{};
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
      enc = true;
      break;
    case Decrypt:
      if (enc == true) {
        decrypt(cryptomatrix, string, key);
        enc = false;
        break;
      }
      std::cout << "Message is not encrypted\n";
      break;
    case Output:
      std::cout << string << std::endl;
    default:
      break;
    }
  }
}