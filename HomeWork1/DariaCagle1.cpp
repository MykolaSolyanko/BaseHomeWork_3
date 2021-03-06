#include <cmath>
#include <iostream>

int main() {
  constexpr int kZero = 0;
  constexpr int kOne = 1;
  constexpr int kTwo = 2;
  constexpr int kFour = 4;
  constexpr int kHundred = 100;
  int64_t a;
  std::cout << "Enter a (integer that does not equal to " << kZero << "):\n";
  std::cin >> a;
  while (a == kZero) {
    std::cout << "You entered " << kZero
              << "! Enter any other integral number:\n";
    std::cin >> a;
  }
  int64_t b;
  std::cout << "Enter b (in range from " << kOne << " to " << kHundred
            << "):\n";
  std::cin >> b;
  while ((b < kOne) || (b > kHundred)) {
    std::cout
        << "You entered a number outside the given range! Enter a number from "
        << kOne << " to " << kHundred << ":\n";
    std::cin >> b;
  }
  int64_t c;
  std::cout << "Enter c (in range from " << -kHundred << " to " << -kOne
            << "):\n";
  std::cin >> c;
  while ((c < -kHundred) || (c > -kOne)) {
    std::cout
        << "You entered a number outside the given range! Enter a number from "
        << -kHundred << " to " << -kOne << ":\n";
    std::cin >> c;
  }
  int64_t d = b * b - (kFour * a * c);
  int doubleA = kTwo * a;
  if (d < kZero) {
    std::cout
        << "The discriminant is negative. No real square roots can be taken!\n";
  } else if (d == kZero) {
    std::cout << "The square root is " << -(static_cast<double>(b) / doubleA) << "\n";
  } else {
    std::cout << "The square roots are: \n";
    double x1 = (-(static_cast<double>(b)) + sqrt(d)) / doubleA;
    double x2 = (-(static_cast<double>(b)) - sqrt(d)) / doubleA;
    std::cout << "x1 = " << x1 << "\n";
    std::cout << "x2 = " << x2 << "\n";
  }
}
