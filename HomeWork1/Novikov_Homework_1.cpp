#include <cmath>
#include <iostream>
#include <limits>

int main() {

	//consts
	const int FOUR = 4;
	const int TWO = 2;


	int a{};
	std::cout << R"(Enter 'a' koef )";
	if (!(std::cin >> a)) {
		std::cout << "Incorrect range\n";
		return 0;
	}

	int b{};
	std::cout << R"(Enter 'b' koef )";
	if (!(std::cin >> b)) {
		std::cout << "Incorrect range\n";
		return 0;
	}

	int c{};
	std::cout << R"(Enter 'c' koef )";
	if (!(std::cin >> c)) {
		std::cout << "Incorrect range\n";
		return 0;
	}


	//roots of equation
	float x1; 
	float x2;
	float fc = static_cast<float>(-c);
	float fb = static_cast<float>(-b);
	// ax^2 = 0
	if (b == 0 && c == 0) {
		x1 = x2 = 0;
		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x2 = " << x2 << std::endl;
		return 0;
	}

	// c = 0
	if (a == 0 && b == 0) {
		std::cout << "This is not an equation" << std::endl;
		return 0;
	}

	// ax^2+c=0
	if (b == 0 && a != 0 && c != 0) {
		if ( fc / a > 0) {
			x1 = sqrt(fc / a);
			x2 = -sqrt(fc / a);
			std::cout << "x1 = " << x1 << std::endl;
			std::cout << "x2 = " << x2 << std::endl;
			return 0;
		}
		else {
			std::cout << "There's no real solutions" << std::endl;
			return 0;
		}
	
		// bx+c=0
	if (a == 0 && b != 0) {
		std::cout << "x = " << fc / b;
		return 0;
	}	

	// ax^2+bx=0
	if (c == 0 && a != 0) {
		x1 = 0;
		x2 = fb / a;
		std::cout << "x1 = " << x1 << std::endl;
		std::cout << "x2 = " << x2 << std::endl;
		return 0;
	}

	// ax^2+bx+c = 0
	if (a != 0 && b != 0 && c != 0) {
		long double D{ b * b - FOUR * a * c };
		if (D < 0) {
			std::cout << "There's no real solutions" << std::endl;
			return 0;
		}
		if (D == 0)
		{
			x1 = x2 = fb / (TWO * a);
			std::cout << "x1 = " << x1 << std::endl;
			std::cout << "x2 = " << x2 << std::endl;
			return 0;
		}
		else {
			x1 = (-b + sqrt(D)) / (TWO * a);
			x2 = (-b - sqrt(D)) / (TWO * a);
			std::cout << "x1 = " << x1 << std::endl;
			std::cout << "x2 = " << x2 << std::endl;
			return 0;
		}
	}
	
}