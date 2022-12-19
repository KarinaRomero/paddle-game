#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <iostream>

namespace Logger
{
    /**
     * Print an error in the console.
     *
     * @param tag Class Name.
     * @param error error description.
     */
    void LogLibraryError(std::string tag, std::string error);

    /**
     * Print an warning in the console.
     *
     * @param tag Class Name.
     * @param message message description.
     */
    void LogLibraryWarning(std::string tag, std::string message);

    /**
     * Print an custom message in the console.
     *
     * @param tag Class Name.
     * @param message message description.
     */
    void LogLibrary(std::string tag, std::string message);
}
#endif
