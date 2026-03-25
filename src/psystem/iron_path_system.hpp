#pragma once

#ifndef IRON_PATH_SYSTEM_HPP
#define IRON_PATH_SYSTEM_HPP

#include <mutex>
#include <filesystem>

namespace IronPathSystem /* namespace IronPathSystem (prefix Iron, full name PathSystem) */
{

    class Psm /* class Psm (full name PathSystemManager) */
    {

    private:
        Psm() = delete;
        ~Psm() = delete;
        static std::mutex pmtx;

    public:
        static auto returnPath(const std::filesystem::path &pwindows, const std::filesystem::path &punix) -> std::filesystem::path;

    }; // class Psm

} // namespace IronPathSystem

#endif // IRON_PATH_SYSTEM_HPP
