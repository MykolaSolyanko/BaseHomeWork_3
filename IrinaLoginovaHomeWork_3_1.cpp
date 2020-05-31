#include <cstdint>
#include <cstring>
#include <iostream>

int main() {
    constexpr int SizeString{ 150 };
    char ArrayString[SizeString]{};
    std::cout << "Please enter your string no more than " << SizeString
        << " characters." << std::endl;
    std::cout << "--->";
    std::cin.getline(ArrayString, SizeString);
    int LengthArrayString = strlen(ArrayString);
    int WholeHalf = LengthArrayString / 2;
    int j = LengthArrayString - 1;
    for (int i = 0; i <= WholeHalf; i++) {
        char StartArray = ArrayString[i];
        char EndArray = ArrayString[j];
        ArrayString[i] = EndArray;
        ArrayString[j] = StartArray;
        j--;
    }
    std::cout << "Your string in reverse order" << std::endl;
    std::cout << "---> " << ArrayString << std::endl;
    return 0;
}
