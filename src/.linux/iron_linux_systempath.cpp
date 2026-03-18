#include "iron_linux_systempath.hpp"

namespace IronLinuxSystemPath
{
    auto SystemPathManager::configForEtc() -> std::filesystem::path
    {
        return "/etc/iron_sql/.config";
    }
} // namespace IronLinuxSystemPath