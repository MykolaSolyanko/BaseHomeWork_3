#include "singletone.h"
#include <cstdarg>
#include <iostream>

void LoggerSingleton::Debug(std::string input) {
    std::cout << "[DEBUG]: " << input << std::endl;
}

void LoggerSingleton::Trace(std::string input) {
    std::cout << "[TRACE]: " << input << std::endl;
}

void LoggerSingleton::Warning(std::string input) {
    std::cout << "[WARNING]: " << input << std::endl;
}

void LoggerSingleton::Info(std::string input) {
    std::cout << "[INFO]: " << input << std::endl;
}

void LoggerSingleton::Error(std::string input) {
    std::cout << "[ERROR]: " << input << std::endl;
}
