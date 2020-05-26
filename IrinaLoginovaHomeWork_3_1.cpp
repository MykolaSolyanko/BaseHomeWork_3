#include <cstdint>
#include <cstring>
#include <iostream>

int main() {
  constexpr int n = {150};
  char ArrayString[n] = {};
  std::cout << "Please enter your string no more than " << n << " characters."
            << std::endl;
  std::cout << "--->";
  std::cin.getline(ArrayString, n);
  int LengthArrayString = strlen(ArrayString);
  for (int i = LengthArrayString; i >= 0; i--) {
    std::cout << ArrayString[i];
  }
  return 0;
}
