#pragma once

#ifndef IRON_PATH_INIT_HPP
#define IRON_PATH_INIT_HPP

#include <shared_mutex>
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

namespace IronPathInit
{

    class Initer
    {
    private:
        Initer() = delete;
        ~Initer() = delete;
        static std::shared_mutex pmtx;

    public:
        static auto initPath(const std::filesystem::path &tpath) -> void;
    }; // class Initer

} // namespace IronPathInit

#endif // IRON_PATH_INIT_HPP
