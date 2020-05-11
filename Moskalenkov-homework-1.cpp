#include <cmath>
#include <iostream>

int main() {
  constexpr int kMin{-100};
  constexpr int kMax{100};

  std::cout << "Enter any integer, from -100 to +100, except 0: " << std::endl;
  int a;
  std::cin >> a;
  while (a == 0 || a < kMin || a > kMax) {
    std::cout << "The number entered is incorrect. Start over" << std::endl;
    std::cout << "Enter any integer, from -100 to +100, except 0: "
              << std::endl;
    std::cin >> a;
  }

  int b;
  std::cin >> b;
  while (b == 0 || b < kMin || b > kMax) {
    std::cout << "The number entered is incorrect. Start over" << std::endl;
    std::cout << "Enter any integer, from -100 to +100, except 0: "
              << std::endl;
    std::cin >> b;
  }
  int c;
  std::cin >> c;
  while (c == 0 || c < kMin || c > kMax) {
    std::cout << "The number entered is incorrect. Start over" << std::endl;
    std::cout << "Enter any integer, from -100 to +100, except 0: "
              << std::endl;
    std::cin >> c;
  }
  std::cout << "You entered" << std::endl;
  std::cout << "a=" << a << " b=" << b << " c=" << c << std::endl;

  const int64_t D = (b * b) - (4 * a * c);

  std::cout << "D=" << D << std::endl;

  double x1;
  double x2;

  if (D > 0) {
    x1 = (-b + sqrt(D)) / (2 * a);
    x2 = (-b - sqrt(D)) / (2 * a);
    std::cout << "X1=" << x1 << std::endl;
    std::cout << "X2=" << x2 << std::endl;
  } else if (D == 0) {
    x1 = (-b + sqrt(D)) / (2 * a);

    std::cout << "X1=X2=" << x1 << std::endl;
  } else
    std::cout << "The equation has no roots" << std::endl;

  return 0;
}
