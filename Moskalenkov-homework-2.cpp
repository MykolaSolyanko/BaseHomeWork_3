#include <iostream>

int main() {
    std::cout << "What task do you want to solve ?" << std::endl;

    int setNumber(0);

    while (setNumber < 1 || setNumber > 5) {
        std::cout
            << "1: Calculate the sum and arithmetic mean of digits in the number"
            << std::endl;
        std::cout << "2: Lucky ticket " << std::endl;
        std::cout << "3: Inverse numbers " << std::endl;
        std::cout << "4: Sum of odd elements " << std::endl;
        std::cout << "5: Best divisor " << std::endl;
        std::cin >> setNumber;
    }
    if (setNumber == 1) {
        int number(0);
        int sum(0);
        int i(0);
        std::cout << "Enter number: " << std::endl;
        std::cin >> number;
        while (number != 0) {
            sum = sum + (number % 10);
            number = number / 10;
            ++i;
        };
        float result = static_cast<float>(sum) / i;

        std::cout << sum << std::endl;
        std::cout << result << std::endl;
    }

    else if (setNumber == 2) {
        int number(0);
        int sum1(0);
        int sum2(0);
        constexpr int kRangeMax{ 1000000 };
        constexpr int kRangeMin{ 100000 };

        std::cout << "Enter a six digit number: " << std::endl;
        std::cin >> number;
        if (number < kRangeMax && number >= kRangeMin) {
            int number1 = number % 1000;
            while (number1 != 0) {
                int a = number1 % 10;
                sum1 = sum1 + a;
                number1 = (number1 - a) / 10;
            }
            number = (number - (number % 1000)) / 1000;
            while (number != 0) {
                int a = number % 10;
                sum2 = sum2 + a;
                number = (number - a) / 10;
            }
            int difference(sum1 - sum2);

            if (difference == 0) {
                std::cout << "Congratulations!!!! Happy Ticket!!!!" << std::endl;
            }
            else
                std::cout << "You're a loser. You'll never be lucky" << std::endl;
        }
        else {
            std::cout << "The number is entered incorrectly" << std::endl;
        }
    }

    else if (setNumber == 3) {
        int number(0);
        long long number2(0);
        std::cout << "Enter the number:" << std::endl;
        std::cin >> number;
        std::cout << number << std::endl;
        while (number != 0) {
            int a(0);
            a = number % 10;
            number = (number - a) / 10;
            number2 = (number2 * 10) + a;
        }

        if (number > 0) {
            std::cout << number2 << std::endl;
        }
        else {
            std::cout << number2 << std::endl;
        }
    }
    else if (setNumber == 4) {
        constexpr int kMin{ 1 };
        constexpr int kMax{ 50 };
        constexpr int kMin2{ -60 };
        constexpr int kMax2{ 90 };
        int sum(0);
        int number(0);
        int quantity(0);
        std::cout
            << "Enter a number from 1 to 50. So many numbers you will need to "
            "enter later"
            << std::endl;
        std::cin >> quantity;
        while (quantity > kMax || quantity < kMin) {
            std::cout << "Try again" << std::endl;
            std::cin >> quantity;
        };
        int i(0);
        if (quantity < kMax && quantity > kMin) {
            std::cout << " Enter " << quantity << " number from -60 to 90"
                << std::endl;
            for (int i = 0; i < quantity; i++) {
                std::cin >> number;
                if (number > kMin2 && number < kMax2) {
                    if (number % 2 != 0) {

                        sum = sum + number;
                    }
                }
            }
            std::cout << "The sum of the odd numbers entered is " << sum
                << " Numbers not in the range were not taken into account"
                << std::endl;
        }
    }

    else if (setNumber == 5) {
        std::cout << "Enter a positive number" << std::endl;
        int number(0);
        std::cin >> number;

        int best(0);

        for (int divisor(1); divisor <= number; divisor++) {

            if ((number % divisor) == 0) {
                int sum(0);
                int b = divisor;
                while (b != 0) {
                    int digit = b % 10;
                    sum = sum + digit;
                    b = b / 10;
                }

                if (sum > best) {
                    best = divisor;
                }
            }
        }
        std::cout << best << std::endl;
    }

    return 0;
}
