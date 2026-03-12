#pragma once

#ifndef STDOST_HPP
#define STDOST_HPP

#include <iostream>
#include <string>

namespace IronStdOst
{
    class OutStream
    {
    private:
        OutStream() = delete;
        ~OutStream() = delete;

    public:
        static void prt64(const std::string &message);
        static void err64(const std::string &message);
    }; // class OutStream

}; // namespace IronStdOst

#endif // STDOST_HPP
