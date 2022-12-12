#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <iostream>

namespace Logger
{
    void LogLibraryError(std::string tag, std::string error);
    void LogLibraryWarning(std::string tag, std::string message);
    void LogLibrary(std::string tag, std::string message);
}
#endif
