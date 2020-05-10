#include <cmath>
#include <iostream>
#include <stdexcept>

int main() {
    constexpr int MinRange = 2, MaxRange = 255;
    {
        std::cout << "Please enter a value for variables A, B, C in the range from "
            << MinRange << " to " << MaxRange << std::endl;
        std::cout << "The value for A = ";
        int a;
        std::cin >> a;
        while (a == 0 || a < MinRange || a > MaxRange) {
            std::cout << "You entered an invalid number. Repeat the value A in the "
                "range"
                << MinRange << " to " << MaxRange << std::endl;
            std::cout << "Please enter a value for variable A" << std::endl;
            std::cout << "The value for A = ";
            std::cin >> a;
        }
        std::cout << "The value for B = ";
        int b;
        std::cin >> b;
        while (b == 0 || b < MinRange || b > MaxRange) {
            std::cout << "You entered an invalid number. Repeat the value B in the "
                "range"
                << MinRange << " to " << MaxRange << std::endl;
            std::cout << "Please enter a value for variable B" << std::endl;
            std::cout << "The value for B = ";
            std::cin >> b;
        }
        std::cout << "The value for C = ";
        int c;
        std::cin >> c;
        while (c == 0 || c < MinRange || c > MaxRange) {
            std::cout << "You entered an invalid number. Repeat the value C in the "
                "range"
                << MinRange << " to " << MaxRange << std::endl;
            std::cout << "Please enter a value for variable C" << std::endl;
            std::cout << "The value for C = ";
            std::cin >> c;
        }
        std::cout << "Your equation is " << a << "x^2+" << b << "x+" << c << "=0."
            << std::endl;
        constexpr int Two{ 2 }, Four{ 4 };
        long long d = (b * b) - (Four * a * c);
        if (d < 0) {
            std::cout << "Equation has no solution \n";
            return (0);
        }
        else if (d > 0) {
            b = -b;
            long double x1 = (b + sqrt(d)) / (Two * a);
            long double x2 = (b - sqrt(d)) / (Two * a);
            std::cout << "First root of the equation x1= " << x1 << std::endl;
            std::cout << "Second root of the equation x2= " << x2 << std::endl;
        }
        else {
            long double x = -(b / (Two * a));
            std::cout << "The root of the equation x= " << x << std::endl;
        }
    }
    return 0;
}
