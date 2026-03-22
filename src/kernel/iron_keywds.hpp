#pragma once

#ifndef IRON_KEYWDS_HPP
#define IRON_KEYWDS_HPP

#include <string>

namespace IronKeywds
{
    class Kw
    {
    private:
        Kw() = delete;
        ~Kw() = delete;

        const static std::string NONE;
        const static int ZERO;
        const static std::string MINT;
        const static std::string BINT;
        const static std::string INT;
        const static std::string CHAR;
        const static std::string STRING;
        const static std::string DOUBLE;
        const static std::string FLOAT;
        const static std::string BOOL;
        const static std::string ERRT;
        const static bool ENABLE;
        const static std::string DOT;
        const static std::string TO;

    private:
        const static std::string ZH_CN;
        const static std::string EN_US;

    public:
        const static std::string none_();
        const static int zero_();
        const static std::string maxInt_();
        const static std::string bigInt_();
        const static std::string int_();
        const static std::string char_();
        const static std::string string_();
        const static std::string double_();
        const static std::string float_();
        const static std::string bool_();
        const static std::string errt_();
        const static bool enable_();
        const static std::string dot_();
        const static std::string to_();

    public:
        const static std::string lang_zh_cn();
        const static std::string lang_en_us();
    }; // class Kw

    class Level
    {
    private:
        Level() = delete;
        ~Level() = delete;
        const static std::string INFO;
        const static std::string WARN;
        const static std::string ERR;
        const static std::string FATAL;
        const static std::string DONE;

    public:
        const static std::string error();
        const static std::string done();
        const static std::string info();
        const static std::string warn();
        const static std::string fatal();
    }; // class Level

} // namespace IronKeywds

#endif // IRON_KEYWDS_HPP
