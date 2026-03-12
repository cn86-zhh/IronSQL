#pragma once

#ifndef IRON_SYNTAX_HPP
#define IRON_SYNTAX_HPP

#include <string>

namespace IronSyntax
{
    class Word
    {
    private:
        Word() = delete;
        ~Word() = delete;
        static const std::string SHOW;
        static const std::string SPACE;
        static const std::string DATABASES;
        static const std::string DATABASE;
        static const std::string USE;
        static const std::string SELECT;
        static const std::string FROM;
        static const std::string INSERT;
        static const std::string INTO;
        static const std::string VALUES;
        static const std::string DATAS;
        static const std::string STRUCT;
        static const std::string DOT;
        static const std::string CREATE;
        static const std::string TABLES;
        static const std::string STAR;
        static const std::string TABLE;
        static const std::string HELP;

    public:
        static const std::string &show();
        static const std::string &space();
        static const std::string &databases();
        static const std::string &database();
        static const std::string &use();
        static const std::string &select();
        static const std::string &from();
        static const std::string &insert();
        static const std::string &into();
        static const std::string &values();
        static const std::string &datas();
        static const std::string &struct_();
        static const std::string &dot();
        static const std::string &create();
        static const std::string &tables();
        static const std::string &star();
        static const std::string &table();
        static const std::string &help();
    }; // class Word
}

#endif // IRON_SYNTAX_HPP
