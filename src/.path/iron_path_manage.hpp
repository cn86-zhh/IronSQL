#pragma once

#ifndef IRON_PATH_MANAGE_HPP
#define IRON_PATH_MANAGE_HPP

#include <filesystem>
#include <string>

namespace IronPathManage
{
    class Control
    {
    public:
        static const auto windowsSettingsConfigPath() -> std::filesystem::path;
        static const auto linuxSettingsConfigPath() -> std::filesystem::path;
    }; // class Control
}
#endif // IRON_PATH_MANAGE_HPP
