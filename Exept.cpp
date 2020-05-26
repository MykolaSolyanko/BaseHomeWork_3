#include <iostream>
#include <chrono>
#include <random>
#include <functional>

bool PredLess(int first, int second)
{
	return first < second;
}

bool PredGreater(int first, int second) {
	return first > second;
}

using Pred = std::function<bool(int, int)>;

void swap(int& elOne, int& elTwo)
{
	int buf{ elOne };
	elOne = elTwo;
	elTwo = buf;
}

void output_array_range(int* begin, int* end)
{
	for (auto it = begin; it!=end; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void fill_array(int* begin, int* end)
{
	int kMinRandomRange = 0;
	int kMaxRandomRange = 65535;
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 rnd(seed);
	std::uniform_int_distribution<> rand_distribution(kMinRandomRange, kMaxRandomRange);

	for (int* it{ begin }; it != end; ++it) {
		*it = rand_distribution(rnd);
	}
}

void buble_sort(int* begin, int* end, Pred pred)
{
	int i = 0;
	for (auto outer_it = begin + 1;  outer_it != end; ++outer_it, ++i) {
		for (auto inner_it = begin; inner_it != end-i; ++inner_it) {
			if (pred(*inner_it, *inner_it+1)) {
				auto temp = *inner_it;
					*inner_it = *(inner_it + 1);
				*(inner_it + 1) = temp;

			}
		}
	}
}

void qSort(int* begin, int first, int last, Pred pred)
{

	int checkingElement{ *(begin + (first+last)/2) };
	int i{ first };
	int j{ last-1 };
	do
	{
		while (pred(*(begin+i), checkingElement)) ++i;
		while (!pred(*(begin+j), checkingElement)) --j;

		if (i<=j){
			swap(*(begin + i), *(begin + j));
			++i;
			--j;
		}
		

	} while (i < j);
	if ( first<j) qSort(begin, first, j, pred);
	if (i<last) qSort(begin, i, last, pred);
}



constexpr int kArraySize{ 1000 };
int ArrayToSort[kArraySize]{};

void TaskOneSortComparsion()
{
	int* ArrayBegin = std::begin(ArrayToSort);
	int* ArrayEnd = std::end(ArrayToSort);
	int ArraySize = std::size(ArrayToSort);


	std::cout << "Filling array with random numbers\n";
	auto start = std::chrono::high_resolution_clock::now();
	fill_array(ArrayBegin, ArrayEnd);
	auto stop = std::chrono::high_resolution_clock::now();
	std::cout << "Array filled in " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " seconds\n";


	constexpr int kOutput = 100;
	std::cout << "First " << kOutput << " elements of array\n";

	output_array_range(ArrayBegin, ArrayBegin + kOutput);

	std::cout << "\n\n";

	fill_array(ArrayBegin, ArrayEnd);
	output_array_range(ArrayBegin, ArrayBegin + kOutput);

	std::cout << "quick sort started: \n";
	start = std::chrono::high_resolution_clock::now();
	qSort(ArrayBegin, 0, kArraySize - 1, [](int a, int b)->bool {return a < b; });
	stop = std::chrono::high_resolution_clock::now();
	std::cout << "Array sorted in  " << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() << " seconds\n";
	output_array_range(ArrayBegin, ArrayBegin + kOutput);
	
	std::cout << "Bubble sort started: \n";
	return;
	start = std::chrono::high_resolution_clock::now();
	
	buble_sort(ArrayBegin, ArrayEnd, PredGreater);
	
	stop = std::chrono::high_resolution_clock::now();

	
	
	std::cout << "Array sorted in  " << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() << " seconds\n";
	
	output_array_range(ArrayBegin, ArrayBegin + kOutput);

	
}



int main()
{
	enum Tasks {
		ExitProgram = 0,
		TaskOneSortCompare
	};


	while (true)
	{
		int loop_state{};
		std::cout << "Choose your task:\n";
		std::cout << "1. Homework task one sort comparsion\n";
		std::cout << "0. Exit\n";
		std::cin >> loop_state;
		switch (loop_state)
		{
		case Tasks::ExitProgram:
			return 0;
		case Tasks::TaskOneSortCompare:
			TaskOneSortComparsion();
			break;
		}
	}
}