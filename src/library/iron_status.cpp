#include "iron_status.hpp"
#include "iron_keywds.hpp"

namespace IronStatus
{
    std::string Manage::database_name{IronKeywds::Kw::none_()};
    int Manage::tables_number{IronKeywds::Kw::zero_()};

    /**
     * @brief Sets the database name.
     *
     * This function updates the global database name used by the system.
     *
     * @param name The new database name to set.
     */
    void Manage::settingDatabaseName(const std::string &name)
    {
        database_name = name;
    }

    /**
     * @brief Sets the number of tables in the database.
     *
     * This function updates the count of tables in the current database.
     *
     * @param numb The number of tables to set.
     */
    void Manage::settingTablesNumber(const int &numb)
    {
        tables_number = numb;
    }

    /**
     * @brief Gets the current database name.
     *
     * This function returns the name of the currently active database.
     *
     * @return The name of the current database.
     */
    std::string Manage::getDatabaseName()
    {
        return database_name;
    }

    /**
     * @brief Gets the number of tables in the current database.
     *
     * This function returns the count of tables in the currently active database as a string.
     *
     * @return The number of tables as a string.
     */
    std::string Manage::getTablesNumber()
    {
        return std::to_string(tables_number);
    }
} // namespace IronStatus