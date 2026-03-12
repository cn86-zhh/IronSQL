#include <algorithm>

#include "iron_fmtout.hpp"
#include "iron_proces.hpp"
#include "iron_stdio.hpp"
#include "iron_keywds.hpp"
#include "iron_handle.hpp"
#include "iron_logsystem.hpp"

/* ***********************************************************
 * zone brief:                                               *
 *           Global alias settings                           *
 ************************************************************/

using ios = IronStdOst::OutStream;
using log = IronLogSystem::LogOut;

namespace _IronInnerFormatOut_
{
    class _Fmt
    {
    private:
        _Fmt() = delete;
        ~_Fmt() = delete;

    public:
        static void _printLine(const int &max_width, const std::string &str);
        static void _printLine(const int &max_width);
        static void _printLine(const int &max_width, const std::vector<std::string> &strs);
        static void _printLine(const int &max_width, const int &number_of_elements);
        static void _printLineNew(const int &max_width, const std::vector<std::string> &strs);
        static void _printLineNew(const int &max_width, const std::string &str);
        static void _printLineNew(const std::vector<int> &row_widths);

    public:
        static auto _computeRowWidths(const std::vector<int> &current_row_widths, const std::vector<std::string> &strings)
            -> std::vector<int>;
    }; // class _Fmt

    /**
     * @brief Prints a formatted line with a single string.
     *
     * This function prints a line with the given string formatted to the specified width.
     *
     * @param max_width The maximum width for the string.
     * @param str The string to print.
     */
    void _Fmt::_printLine(const int &max_width, const std::string &str)
    {
        std::cout << std::left;
        std::cout << '|';
        std::cout << std::setw(max_width) << str;
        std::cout << '|' << std::endl;
    }

    /**
     * @brief Prints a horizontal line.
     *
     * This function prints a horizontal line of the specified width.
     *
     * @param max_width The width of the line.
     */
    void _Fmt::_printLine(const int &max_width)
    {
        std::cout << '+';
        std::cout << std::string(max_width, '-');
        std::cout << '+' << std::endl;
    }

    /**
     * @brief Prints multiple formatted lines, one for each string in the vector.
     *
     * This function prints a separate line for each string in the vector, each formatted to the specified width.
     *
     * @param max_width The maximum width for each string.
     * @param strs A vector of strings to print.
     */
    void _Fmt::_printLine(const int &max_width, const std::vector<std::string> &strs)
    {
        std::cout << std::left;
        for (const auto &str : strs)
        {
            std::cout << '|';
            std::cout << std::setw(max_width) << str;
            std::cout << '|' << std::endl;
        }
    }

    /**
     * @brief Prints a horizontal line with multiple segments.
     *
     * This function prints a horizontal line divided into multiple segments of the specified width.
     *
     * @param max_width The width of each segment.
     * @param number_of_elements The number of segments.
     */
    void _Fmt::_printLine(const int &max_width, const int &number_of_elements)
    {
        std::cout << '+';
        for (int i{0}; i < number_of_elements; ++i)
        {
            std::cout << std::string(max_width, '-');
            std::cout << '+';
        }
        std::cout << std::endl;
    }

    /**
     * @brief Prints a single line with multiple strings.
     *
     * This function prints multiple strings on a single line, each formatted to the specified width.
     *
     * @param max_width The maximum width for each string.
     * @param strs A vector of strings to print.
     */
    void _Fmt::_printLineNew(const int &max_width, const std::vector<std::string> &strs)
    {
        std::cout << std::left;
        std::cout << '|';
        for (const auto &str : strs)
        {
            std::cout << std::setw(max_width) << str;
            std::cout << '|';
        }
        std::cout << std::endl;
    }

    /**
     * @brief Prints the beginning of a line with a single string.
     *
     * This function prints the start of a line with the given string, but does not complete the line.
     *
     * @param max_width The maximum width for the string.
     * @param str The string to print.
     */
    void _Fmt::_printLineNew(const int &max_width, const std::string &str)
    {
        std::cout << std::left;
        std::cout << '|';
        std::cout << std::setw(max_width) << str;
    }

