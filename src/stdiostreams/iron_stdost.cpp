#include "iron_stdost.hpp"

namespace IronStdOst
{
    /**
     * @brief print a message to the standard output stream, '64' is flag
     *
     * @param message the message to be printed
     */
    void OutStream::prt64(const std::string &message)
    {
        std::cout << message << std::endl;
    }

    /**
     * @brief print a error message to the standard error stream, '64' is flag
     *
     * @param message the error message to be printed
     */
    void OutStream::err64(const std::string &message)
    {
        std::cerr << message << std::endl;
    }
} // namespace IronStdOst