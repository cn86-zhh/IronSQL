#pragma once

#ifndef IRON_STATUS_HPP
#define IRON_STATUS_HPP

#include <string>

namespace IronStatus
{
    class Manage
    {
    private:
        Manage() = delete;
        ~Manage() = delete;
        static std::string database_name;
        static int tables_number;

    public:
        static void settingDatabaseName(const std::string &name);
        static void settingTablesNumber(const int &numb);

        static std::string getDatabaseName();
        static std::string getTablesNumber();
    }; // class Manage

} // namespace IronStatus

#endif // IRON_STATUS_HPP