    /**
     * @brief Prints a horizontal line with segments of varying widths.
     *
     * This function prints a horizontal line with segments of different widths based on the input vector.
     *
     * @param row_widths A vector of segment widths.
     */
    void _Fmt::_printLineNew(const std::vector<int> &row_widths)
    {
        std::cout << '+';
        for (int i{0}; i < row_widths.size(); ++i)
        {
            std::cout << std::string(row_widths[i], '-');
            std::cout << '+';
        }
        std::cout << std::endl;
    }

    /**
     * @brief Computes row widths based on current widths and new strings.
     *
     * This function updates the row widths to accommodate the new strings, ensuring each column is wide enough.
     *
     * @param current_row_widths The current row widths.
     * @param strings The new strings to consider.
     * @return The updated row widths.
     */
    auto _Fmt::_computeRowWidths(const std::vector<int> &current_row_widths, const std::vector<std::string> &strings)
        -> std::vector<int>
    {
        std::vector<int> last_row_widths{current_row_widths};

        if (last_row_widths.size() < strings.size())
        {
            last_row_widths.resize(strings.size(), 0);
        }

        for (int i{0}; i < strings.size(); ++i)
        {
            last_row_widths[i] = std::max(last_row_widths[i], IronHandle::Strings::getDisplayWidth(strings[i]));
        }
        return last_row_widths;
    }
} // namespace _IronInnerFormatOut_

namespace IronFormatOut
{
    /**
     * @brief Prints a list of all databases.
     *
     * This function retrieves all database names and prints them in a formatted table.
     */
    void Printer::printDatabases()
    {
        auto databases = IronProces::Gets::getDatabaseNames();
        auto database_name_max_width = IronProces::Gets::getDatabaseNameMaxWidth();

        if (databases.empty())
        {
            ios::err64(IronKeywds::Level::error() + "empty databases.");
            log::IRON_DEBUG("empty databases.");
            return;
        }

        _IronInnerFormatOut_::_Fmt::_printLine(database_name_max_width);
        _IronInnerFormatOut_::_Fmt::_printLine(database_name_max_width, databases);
        _IronInnerFormatOut_::_Fmt::_printLine(database_name_max_width);
    }

    /**
     * @brief Prints a list of tables in the specified database.
     *
     * This function retrieves all table names in the specified database and prints them in a formatted table.
     *
     * @param database_name The name of the database.
     */
    void Printer::printTables(const std::string &database_name)
    {
        auto table_names = IronProces::Gets::getTableNames(database_name);
        auto table_name_max_width = IronProces::Gets::getTableNameMaxWidth(database_name);

        if (table_names.empty())
        {
            ios::err64(IronKeywds::Level::error() + "empty tables.");
            log::IRON_DEBUG("empty tables.");
            return;
        }

        _IronInnerFormatOut_::_Fmt::_printLine(table_name_max_width);
        _IronInnerFormatOut_::_Fmt::_printLine(table_name_max_width, table_names);
        _IronInnerFormatOut_::_Fmt::_printLine(table_name_max_width);
    }

    /**
     * @brief Prints the structure of the specified table.
     *
     * This function retrieves the field names and types of the specified table and prints them in a formatted table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     */
    void Printer::printTableStruct(const std::string &database_name, const std::string &table_name)
    {
        auto field_names = IronProces::Gets::getFieldNames(database_name, table_name);
        auto field_types = IronProces::Gets::getFieldTypes(database_name, table_name);

        if (field_names.empty() || field_types.empty())
        {
            ios::err64(IronKeywds::Level::error() + "empty table struct.");
            log::IRON_DEBUG("empty table struct.");
            return;
        }

        auto field_name_max_width = IronProces::Gets::getFieldNameMaxWidth(database_name, table_name);
        auto field_type_max_width = IronProces::Gets::getFieldTypeMaxWidth(database_name, table_name);

        auto last_max_width{field_name_max_width > field_type_max_width ? field_name_max_width : field_type_max_width};
        auto number_of_elements{field_names.size()};

        _IronInnerFormatOut_::_Fmt::_printLine(last_max_width, number_of_elements);
        _IronInnerFormatOut_::_Fmt::_printLineNew(last_max_width, field_names);
        _IronInnerFormatOut_::_Fmt::_printLine(last_max_width, number_of_elements);
        _IronInnerFormatOut_::_Fmt::_printLineNew(last_max_width, field_types);
        _IronInnerFormatOut_::_Fmt::_printLine(last_max_width, number_of_elements);
    }

