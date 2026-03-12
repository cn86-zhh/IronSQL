#pragma once

#ifndef IRON_LOGSYSTEM_HPP
#define IRON_LOGSYSTEM_HPP

#include <iostream>
#include <string>

namespace IronLogSystem
{
    class LogOut
    {
    private:
        LogOut() = delete;
        ~LogOut() = delete;

    public:
        static void setDebug(const bool &enable);
        static void setDebugHighlight(const bool &enable);
        static void debug(const std::string &message, const std::string &file, const int &line);

#define IRON_DEBUG(message) LogOut::debug(message, __FILE__, __LINE__)
    }; // LogOut
} // namespace IronLogSystem

#endif // IRON_LOGSYSTEM_HPP
