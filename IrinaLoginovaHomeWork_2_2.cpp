#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdexcept>

int main() {
    int array_NubmerTicket[6];
    constexpr int MinRange = 1, MaxRange = 9;
    std::cout << "Please enter 6 digits of your ticket. Numbers ranging from "
        << MinRange << " to " << MaxRange << std::endl;
    for (size_t i = 0; i <= 5; ++i) {
        std::cout << "Number is --> " << std::endl;
        std::cin >> array_NubmerTicket[i];
        while (array_NubmerTicket[i] == 0 || array_NubmerTicket[i] < MinRange ||
            array_NubmerTicket[i] > MaxRange) {
            std::cout << "You entered an invalid number. Repeat a number in the "
                "correct range"
                << std::endl;
            std::cout << "Number is --> " << std::endl;
            std::cin >> array_NubmerTicket[i];
        }
    }
    int sum_1 = {};
    int sum_2 = {};
    for (size_t i = 0; i <= 2; ++i) {
        sum_1 = sum_1 + array_NubmerTicket[i];
    }
    for (size_t i = 3; i <= 5; ++i) {
        sum_2 = sum_2 + array_NubmerTicket[i];
    }
    if (sum_1 != sum_2) {
        std::cout << "You NO have a lucky ticket." << std::endl;
    }
    else {
        std::cout << "You have a lucky ticket." << std::endl;
    }
    return 0;
}
