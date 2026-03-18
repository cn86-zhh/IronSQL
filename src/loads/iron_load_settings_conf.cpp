#include "iron_load_settings_conf.hpp"

namespace IronLoadSettingsConf
{
    /**
     * @brief Load settings conf file.
     *
     * @param settingsConfFilePath Path to settings conf file.
     * @param keyword Keyword to search.
     * @return True if keyword is found and value is 1, false otherwise.
     */
    auto Loader::loadSettingsConfFile(const std::filesystem::path &settingsConfFilePath, const std::string &keyword) -> bool
    {
        std::ifstream settingsConfFile(settingsConfFilePath);
        if (!settingsConfFile.is_open())
        {
            std::cerr << "Error: cannot open settings conf file: " << settingsConfFilePath << std::endl;
            return false;
        }
        std::string line;
        while (std::getline(settingsConfFile, line))
        {
            if (line.find(keyword) != std::string::npos)
            {
                return line.find("1") != std::string::npos; // 1 is true, 0 is false
            }
        }
        return false; // default is false
    }
}