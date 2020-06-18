#include "binaryTree.h"
#include <iostream>

int main() {
    LoggerSingleton::Log()->Info("Logger initialized...");
    BinaryTree tree{};
    tree.input(5);
    tree.input(-5);
    tree.input(3);
    tree.input(6);
    tree.input(7);
    tree.input(8);
    tree.print();
    std::cout << std::endl;
    tree.remove(6);
    tree.print();
}