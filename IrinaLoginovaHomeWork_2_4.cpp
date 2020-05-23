
#include <iostream>

int main() {
    constexpr int Valume = { 50 };
    constexpr int MinRange = { -60 };
    constexpr int MaxRange = { 90 };
    std::cout << "Please enter numbers for an array of " << Valume
        << " elements. Numbers must be in the range of " << MinRange
        << " to " << MaxRange << std::endl;
    std::cout << "Enter the numbers: " << std::endl;
    int32_t Numbers = {};
    int SumUneven = {};
    for (size_t i = 1; i <= Valume; ++i) {
        std::cout << "---> ";
        std::cin >> Numbers;
        while (Numbers == 0 || Numbers < MinRange || Numbers > MaxRange) {
            std::cout << "You entered an invalid number. Re-enter the number in the "
                "range "
                << MinRange << " to " << MaxRange << std::endl;
            std::cout << "---> ";
            std::cin >> Numbers;
        }
        if (Numbers & 1) {
            SumUneven += Numbers;
        }
    }
    std::cout << SumUneven << std::endl;
    return 0;
}
