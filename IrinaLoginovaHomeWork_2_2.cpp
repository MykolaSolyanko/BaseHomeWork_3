#include <iostream>
#include <stdexcept>

int main() {
    int NumberTicket{};
    constexpr int MinRange = 1, MaxRange = 9;
    std::cout << "Please enter 6 numbers of your ticket through Enter. Numbers "
        "ranging from "
        << MinRange << " to " << MaxRange << std::endl;
    int sum_1 = {};
    int sum_2 = {};
    for (size_t i = 1; i < 4; ++i) {
        std::cout << "Number is --> " << std::endl;
        std::cin >> NumberTicket;
        sum_1 += NumberTicket;
    }
    for (size_t i = 4; i < 7; ++i) {
        std::cout << "Number is --> " << std::endl;
        std::cin >> NumberTicket;
        sum_2 += NumberTicket;
    }
    if (sum_1 != sum_2) {
        std::cout << "Congratulations! You NO have a lucky ticket." << std::endl;
    }
    else {
        std::cout << "Congratulations! You have a lucky ticket." << std::endl;
    }
    return 0;
}
