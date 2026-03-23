#include "iron_stdout.hpp"

namespace IronStdOut
{
    /**
     * @brief print a line to the standard output stream
     *
     * @param line the line to be printed, parameter is a reference to a string
     */
    void Stream::prt(const std::string &line)
    {
        std::cout << line << std::endl;
    }

    /**
     * @brief print a line to the standard error stream
     *
     * @param line the line to be printed, parameter is a reference to a string
     */
    void Stream::err(const std::string &line)
    {
        std::cerr << line << std::endl;
    }
} // namespace IronStdOut