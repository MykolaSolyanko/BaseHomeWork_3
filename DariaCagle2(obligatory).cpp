#include <iostream>

enum {
  kOne = 1,
  kTwo,
  kThree,
  kFour,
  kFive,
  kSix,
  kTen = 10,
  kFifty = 50,
  kSixty = 60,
  kNinety = 90,
  kThousand = 1000,
  kZero = 0
};

enum TASKS {
  SUMANDMEAN = 1,
  LUCKYTICKET,
  REVERSENUMBERS,
  SUMOFODD,
  BESTDIVISOR
}

void sumAndMean() {
  std::cout << "Enter any multidigital number:\n";
  int number;
  int i = kZero;
  int sum = kZero;
  std::cin >> number;
  while (number != kZero) {
    int digit = number % kTen;
    sum += digit;
    number = (number - (number % kTen)) / kTen;
    ++i;
  }
  float mean = static_cast<float>(sum) / i;
  std::cout << sum << " " << mean << "\n";
}

void luckyTicket() {
  std::cout << "Enter a " << kSix << "-digit number:\n";
  int number;
  std::cin >> number;
  int number1 = (number - (number % kThousand)) / kThousand;
  int number2 = number % kThousand;
  int sum1 = kZero;
  while (number1 != kZero) {
    int digit = number1 % kTen;
    sum1 += digit;
    number1 = (number1 - (number1 % kTen)) / kTen;
  }
  int sum2 = kZero;
  while (number2 != kZero) {
    int digit = number2 % kTen;
    sum2 += digit;
    number2 = (number2 - (number2 % kTen)) / kTen;
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
  int64_t reverseNumber = kZero;
  if (number == -number) {
    while (number != kZero) {
      digit = number % kTen;
      reverseNumber = reverseNumber * kTen + digit;
      number = (number - (number % kTen)) / kTen;
    }
    std::cout << reverseNumber << "\n";
  } else {
    number = abs(number);
    while (number != kZero) {
      digit = number % kTen;
      reverseNumber = reverseNumber * kTen + digit;
      number = (number - (number % kTen)) / kTen;
    }
    std::cout << -reverseNumber << "\n";
  }
}

void sumOfOdd() {
  int numberOfElements;
  do {
    std::cout << "Enter number of elements from " << kOne << " to " << kFifty
              << ":\n";
    std::cin >> numberOfElements;
  } while ((numberOfElements < kOne) || (numberOfElements > kFifty));
  std::cout << "Enter " << numberOfElements << " elements from " << -kSixty
            << " to " << kNinety << ":\n";
  int sum = 0;
  for (size_t i = kOne; i <= numberOfElements; i++) {
    int element;
    std::cin >> element;
    while ((element < -kSixty) || (element > kNinety)) {
      std::cout << "Wrong range! Enter again:\n";
      std::cin >> element;
    }
    if (element % kTwo == kOne) {
      sum += element;
    }
  }
  std::cout << sum << "\n";
}

int sum(int number) {
  int sum = kZero;
  while (number != kZero) {
    int digit = number % kTen;
    sum += digit;
    number = (number - (number % kTen)) / kTen;
  }
  return sum;
}

void bestDivisor() {
  std::cout << "Enter a positive number:\n";
  int number;
  std::cin >> number;
  int bestDivisor = kZero;
  for (int divisor = kOne; divisor <= number; divisor++) {
    if ((number % divisor) == kZero) {
      auto sum_digit_devisor = sum(divisor);
      if (sum_digit_devisor > bestDivisor) {
      bestDivisor = sum_digit_devisor;
      }
    }
  }
  std::cout << bestDivisor << "\n";
}

int main() {
  std::cout << "Choose a program:\n";
  std::cout << kOne << ". Sum and Mean\n";
  std::cout << kTwo << ". Lucky Ticket\n";
  std::cout << kThree << ". Reverse Numbers\n";
  std::cout << kFour << ". Sum of Odd Elements\n";
  std::cout << kFive << ". Best Divisor\n";
  std::cout << "Press any other key to exit\n";
  while (true) {
    std::cout << "Enter the desired number from " << kOne << " to " << kFive
              << "\n";
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
