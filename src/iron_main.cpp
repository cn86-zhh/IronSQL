#include <iostream>
#include <string>

// #ifdef _WIN32
// #include <windows.h>
// #include <io.h>
// #include <fcntl.h>
// #else
// #include <unistd.h>
// #endif

#include "iron_cross_platform.hpp"
#include "iron_handle.hpp"
#include "iron_server.hpp"
#include "iron_help.hpp"
#include "iron_test.hpp"
#include "iron_keywds.hpp"
#include "iron_logsystem.hpp"

namespace IronMain
{

    /* ***********************************************************
     * zone brief:                                               *
     *           Global alias settings                           *
     ************************************************************/

    using log = IronLogSystem::LogOut;

    class Master
    {
    private:
        Master() = delete;
        ~Master() = delete;

    public:
        static void initIronSQL();
    }; // class Master

    /**
     * @brief Initializes IronSQL and starts the main interactive loop.
     *
     * This function displays the welcome message and enters a loop to read
     * and process user commands until the user exits. It handles multi-line
     * commands and processes them when a semicolon is encountered.
     */
    void Master::initIronSQL()
    {
        // set terminal encoding to UTF-8
#ifdef _WIN32
        SetConsoleOutputCP(65001); // set console output encoding to UTF-8
        SetConsoleCP(65001);       // set console input encoding to UTF-8
#endif

        bool isInteractive = false;
#ifdef _WIN32
        isInteractive = _isatty(_fileno(stdin));
#else
        isInteractive = isatty(fileno(stdin));
#endif

        if (isInteractive)
        {
            IronHelp::ShowHelpInformation::welcome(IronKeywds::Kw::enable_());
        }

        std::string buffer; // used to accumulate multi-line statements

        while (true)
        {
            if (isInteractive && buffer.empty())
            {
                std::cout << "IronSQL> ";
            }
            else if (isInteractive)
            {
                std::cout << "       -> ";
            }

            std::string line;
            if (!std::getline(std::cin, line))
            {
                break;
            }

            log::IRON_DEBUG(line);
            std::string original_line = line;
            IronHandle::Strings::strip(line);

            if (line.empty())
            {
                continue;
            }

            if ("#" == line.substr(0, 1) || "//" == line.substr(0, 2) || "--" == line.substr(0, 2))
            {
                continue;
            }

            std::string lower_line = line;
            IronHandle::Strings::lower(lower_line);

            if ("quit" == lower_line || "exit" == lower_line || "exit;" == lower_line || "quit;" == lower_line)
            {
                std::cout << "Exit IronSQL !" << std::endl;
                break;
            }

            std::string stripped_original = original_line;
            IronHandle::Strings::strip(stripped_original);

            if (!buffer.empty())
            {
                buffer += " ";
            }
            buffer += stripped_original;

            size_t pos = 0;
            while ((pos = buffer.find(';')) != std::string::npos)
            {
                std::string sentence = buffer.substr(0, pos);
                IronHandle::Strings::strip(sentence);

                if (!sentence.empty())
                {
                    log::IRON_DEBUG(sentence);
                    IronServer::Service::runIronSQL(sentence);
                }

                buffer = buffer.substr(pos + 1);
                IronHandle::Strings::strip(buffer);
            }
        }
    }
} // namespace IronMain

int main(int argc, char *argv[])
{
    IronTest::test();
    IronMain::Master::initIronSQL();
    return 0;
}
