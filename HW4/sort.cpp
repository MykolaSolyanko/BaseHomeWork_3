#include "Functions.h"
#include "sort.h"

auto swap = [](auto &elOne, auto &elTwo) {
  auto buf{elOne};
  elOne = elTwo;
  elTwo = buf;
};

void buble_sort(int *begin, int *end, Pred pred) {
  if (begin == nullptr || end == nullptr)
    return;
  int i = 1;
  for (auto outer_it = begin; outer_it != end; ++outer_it, ++i) {
    for (auto inner_it = outer_it; inner_it != end; ++inner_it) {
      if (pred(*outer_it, *(inner_it))) {
        swap(*outer_it, *(inner_it));
      }
    }
  }
}
void buble_sort(unsigned int *begin, unsigned int *end, PredUI pred) {
  if (begin == nullptr || end == nullptr)
    return;
  int i = 1;
  for (auto outer_it = begin; outer_it != end; ++outer_it, ++i) {
    for (auto inner_it = outer_it; inner_it != end; ++inner_it) {
      if (pred(*outer_it, *(inner_it))) {
        swap(*outer_it, *(inner_it));
      }
    }
  }
}
void buble_sort(double *begin, double *end, PredD pred) {
  if (begin == nullptr || end == nullptr)
    return;
  int i = 1;
  for (auto outer_it = begin; outer_it != end; ++outer_it, ++i) {
    for (auto inner_it = outer_it; inner_it != end; ++inner_it) {
      if (pred(*outer_it, *(inner_it))) {
        swap(*outer_it, *(inner_it));
      }
    }
  }
}
void buble_sort(char *begin, char *end, PredC pred) {
  if (begin == nullptr || end == nullptr)
    return;
  int i = 0;
  for (auto outer_it = begin; outer_it != end; ++outer_it, ++i) {
    for (auto inner_it = outer_it; inner_it != end; ++inner_it) {
      if (pred(*outer_it, *(inner_it))) {
        swap(*outer_it, *(inner_it));
      }
    }
  }
}

void qSort(int *begin, int size, Pred pred) {
  if (begin == nullptr || size < 0)
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
  if (begin == nullptr || size < 0)
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
