#pragma once

#ifndef IRON_SERVER_HPP
#define IRON_SERVER_HPP

#include <iostream>
#include <string>

namespace IronServer
{
    class Service
    {
    private:
        Service() = delete;
        ~Service() = delete;

    public:
        static void runIronSQL(const std::string &query, const bool &enableHighlight = true);
    }; // class Service
} // namespace IronServer

#endif // IRON_SERVER_HPP