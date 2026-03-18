#include "iron_logsystem.hpp"
#include "iron_load_settings_conf.hpp"

namespace IronLogSystem
{
    namespace load = IronLoadSettingsConf;

    static const std::string ENABLE_BASE_DEBUG{"ENABLE_BASE_DEBUG"};
    static const std::string ENABLE_DEBUG_HIGHLIGHT{"ENABLE_DEBUG_HIGHLIGHT"};

#if defined(_WIN32) || defined(_WIN64) // windows
    static bool enableDebug{load::Loader::loadSettingsConfFile("C:\\Users\\IronSQL\\.Config\\ironsql_settings.conf", ENABLE_BASE_DEBUG)};
    static bool enableDebugHighlight{load::Loader::loadSettingsConfFile("C:\\Users\\IronSQL\\.Config\\ironsql_settings.conf", ENABLE_DEBUG_HIGHLIGHT)};
#else // linux
    static bool enableDebug{load::Loader::loadSettingsConfFile("/etc/ironsql/.config/ironsql_settings.conf", ENABLE_BASE_DEBUG)};
    static bool enableDebugHighlight{load::Loader::loadSettingsConfFile("/etc/ironsql/.config/ironsql_settings.conf", ENABLE_DEBUG_HIGHLIGHT)};
#endif

    /**
     * @brief Set debug mode.
     *
     * @param enable True to enable debug mode, false to disable.
     */
    void LogOut::setDebug(const bool &enable)
    {
        enableDebug = enable;
    }

    /**
     * @brief Set debug highlight mode.
     *
     * @param enable True to enable debug highlight mode, false to disable.
     */
    void LogOut::setDebugHighlight(const bool &enable_highlight)
    {
        enableDebugHighlight = enable_highlight;
    }

    /**
     * @brief Output debug information.
     *
     * @param message Debug information.
     * @param file File name.
     * @param line Line number.
     */
    void LogOut::debug(const std::string &message, const std::string &file, const int &line)
    {
        const static std::string _C_{"\033[1;36m"};
        const static std::string _R_{"\033[1;31m"};
        const static std::string _M_{"\033[1;35m"};
        const static std::string _E_{"\033[0m"};

        if (enableDebugHighlight && enableDebug)
        {
            std::cout << "[";
            std::cout << _C_ << "de" << _E_;
            std::cout << _R_ << "b" << _E_;
            std::cout << _C_ << "ug" << _E_;
            std::cout << "]: " << "file: " << file << " line: " << line << _E_ << std::endl;
            std::cout << _C_ << "       : " << "msge: " << _M_ << message << _E_ << std::endl;
            std::cout << std::endl;
        }

        if (!enableDebugHighlight && enableDebug)
        {
            std::cout << "[debug]: " << "file: " << file << " line: " << line << std::endl;
            std::cout << "       : " << "msge: " << message << std::endl;
            std::cout << std::endl;
        }
    }
} // namespace IronLogSystem