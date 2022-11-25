#include <string>
#include <iostream>

#include "logger.h"

void Logger::LogLibraryError(std::string tag, std::string error)
{
    std::cout << "An error has occurred [" << tag << "] " << error << "\n";
}