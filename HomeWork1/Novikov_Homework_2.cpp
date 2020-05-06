#include <cmath>
#include <iostream>

void Task_1_average_numbers();
void Task_2_lucky_ticket();
void Task_3_number_reverce();
void Task_4_odd_numbers();
void Task_5_best_divider();
void Task_6_christmas_tree();
void Task_7_bit_count();
void Task_8_bit_set();
void Task_9_number_builder();

int main() {

  std::cout << "Homework task one average of digits\n";
  Task_1_average_numbers();

  std::cout << "Homework task two lucky ticket\n";
  Task_2_lucky_ticket();

  std::cout << "Homework task three reverse number\n";
  Task_3_number_reverce();

  std::cout << "Homework task four sum of odd elements\n";
  Task_4_odd_numbers();

  std::cout << "Homework task five the best divider\n";
  Task_5_best_divider();

  std::cout << "Homework task six christmas tree\n";
  Task_6_christmas_tree();

  std::cout << "Homework task seven number of set bits\n";
  Task_7_bit_count();

  std::cout << "Homework task eight check state of bit number\n";
  Task_8_bit_set();

  std::cout << "Homework task nine number building\n";
  Task_9_number_builder();
}

int sum_counter(int number) {
  int result{0};
  while (number) {
    result += (number % 10);
    number /= 10;
  }
  return result;
}

void Task_1_average_numbers() {
  int number{0};
  std::cout << "Enter your number: ";
  std::cin >> number;

  if (number == 0) {
    std::cout << "Number is zero";
    return;
  }

  const int numberOfDigits = static_cast<int>(log10(number)) + 1; // math magic

  if (numberOfDigits == 1) {
    std::cout << "Average is " << number << std::endl;
    return;
  }

  float average{0.0};
  while (number) {
    average += (number % 10) / static_cast<float>(numberOfDigits);
    number /= 10;
  }

  std::cout << "Average is " << average << std::endl;
}

void Task_2_lucky_ticket() {
  bool check{true};
  int number;
  int digitsNumber{0};
  while (check) {
    std::cout << "Enter 6-digit number" << std::endl;
    std::cin >> number;
    if (number == 0) {
      std::cout << "Number is zero\n";
      continue;
    }
    digitsNumber = static_cast<int>(log10(number)) + 1;

    if (digitsNumber != 6) {
      std::cout << "Number is not 6-digit! Please try again!\n";
      continue;
    } else
      check = false;
  }

  int left{0};
  int right{0};
  const int divider = digitsNumber / 2.0;
  while (number) {
    if (digitsNumber > divider) {
      right += number % 10;
    } else {
      left += number % 10;
    }
    number /= 10;
    digitsNumber--;
  }

  if (left == right)
    std::cout << "It's your lucky ticket!\n";
  else
    std::cout << "It's not a lucky ticket!\n";
}

void Task_3_number_reverce() {
  int32_t number{0};
  int32_t reverse_number{0};
  constexpr int kTen{10};
  std::cout << "Enter number: ";
  std::cin >> number;

  while (number) {
    reverse_number = kTen * reverse_number + number % 10;
    number /= 10;
  }

  std::cout << "Result is: " << reverse_number << std::endl;
}

void Task_4_odd_numbers() {
  constexpr int kRangeArraySizeLow{1};
  constexpr int kRangeArraySizeHigh{50};
  constexpr int kRangeArrayElementLow{-60};
  constexpr int kRangeArrayElementHigh{90};

  int elementsNumber{0};
  int elements[50]{0};
  bool check{true};

  while (check) {
    std::cout << "Enter number of elements [1..50]: ";
    std::cin >> elementsNumber;
    if (elementsNumber < kRangeArraySizeLow ||
        elementsNumber > kRangeArraySizeHigh) {
      std::cout << "Number is not in range! Please try again\n";
      continue;
    }
    check = false;
  }

  std::cout << "Enter elements in range [-60..90]\n";
  for (int i = 0; i < elementsNumber;) {
    std::cin >> elements[i];
    if (elements[i] <= kRangeArrayElementLow ||
        elements[i] >= kRangeArraySizeHigh) {
      std::cout << "Element is not in range! Please try again\n";
      continue;
    }
    i++;
  }

  int oddSum{0};

  for (int i = 0; i < elementsNumber; i++)
    if (elements[i] & 1)
      oddSum += elements[i];

  std::cout << "Sum of odd elements: " << oddSum << std::endl;
}

int sum_i(int number) {
  if (number < 10)
    return number;
  else {
    int sum{0};
    sum = sum_counter(number);
    return sum;
  }
}

void Task_5_best_divider() {

  int number{0};

  std::cout << "Enter a number ";
  std::cin >> number;

  if (number < 0)
    number *= -1;

  int best = 0;
  std::cout << "Dividers = { ";
  for (int i = 1; i <= number; i++)
    if (number % i == 0) {
      if (sum_i(best) <= sum_i(i))
        best = i;
      std::cout << i << " ";
    }
  std::cout << "}\n";

  std::cout << "The best divider is: " << best << std::endl;
}

void Task_6_christmas_tree() {
  int number{0};
  int star{1};

  std::cout << "Enter number: ";
  std::cin >> number;

  int spaces = number / 2;
  while (star <= number + 1) {
    for (int i = 0; i < spaces; i++)
      std::cout << " ";
    for (int i = 0; i < star; i++)
      std::cout << "*";
    std::cout << std::endl;
    star += 2;
    spaces--;
  }
}

void Task_7_bit_count() {
  int number{0};

  std::cout << "Enter number: ";
  std::cin >> number;
  std::cout << std::endl;

  int checker{1};
  int sum_of_bits{0};
  for (int i = 0; i < sizeof(int) * 8; i++) {
    if (number & checker)
      sum_of_bits++;
    checker <<= 1;
  }

  std::cout << "NUmber of set bits is: " << sum_of_bits << std::endl;
}

void Task_8_bit_set() {
  int number{0};

  std::cout << "Enter number: ";
  std::cin >> number;
  std::cout << std::endl;

  int checker{0};
  std::cout << "Enter bit number to check: ";
  std::cin >> checker;
  std::cout << std::endl;

  constexpr int mask{1};
  if (number & checker << mask)
    std::cout << "Bit is set\n";
  else
    std::cout << "Bit is not set\n";
}

void Task_9_number_builder() {
  int number_count{0};
  int number{0};

  std::cout << "Enter count of numbers: ";
  std::cin >> number_count;
  std::cout << std::endl;

  int sum_of_digits{0};
  for (int i = 0; i < number_count; i++) {
    std::cout << "Enter number " << i << std::endl;
    std::cin >> number;

    sum_of_digits = sum_counter(number);
  }

  if (sum_of_digits % 3 == 0)
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
}