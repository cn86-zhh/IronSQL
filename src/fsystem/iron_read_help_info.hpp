#pragma once

#ifndef IRON_READ_HELP_INFO_HPP
#define IRON_READ_HELP_INFO_HPP

#include <filesystem>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <shared_mutex>

namespace IronReadHelpInfo
{

    class ReadStream
    {

    private:
        ReadStream() = delete;
        ~ReadStream() = delete;
        static std::shared_mutex rmutex;

    public:
        static auto readLine(const std::filesystem::path &tarpath) -> std::vector<std::string>;

    }; // class ReadStream

} // namespace IronReadHelpInfo

#endif // IRON_READ_HELP_INFO_HPP