#include "func.h"
#include "tree.h"
#include <cmath>
#include <functional>
#include <iostream>

void TaskOne() {
    BinaryTree* tree{};
    std::function<void()> tasks[] = { [&tree]() {
                                       int data;
                                       std::cout << "Enter value to add: \n";
                                       std::cin >> data;
                                       InputElement(tree, data);
                                     },
                                     [&tree]() { PrintTree(tree); },
                                     [&tree]() {
                                       int data;
                                       std::cout << "Enter value to delete: \n";
                                       std::cin >> data;
                                       DeleteElement(tree, data);
                                       DeleteElement(tree, data);
                                     }

    };

    while (true) {
        std::cout << "Choose your actions with BTS: \n";

        std::cout << "1. Insert element\n";
        std::cout << "2. Print tree\n";
        std::cout << "3. Delete element\n";
        std::cout << "0. Exit\n";
        unsigned int choise{};
        std::cin >> choise;
        if (choise > 3) {
            std::cout << "Incorrect! Try again\n";
            continue;
        }
        if (choise == 0) {
            break;
        }
        tasks[choise - 1]();
    }
}

static bool check_string(std::string str) {
    for (int n{ 0 }; n < str.size(); ++n) {
        if (str[n] > 57 || str[n] < 48)
            return false;
    }
    return true;
}

void TaskTwo() {
    std::string InputString{};
    int sz{};
    std::cout << "Enter string and count of substring\n";
    std::cin >> InputString;
    std::cin >> sz;
    if (!check_string(InputString) || sz > InputString.size() || sz < 0) {
        std::cout << "Incorrect input\n";
        return;
    }
    auto ResultString = revrot(InputString, sz);
    std::cout << R"(revrot(")" << InputString << "\", " << sz << R"(") -->  ")"
        << ResultString << "\"" << std::endl;
}

static bool get_cubes(std::string str) {
    int rez{};
    int buf{};
    for (int i{}; i < str.size(); ++i) {
        std::stringstream s;
        s << str[i];
        s >> buf;
        rez += pow(buf, 3);
    }
    if (rez % 2 == 0) {
        return true;
    }
    return false;
}

static void reverse(std::string& str) {
    for (int i{}, j = str.size() - 1; i < str.size() / 2; ++i, --j) {
        auto tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

static void rotate(std::string& str) {
    auto first = str[0];
    for (int i{}; i < str.size() - 1; ++i) {
        auto tmp = str[i];
        str[i] = str[i + 1];
        str[i + 1] = tmp;
    }
    str[str.size() - 1] = first;
}

static std::string revrot(std::string str, int sz) {
    std::string buf{};
    std::string rezult{};
    if (str.size() == 0 || sz == 0) {
        return "";
    }
    for (int i{ 0 }; i < str.size() + 1; ++i) {
        if (i % sz == 0 && i != 0) {
            if (get_cubes(buf)) {
                reverse(buf);
            }
            else {
                rotate(buf);
            }
            rezult += buf;
            buf.erase();
        }
        buf += str[i];
    }
    str.erase();
    return rezult;
}
