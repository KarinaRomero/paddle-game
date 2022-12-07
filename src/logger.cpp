#include <string>
#include <iostream>

#include "logger.h"


void Logger::LogLibrary(std::string tag, std::string message)
{
    //std::cout << "Log info [" << tag << "] " << message << "\n";
}

void Logger::LogLibraryWarning(std::string tag, std::string message)
{
    //std::cout << "Warning [" << message << "] !" << "\n";
}

void Logger::LogLibraryError(std::string tag, std::string error)
{
    //std::cout << "An error has occurred [" << tag << "] " << error << "\n";
}
