#include <iostream>

int main() {
    enum {
        CalculateTheSumAndArithmeticMeanOfDigitsInTheNumber = 1,
        LuckyTticket,
        InverseNumbers,
        SumOfOddElements,
        BestDivisor
    };
    std::cout << "What task do you want to solve ?" << std::endl;

    int setNumber{};

    while (setNumber < 1 || setNumber > 5) {
        std::cout
            << CalculateTheSumAndArithmeticMeanOfDigitsInTheNumber
            << " Calculate the sum and arithmetic mean of digits in the number"
            << std::endl;
        std::cout << LuckyTticket << " Lucky ticket " << std::endl;
        std::cout << InverseNumbers << " Inverse numbers " << std::endl;
        std::cout << SumOfOddElements << " Sum of odd elements " << std::endl;
        std::cout << BestDivisor << " Best divisor " << std::endl;
        std::cin >> setNumber;
    }
    if (setNumber == CalculateTheSumAndArithmeticMeanOfDigitsInTheNumber) {
        int number{};
        int sum{};
        int i{};
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

    else if (setNumber == LuckyTticket) {
        int number{};
        int sum1{};
        int sum2{};
        constexpr int kRangeMax{ 1000000 };
        constexpr int kRangeMin{ 100000 };

        std::cout << "Enter a six digit number: " << std::endl;
        std::cin >> number;
        if (number < kRangeMax && number >= kRangeMin) {
            int number1 = number % 1000;
            while (number1 != 0) {
                int a = number1 % 10;
                sum1 += a;
                number1 = (number1 - a) / 10;
            }
            number = (number - (number % 1000)) / 1000;
            while (number != 0) {
                int a = number % 10;
                sum2 += a;
                number = (number - a) / 10;
            }

            if (sum1 == sum2) {
                std::cout << "Congratulations!!!! Happy Ticket!!!!" << std::endl;
            }
            else
                std::cout << "You're a loser. You'll never be lucky" << std::endl;
        }
        else {
            std::cout << "The number is entered incorrectly" << std::endl;
        }
    }

    else if (setNumber == InverseNumbers) {
        int number{};
        long long number2{};
        std::cout << "Enter the number:" << std::endl;
        std::cin >> number;
        std::cout << number << std::endl;
        while (number != 0) {
            int a = number % 10;
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
    else if (setNumber == SumOfOddElements) {
        constexpr int kMin{ 1 };
        constexpr int kMax{ 50 };
        constexpr int kMinValue{ -60 };
        constexpr int kMaxValue{ 90 };
        int sum{};
        int number{};
        int quantity{};
        std::cout << "Enter a number from " << kMin << " to " << kMax
            << ". So many numbers you will need to enter later" << std::endl;
        std::cin >> quantity;
        while (quantity > kMax || quantity < kMin) {
            std::cout << "Try again" << std::endl;
            std::cin >> quantity;
        };
        int i(0);
        if (quantity < kMax && quantity > kMin) {
            std::cout << " Enter " << quantity << " number from " << kMinValue
                << " to " << kMaxValue << std::endl;
            for (int i = 0; i < quantity; i++) {
                std::cin >> number;
                if (number > kMinValue && number < kMaxValue) {
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

    else if (setNumber == BestDivisor) {
        std::cout << "Enter a positive number" << std::endl;
        int number{};
        std::cin >> number;

        int best{};

        for (int divisor(1); divisor <= number; divisor++) {

            if ((number % divisor) == 0) {
                int sum{};
                int b = divisor;
                while (b != 0) {
                    int digit = b % 10;
                    sum += digit;
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
