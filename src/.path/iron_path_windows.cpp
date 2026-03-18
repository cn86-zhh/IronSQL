#include "iron_path_windows.hpp"

namespace IronPathWindows
{

    const std::filesystem::path PathPool::get_iron_settings_config()
    {
        static const std::filesystem::path iron_settings_config{"C:\\Users\\IronSQL\\.Config\\ironsql_settings.conf"};
        return iron_settings_config;
    }
}