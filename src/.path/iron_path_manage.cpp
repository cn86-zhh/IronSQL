#include "iron_path_manage.hpp"
#include "iron_path_windows.hpp"
#include "iron_path_linux.hpp"

namespace IronPathManage
{
    namespace _wp = IronPathWindows;
    namespace _lp = IronPathLinux;

    /**
     * @brief Get windows settings config path.
     * @brief PATH: "C:\\Users\\IronSQL\\.Config"
     * @return Windows settings config path.
     */
    const auto Control::windowsSettingsConfigPath() -> std::filesystem::path
    {
        return _wp::PathPool::get_iron_settings_config();
    }

    /**
     * @brief Get linux settings config path.
     * @brief PATH: "/etc/ironsql/.config"
     * @return Linux settings config path.
     */
    const auto Control::linuxSettingsConfigPath() -> std::filesystem::path
    {
        return _lp::PathPool::get_iron_settings_config();
    }
}