    /**
     * @brief Prints the data rows of the specified table.
     *
     * This function retrieves the data rows of the specified table and prints them in a formatted table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     */
    void Printer::printTableDatas(const std::string &database_name, const std::string &table_name)
    {
        auto table_names = IronProces::Gets::getTableNames(database_name);

        if (std::find(table_names.begin(), table_names.end(), table_name) == table_names.end())
        {
            ios::err64(IronKeywds::Level::error() + "undefined table:'" + table_name + "'");
            log::IRON_DEBUG("undefined table:'" + table_name + "'");
            return;
        }

        auto table_datas = IronProces::Gets::getTableDatas(database_name, table_name);
        if (table_datas.empty())
        {
            ios::err64(IronKeywds::Level::error() + "empty table datas.");
            log::IRON_DEBUG("empty table datas.");
            return;
        }
        auto field_names = IronProces::Gets::getFieldNames(database_name, table_name);
        auto row_widths = IronProces::Gets::getDataRowWidth(database_name, table_name);

        auto last_row_widths = _IronInnerFormatOut_::_Fmt::_computeRowWidths(row_widths, field_names);

        _IronInnerFormatOut_::_Fmt::_printLineNew(last_row_widths);

        // print field names
        std::cout << '|';
        for (int i{0}; i < field_names.size(); i++)
        {
            std::cout << std::left << std::setw(last_row_widths[i]) << field_names[i] << '|';
        }
        std::cout << std::endl;
        _IronInnerFormatOut_::_Fmt::_printLineNew(last_row_widths);

        // print data rows
        for (int i{0}; i < table_datas.size(); i++)
        {
            std::cout << '|';
            for (int j{0}; j < table_datas[i].size(); j++)
            {
                std::cout << std::left << std::setw(last_row_widths[j]) << table_datas[i][j] << '|';
            }
            std::cout << std::endl;
            _IronInnerFormatOut_::_Fmt::_printLineNew(last_row_widths);
        }
    }

    /**
     * @brief Prints the results of a target query.
     *
     * This function retrieves the results of a query for specific fields and prints them in a formatted table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @param field_names A vector of field names to query.
     */
    void Printer::printTargetQuery(const std::string &database_name, const std::string &table_name,
                                   const std::vector<std::string> &field_names)
    {
        bool ref_bool{true};
        auto target_query_array = IronProces::Gets::getTargetQueryArray(database_name, table_name, field_names, ref_bool);
        if (!ref_bool)
        {
            ios::err64(IronKeywds::Level::error() + "undefined field.");
            log::IRON_DEBUG("undefined field.");
            return;
        }

        if (target_query_array.empty())
        {
            std::cout << IronKeywds::Level::info() << "(0 rows)" << std::endl;
            return;
        }

        std::vector<int> column_widths(field_names.size(), 0);
        for (int i = 0; i < field_names.size(); ++i)
        {
            column_widths[i] = static_cast<int>(field_names[i].size());
        }

        for (const auto &row : target_query_array)
        {
            for (int i = 0; i < row.size() && i < field_names.size(); ++i)
            {
                column_widths[i] = std::max(column_widths[i], static_cast<int>(row[i].size()));
            }
        }

        _IronInnerFormatOut_::_Fmt::_printLineNew(column_widths);

        std::cout << '|';
        for (int i = 0; i < field_names.size(); ++i)
        {
            std::cout << std::left << std::setw(column_widths[i]) << field_names[i] << '|';
        }
        std::cout << std::endl;

        _IronInnerFormatOut_::_Fmt::_printLineNew(column_widths);

        for (const auto &row : target_query_array)
        {
            std::cout << '|';
            for (int i = 0; i < row.size(); ++i)
            {
                std::cout << std::left << std::setw(column_widths[i]) << row[i] << '|';
            }
            std::cout << std::endl;
            _IronInnerFormatOut_::_Fmt::_printLineNew(column_widths);
        }

        std::cout << "(" << target_query_array.size() << " row" << (target_query_array.size() > 1 ? "s" : "") << ")" << std::endl;
    }
} // namespace IronFormatOut