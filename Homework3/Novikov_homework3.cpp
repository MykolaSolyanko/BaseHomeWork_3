#include <iostream>
#include <random>


void outputArray(int* array, int n)
{
	for (size_t i = 0; i < n; i++) {
		std::cout << array[i] << " ";
	}
}

void TaskOneReverse()
{
	//clear cin buffer after last input
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	constexpr int kMaxStringSize{ 255 };
	char string[kMaxStringSize]{};
	std::cout << "Enter string less than "<<kMaxStringSize<<" symbol\n";

	while (true){
		if (!std::cin.getline(string, kMaxStringSize)) {
			std::cout << "Error in string range, try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (!strlen(string))
			std::cout << "Empty string try again\n";
		else
			break;			
	}

	
	const int cycleDuration = strlen(string)/2;
	int endOfString = strlen(string) -1 ;

	for (size_t i = 0; i < cycleDuration; i++, endOfString--)
	{
	 char buf = *(string + i);
	 *(string + i) = *(string + endOfString);
	 *(string + endOfString) = buf;
	}
	std::cout << "Result string: " << string;

}


void TaskTwoInsertion()
{
	constexpr int arrayMaxSize{ 5 };
	int MyArray[arrayMaxSize]{};
	std::cout << "Enter array elements\n";
	for (size_t i = 0; i < arrayMaxSize; i++){
		std::cin >> MyArray[i];
		if(i!=0)
			for (int j = i; j > 0; j--) {
				if (MyArray[j] < MyArray[j - 1]) {
					int buf = MyArray[j];
					MyArray[j] = MyArray[j - 1];
					MyArray[j - 1] = buf;
				}
				else
					break;
			}
	}
	std::cout << "Array: [ ";
	outputArray(MyArray, arrayMaxSize);
	std::cout << "]\n";
}

void deleteElement(int* array, int number, int& arraySize)
{
	for (size_t i = number; i < arraySize-1; i++)
		array[i] = array[i + 1];
	arraySize--;
}

void findElement(int* array, int &arraySize)
{
	int finder{};
	std::cout << "Enter element to find \n";
	std::cin >> finder;
	if (arraySize > 0) {
		for (size_t i = 0; i < arraySize; i++)
		{
			if (array[i] == finder) {
				deleteElement(array, i, arraySize);
			}
		}
	}
	else
		std::cout << "No elements left\n";
	
}

void TaskThreeDeleteElement()
{
	constexpr int maxArraySize = 10;
	int ArraySize = maxArraySize;
	int MyArray[maxArraySize];
	int maxRange{};
	int minRange{};
	std::cout << "Enter element max range\n";
	std::cin >> maxRange;
	std::cout << "Enter element min range\n";
	std::cin >> minRange;

	std::mt19937 rnd;
	std::uniform_int_distribution<> rand_distribution(maxRange, minRange);
	for (size_t i = 0; i < maxArraySize; i++) {
		MyArray[i] = rand_distribution(rnd);
	}

	std::cout << "Generated array: [ ";
	outputArray(MyArray, ArraySize);
	std::cout << "]\n";

	enum oportunity {
		exit = 0,
		deleteElement
	};
	int choise{};
	bool menu{ true };
	while (menu) {
		std::cout << "Choose what to do: \n";
		std::cout << "1. Delete element \n";
		std::cout << "0. Exit \n";
		std::cin >> choise;
		switch (choise) {
		case exit:
			menu = false;
			break;
		case deleteElement:
			findElement(MyArray, ArraySize);
			break;
		}
	}
	std::cout << "Result array: [ ";
	outputArray(MyArray, ArraySize);
	std::cout << "]\n";
	
}

void TaskFourToUpper()
{
	//clear cin buffer after last input
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	constexpr int kMaxStringSize{ 255 };
	char string[kMaxStringSize]{};
	std::cout << "Enter string less than " << kMaxStringSize << " symbol\n";

	while (true) {
		if (!std::cin.getline(string, kMaxStringSize)) {
			std::cout << "Error in string range, try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (!strlen(string))
			std::cout << "Empty string try again\n";
		else
			break;
	}

	int i{0};
	while (*(string + i))
	{
		if (*(string + i) >= 'a' && *(string + i) <= 'z')
		{
			*(string + i) -= 32;
		}
		i++;
	}
	std::cout << "Result string: " << string << std::endl;
}

void TaskFiveisDigit()
{
	//clear cin buffer after last input
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	constexpr int kMaxStringSize{ 255 };
	char string[kMaxStringSize]{};
	std::cout << "Enter string less than " << kMaxStringSize << " symbol\n";

	while (true) {
		if (!std::cin.getline(string, kMaxStringSize)) {
			std::cout << "Error in string range, try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (!strlen(string))
			std::cout << "Empty string try again\n";
		else
			break;
	}
	const int cycleDuration = strlen(string);
	std::cout << "Digits in string [ ";
	for (size_t i = 0; i < cycleDuration; i++)
	{
		if (string[i] >= '0' && string[i] <= '9')
			std::cout << string[i] << " ";
	}
	std::cout << "]\n";

}

void TaskSixToLower()
{
	//clear cin buffer after last input
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	constexpr int kMaxStringSize{ 255 };
	char string[kMaxStringSize]{};
	std::cout << "Enter string less than " << kMaxStringSize << " symbol\n";

	while (true) {
		if (!std::cin.getline(string, kMaxStringSize)) {
			std::cout << "Error in string range, try again\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (!strlen(string))
			std::cout << "Empty string try again\n";
		else
			break;
	}

	int i{ 0 };
	while (*(string + i))
	{
		if (*(string + i) >= 'A' && *(string + i) <= 'Z')
		{
			*(string + i) += 32;
		}
		i++;
	}
	std::cout << "Result string: " << string << std::endl;
}


int main()
{
	enum Tasks {
		ExitProgram = 0,
		TaskOne,
		TaskTwo,
		TaskThree,
		TaskFour,
		TaskFive,
		TaskSix
	};
	while (true)
	{
		int loop_state{};
		std::cout << "Choose your task:\n";
		std::cout << "1. Homework task one reverse string\n";
		std::cout << "2. Homework task two insertion sort\n";
		std::cout << "3. Homework task three delete element from array\n";
		std::cout << "4. Homework task four to upper\n";
		std::cout << "5. Homework task five is digit\n";
		std::cout << "6. Homework task six to lower\n";
		std::cout << "0. Exit\n";
		std::cin >> loop_state;
		switch (loop_state)
		{
		case Tasks::ExitProgram:
			return 0;
		case Tasks::TaskOne:
			TaskOneReverse();
			break;
		case Tasks::TaskTwo:
			TaskTwoInsertion();
			break;
		case Tasks::TaskThree:
			TaskThreeDeleteElement();
			break;
		case Tasks::TaskFour:
			TaskFourToUpper();
			break;
		case Tasks::TaskFive:
			TaskFiveisDigit();
			break;
		case Tasks::TaskSix:
			TaskSixToLower();
			break;
		default:
			std::cout << "There's no such option\n";
			break;
		}
		std::cout << std::endl;
	}

}