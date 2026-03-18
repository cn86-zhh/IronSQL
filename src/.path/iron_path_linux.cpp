#include "iron_path_linux.hpp"

namespace IronPathLinux
{

    const std::filesystem::path PathPool::get_iron_settings_config()
    {
        static const std::filesystem::path iron_settings_config{"/etc/ironsql/.config/ironsql_settings.conf"};
        return iron_settings_config;
    }
}