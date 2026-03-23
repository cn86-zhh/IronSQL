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
        static auto windowsSettingsConfigPath() -> std::filesystem::path;
        static auto linuxSettingsConfigPath() -> std::filesystem::path;
    }; // class Control
}
#endif // IRON_PATH_MANAGE_HPP
