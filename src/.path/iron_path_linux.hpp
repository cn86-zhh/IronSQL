#pragma once

#ifndef IRON_PATH_LINUX_HPP
#define IRON_PATH_LINUX_HPP

#include <filesystem>
#include <string>

namespace IronPathLinux
{

    class PathPool
    {
    private:
        PathPool() = delete;
        ~PathPool() = delete;

    public:
        static const std::filesystem::path get_iron_settings_config();
    }; // class PathPool
}

#endif // IRON_PATH_LINUX_HPP