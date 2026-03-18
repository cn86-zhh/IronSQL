#pragma once

#ifndef IRON_FILE_SYSTEM_HPP
#define IRON_FILE_SYSTEM_HPP

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace IronFileSystem
{
    class Fsys
    {
    private:
        Fsys() = delete;
        ~Fsys() = delete;

    public:
        static auto inspectDirectoryExist(const std::filesystem::path &path) -> bool;
        static auto createDirectory(const std::filesystem::path &path) -> bool;
        static auto inspectFileExist(const std::filesystem::path &path) -> bool;
        static auto createFile(const std::filesystem::path &path) -> bool;
    }; // class Fsys
} // namespace IronFileSystem

#endif // IRON_FILE_SYSTEM_HPP
