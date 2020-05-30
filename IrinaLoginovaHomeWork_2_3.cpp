#include <cmath>
#include <iostream>
#include <stdexcept>

int main() {
    std::cout << "Please enter a number and we will reverse it --> ";
    int32_t number{};
    std::cin >> number;
    if (number < 0) {
        std::cout << "Reverse = -";
    }
    else {
        std::cout << "Reverse = ";
    }
    number = abs(number);
    int x = number % 10;  
    int32_t ReverseNumber{};
    ReverseNumber = x;
    while (x > 0) {
        number = (number - x) / 10;
        x = number % 10;
        if (x == 0) {
            std::cout << ReverseNumber << std::endl;
        }
        ReverseNumber = (ReverseNumber * 10) + x;
    }
    return 0;
}
