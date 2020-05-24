#include <iostream>
enum { Herringbone = 1, NumberOfSetBits, IsTheBitSet, NumberConstruction };
int main() {
    std::cout << "What task to perform?" << std::endl;
    int num{};
    while (num > NumberConstruction || num < Herringbone) {
        std::cout << Herringbone << " Herringbone" << std::endl;
        std::cout << NumberOfSetBits << " Count the number of set bits in a number"
            << std::endl;
        std::cout << IsTheBitSet << " Is the bit set" << std::endl;
        std::cout << NumberConstruction << " Number construction" << std::endl;
        std::cin >> num;
        if (num == Herringbone) {
            std::cout << "Enter the number of the base of the herringbone "
                << std::endl;
            int number{ 0 };
            std::cin >> number;
            int star{ 0 };
            for (number; number >= 0; number -= 2) {

                for (int space(number / 2); space > 0; space--) {
                    std::cout << " ";
                }
                for (int i{ 0 }; i <= star; i++) {
                    std::cout << "*";
                }
                std::cout << "" << std::endl;
                star += 2;
            }
        }
        else if (num == NumberOfSetBits) {
            std::cout
                << "Enter the number in which you want to count the number of bits :"
                << std::endl;
            int number;
            std::cin >> number;
            int sum{};
            constexpr int kIntBit = sizeof(int) * 8;
            for (size_t i{}; i < kIntBit; i++) {
                if (number & (1 << i)) {
                    ++sum;
                }
            }
            std::cout << "Quantity bits in number " << sum << std::endl;
        }
        else if (num == IsTheBitSet) {
            std::cout << "Enter the number in which you will check the set bit: "
                << std::endl;
            int number;
            std::cin >> number;
            std::cout << "What bit will we check ? " << std::endl;
            size_t i{};
            std::cin >> i;
            if (number & (1 << i)) {
                std::cout << "Yes" << std::endl;
            }
            else {
                std::cout << "No" << std::endl;
            }

        }
        else if (num == NumberConstruction) {
            std::cout << "How many numbers will you enter?" << std::endl;
            int quantity{ 0 };
            std::cin >> quantity;
            std::cout << "Enter numbers" << std::endl;
            int number{ 0 };
            int sum{ 0 };
            for (int i{ 0 }; i < quantity; i++) {
                std::cin >> number;
                sum = sum + number;
            }
            if (sum % 3 == 0) {
                std::cout << "Yes" << std::endl;
            }
            else
                std::cout << "No" << std::endl;
        }
    }
    return 0;
}
