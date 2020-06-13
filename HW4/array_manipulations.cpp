#include "array_manupulations.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>

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

  for (auto it{begin}; it != end; ++it) {
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

  while (begin != end) {
    char letter = rand_distribution(rnd);
    if (letter <= 'Z' || letter >= 'a')
      *begin++ = letter;
  }
}
