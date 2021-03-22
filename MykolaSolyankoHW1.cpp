#include <iostream>

int main() {


  constexpr uint16_t kMin{100};
  constexpr uint16_t kMax{200};

  std::cout << "please input value [" << kMin << "..." << kMax << "]\n";
  uint32_t a{};
  std::cin >> a;

  if (a > kMax || a < kMin) { // true || false = true
    std::cout << "error input a\n";
    return -1;
  }

  std::cout << "please input value [" << kMin << "..." << kMax << "]\n";
  uint32_t c{};
  std::cin >> c;

  if (c > kMax || c < kMin) { // true || false = true
    std::cout << "error input c\n";
    return -1;
  }

  std::cout << "please input value [" << kMin << "..." << kMax << "]\n";
  uint32_t b{

  };
  std::cin >> b;

  if (b > kMax || b < kMin) { // true || false = true
    std::cout << "error input b\n";
    return -1;
  }

  return 0;
}
