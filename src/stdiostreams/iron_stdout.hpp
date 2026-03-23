#pragma once

#ifndef IRON_STDOUT_HPP
#define IRON_STDOUT_HPP

#include <iostream>
#include <string>

namespace IronStdOut
{

    class Stream
    {
    private:
        Stream() = delete;
        ~Stream() = delete;

    public:
        static void prt(const std::string &line);
        static void err(const std::string &line);
    }; // class Stream

} // namespace IronStdOut

#endif // IRON_STDOUT_HPP