#include "Logger.hpp"
#include <fstream>
#include <iostream>

void Logger::log(const std::string& message) {
    std::ofstream file("system.log", std::ios::app);
    file << message << std::endl;
    std::cout << message << std::endl;
}
