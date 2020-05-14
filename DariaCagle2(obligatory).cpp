#include <iostream>

enum TASKS {
  SUMANDMEAN = 1,
  LUCKYTICKET,
  REVERSENUMBERS,
  SUMOFODD,
  BESTDIVISOR
};

void sumAndMean() {
  std::cout << "Enter any multidigital number:\n";
  int number;
  int i = 0;
  int sum = 0;
  std::cin >> number;
  while (number != 0) {
    int digit = number % 10;
    sum += digit;
    number = number / 10;
    ++i;
  }
  float mean = static_cast<float>(sum) / i;
  std::cout << sum << " " << mean << "\n";
}

void luckyTicket() {
  constexpr int kSix = 6;
  constexpr int kThousand = 1000;
  std::cout << "Enter a " << kSix << "-digit number:\n";
  int number;
  std::cin >> number;
  int number1 = number / kThousand;
  int number2 = number % kThousand;
  int sum1 = 0;
  while (number1 != 0) {
    int digit = number1 % 10;
    sum1 += digit;
    number1 = number1 / 10;
  }
  int sum2 = 0;
  while (number2 != 0) {
    int digit = number2 % 10;
    sum2 += digit;
    number2 = number2 / 10;
  }
  if (sum1 == sum2)
    std::cout << "This is a lucky ticket!\n";
  else {
    std::cout << "This is not a lucky ticket!\n";
  }
}

void reverseNumbers() {
  int64_t number;
  std::cout << "Enter any 32x signed number:\n";
  std::cin >> number;
  int digit;
  bool isNegative = number < 0;
  int64_t reverseNumber = 0;
  if (isNegative) {
    number = -number;
  }
  while (number != 0) {
    digit = number % 10;
    reverseNumber = reverseNumber * 10 + digit;
    number = number / 10;
  }
  if (isNegative) {
    reverseNumber = -reverseNumber;
  }
  std::cout << reverseNumber << "\n";
}

void sumOfOdd() {
  constexpr int kOne = 1;
  constexpr int kFifty = 50;
  constexpr int kSixty = 60;
  constexpr int kNinety = 90;
  int numberOfElements;
  do {
    std::cout << "Enter number of elements from " << kOne << " to " << kFifty
              << ":\n";
    std::cin >> numberOfElements;
  } while ((numberOfElements < kOne) || (numberOfElements > kFifty));
  std::cout << "Enter " << numberOfElements << " elements from " << -kSixty
            << " to " << kNinety << ":\n";
  int sum = 0;
  for (size_t i = 1; i <= numberOfElements; i++) {
    int element;
    std::cin >> element;
    while ((element < -kSixty) || (element > kNinety)) {
      std::cout << "Wrong range! Enter again:\n";
      std::cin >> element;
    }
    if (element % 2 == 1) {
      sum += element;
    }
  }
  std::cout << sum << "\n";
}

int sum(int number) {
  int sum = 0;
  while (number != 0) {
    int digit = number % 10;
    sum += digit;
    number = number / 10;
  }
  return sum;
}

void bestDivisor() {
  std::cout << "Enter a positive number:\n";
  int number;
  std::cin >> number;
  int bestDivisor = 0;
  for (int divisor = 1; divisor <= number; divisor++) {
    if ((number % divisor) == 0) {
      auto sum_digit_devisor = sum(divisor);
      if (sum_digit_devisor > bestDivisor) {
        bestDivisor = divisor;
      }
    }
  }
  std::cout << bestDivisor << "\n";
}

int main() {
  std::cout << "Choose a program:\n";
  std::cout << SUMANDMEAN << ". Sum and Mean\n";
  std::cout << LUCKYTICKET << ". Lucky Ticket\n";
  std::cout << REVERSENUMBERS << ". Reverse Numbers\n";
  std::cout << SUMOFODD << ". Sum of Odd Elements\n";
  std::cout << BESTDIVISOR << ". Best Divisor\n";
  std::cout << "Press any other key to exit\n";
  while (true) {
    std::cout << "Enter the desired number from " << SUMANDMEAN << " to "
              << BESTDIVISOR << "\n";
    int chosenProgram;
    std::cin >> chosenProgram;
    switch (chosenProgram) {
    case SUMANDMEAN:
      sumAndMean();
      break;
    case LUCKYTICKET:
      luckyTicket();
      break;
    case REVERSENUMBERS:
      reverseNumbers();
      break;
    case SUMOFODD:
      sumOfOdd();
      break;
    case BESTDIVISOR:
      bestDivisor();
      break;
    default:
      return 0;
    }
  }
}
