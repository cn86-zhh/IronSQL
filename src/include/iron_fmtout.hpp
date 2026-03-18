#pragma once

#ifndef IRON_FMTOUT_HPP
#define IRON_FMTOUT_HPP

#include <iostream>
#include <vector>
#include <iomanip>

namespace IronFormatOut
{
    class Printer
    {
    private:
        Printer() = delete;
        ~Printer() = delete;

    public:
        static void printDatabases();
        static void printTables(const std::string &database_name);
        static void printTableStruct(const std::string &database_name, const std::string &table_name);
        static void printTableDatas(const std::string &database_name, const std::string &table_name);
        static void printTargetQuery(const std::string &database_name, const std::string &table_name, const std::vector<std::string> &field_names);
        static void printMultipleTableData(const std::string &database_name, const std::vector<std::string> &table_names);
    };
} // namespace IronFormatOut

#endif // IRON_FMTOUT_HPP
