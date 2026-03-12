#pragma once

#ifndef IRON_HANDLE_HPP
#define IRON_HANDLE_HPP

#include <iostream>
#include <string>
#include <vector>

namespace IronHandle
{
    class Strings
    {
    private:
        Strings() = delete;
        ~Strings() = delete;

    public:
        static void strip(std::string &str);
        static void lower(std::string &str);
        static auto split(const std::string &str, const std::string &delimiter) -> std::vector<std::string>;
        static auto stringName(const std::string &str) -> std::vector<std::string>;
        static auto extractDatabaseAndTable(const std::string &str) -> std::vector<std::string>;
        static auto getDisplayWidth(const std::string &str) -> int;
    };

} // namespace IronHandle

#endif // IRON_HANDLE_HPP