#pragma once

#ifndef IRON_LOAD_SETTINGS_CONF_HPP
#define IRON_LOAD_SETTINGS_CONF_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <unordered_map>

namespace IronLoadSettingsConf
{
    class Loader
    {
    public:
        static auto loadSettingsConfFile(const std::filesystem::path &settingsConfFilePath, const std::string &keyword) -> bool;
    }; // class Loader
}

#endif // IRON_LOAD_SETTINGS_CONF_HPP
