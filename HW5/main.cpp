#include <iostream>
#include <functional>
#include "func.h"

enum Tasks{
    Exit = 0,
    binaryTree,
    taskTwo
};



int main()
{
    std::function<void()> HomeWork[] = {
        []() { TaskOne(); },
        []() { TaskTwo(); }
    };
    while(true){
        std::cout << "Choose what to do: \n";
        std::cout << "1. Task one data structures\n";
        std::cout << "2. Task two\n";
        std::cout << "0. Exit\n";
        int loop{};
        std::cin >> loop;
        if (loop > 2) {
            std::cout << "Incorrect! Try again\n";
            continue;
        }
        if (loop == 0) {
            break;
        }
        HomeWork[loop - 1]();

        
        
    }

}