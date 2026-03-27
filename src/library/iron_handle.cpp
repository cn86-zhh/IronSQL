#include "iron_handle.hpp"
#include "iron_keywds.hpp"

namespace IronHandle
{
    /**
     * @brief Strips leading and trailing whitespace from a string.
     *
     * This function removes all leading and trailing whitespace characters from the input string.
     *
     * @param str The string to strip whitespace from.
     */
    void Strings::strip(std::string &str)
    {
        str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
        str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
    }

    /**
     * @brief Converts a string to lowercase.
     *
     * This function converts all characters in the input string to lowercase.
     *
     * @param str The string to convert to lowercase.
     */
    void Strings::lower(std::string &str)
    {
        for (char &c : str)
        {
            c = std::tolower(c);
        }
    }

    /**
     * @brief Splits a string by a delimiter.
     *
     * This function splits the input string into tokens based on the specified delimiter.
     *
     * @param str The string to split.
     * @param delimiter The delimiter to use for splitting.
     * @return A vector of string tokens resulting from the split.
     */
    auto Strings::split(const std::string &str, const std::string &delimiter) -> std::vector<std::string>
    {
        std::vector<std::string> tokens;
        size_t start = 0, end = 0;
        while ((end = str.find(delimiter, start)) != std::string::npos)
        {
            tokens.push_back(str.substr(start, end - start));
            start = end + delimiter.length();
        }
        tokens.push_back(str.substr(start));
        return tokens;
    }

    /**
     * @brief Extracts the table name from a string.
     * if exist databasename [database_name, table1_name, table2_name, new_table_name]
     * else [table1_name, table2_name, new_table_name]
     * This function extracts the table name from the input string. The table name is the part of the string
     * that comes after the last dot (.) character.
     *
     * @param str The string containing the table name.
     * @return A vector of string tokens resulting from the split.
     */
    auto Strings::stringName(const std::string &str) -> std::vector<std::string>
    {
        std::vector<std::string> tokens;

        std::string filtered_string{str};

        // Find the first dot (database.table format)
        auto first_dot = filtered_string.find(IronKeywds::Kw::dot_());

        std::string database_name;
        std::string table1, table2, new_table;

        if (first_dot != std::string::npos)
        {
            // Extract database name
            database_name = filtered_string.substr(0, first_dot);
            // Remove spaces
            size_t start = database_name.find_first_not_of(" ");
            if (start != std::string::npos)
            {
                database_name = database_name.substr(start);
            }
            size_t end = database_name.find_last_not_of(" ");
            if (end != std::string::npos)
            {
                database_name = database_name.substr(0, end + 1);
            }

            // Find 'to' keyword
            auto to_pos = filtered_string.find(IronKeywds::Kw::to_());
            if (to_pos == std::string::npos)
            {
                std::cerr << "error: invalid link table sentence" << std::endl;
                return tokens;
            }

            // Extract first table name (between first dot and 'to')
            table1 = filtered_string.substr(first_dot + 1, to_pos - first_dot - 1);
            // Remove spaces
            start = table1.find_first_not_of(" ");
            if (start != std::string::npos)
            {
                table1 = table1.substr(start);
            }
            end = table1.find_last_not_of(" ");
            if (end != std::string::npos)
            {
                table1 = table1.substr(0, end + 1);
            }

            // Find second dot
            auto second_dot = filtered_string.find(IronKeywds::Kw::dot_(), to_pos);
            if (second_dot == std::string::npos)
            {
                std::cerr << "error: invalid link table sentence" << std::endl;
                return tokens;
            }

            // Verify second database name
            std::string db_name_2 = filtered_string.substr(to_pos + 3, second_dot - to_pos - 3);
            // Remove spaces
            start = db_name_2.find_first_not_of(" ");
            if (start != std::string::npos)
            {
                db_name_2 = db_name_2.substr(start);
            }
            end = db_name_2.find_last_not_of(" ");
            if (end != std::string::npos)
            {
                db_name_2 = db_name_2.substr(0, end + 1);
            }

            if (database_name != db_name_2)
            {
                std::cerr << "error: database name not match" << std::endl;
                return tokens;
            }

            // Find 'new' keyword
            auto new_pos = filtered_string.find(" new ", second_dot);

            if (new_pos != std::string::npos)
            {
                // Extract second table name (between second dot and 'new')
                table2 = filtered_string.substr(second_dot + 1, new_pos - second_dot - 1);
                // Remove spaces
                start = table2.find_first_not_of(" ");
                if (start != std::string::npos)
                {
                    table2 = table2.substr(start);
                }
                end = table2.find_last_not_of(" ");
                if (end != std::string::npos)
                {
                    table2 = table2.substr(0, end + 1);
                }

                // Extract new table name
                new_table = filtered_string.substr(new_pos + 5);
                // Remove spaces
                start = new_table.find_first_not_of(" ");
                if (start != std::string::npos)
                {
                    new_table = new_table.substr(start);
                }
                end = new_table.find_last_not_of(" ");
                if (end != std::string::npos)
                {
                    new_table = new_table.substr(0, end + 1);
                }

                tokens = {database_name, table1, table2, new_table};
            }
            else
            {
                // Extract second table name (from second dot to end)
                table2 = filtered_string.substr(second_dot + 1);
                // Remove spaces
                start = table2.find_first_not_of(" ");
                if (start != std::string::npos)
                {
                    table2 = table2.substr(start);
                }
                end = table2.find_last_not_of(" ");
                if (end != std::string::npos)
                {
                    table2 = table2.substr(0, end + 1);
                }

                tokens = {database_name, table1, table2};
            }
        }
        else
        {
            // Relative statement processing
            auto to_pos = filtered_string.find(IronKeywds::Kw::to_());
            if (to_pos == std::string::npos)
            {
                std::cerr << "error: invalid link table sentence" << std::endl;
                return tokens;
            }

            auto new_pos = filtered_string.find(" new ", to_pos);

            table1 = filtered_string.substr(0, to_pos);
            std::string table2_part = filtered_string.substr(to_pos + 3);

            if (new_pos != std::string::npos)
            {
                auto relative_new_pos = new_pos - to_pos - 3;
                if (relative_new_pos >= table2_part.length())
                {
                    std::cerr << "error: invalid link table sentence" << std::endl;
                    return tokens;
                }
                table2 = table2_part.substr(0, relative_new_pos);
                new_table = table2_part.substr(relative_new_pos + 5);

                tokens = {table1, table2, new_table};
            }
            else
            {
                tokens = {table1, table2_part};
            }
        }
        return tokens;
    }

    /**
     * @brief Extracts database and table name from a string.
     * If the string contains a dot, it is assumed to be in the format "database.table".
     * Otherwise, it is assumed to be just a table name.
     *
     * @param str The string to extract from.
     * @return A vector of strings. If size() == 1, it contains just the table name.
     *         If size() == 2, it contains [database_name, table_name].
     */
    auto Strings::extractDatabaseAndTable(const std::string &str) -> std::vector<std::string>
    {
        std::vector<std::string> result;
        const static std::string dot{IronKeywds::Kw::dot_()};

        auto dot_pos = str.find(dot);

        if (dot_pos == std::string::npos)
        {
            std::string table_name{str};
            IronHandle::Strings::strip(table_name);
            result.push_back(table_name);
        }
        else
        {
            std::string database_name{str.substr(0, dot_pos)};
            IronHandle::Strings::strip(database_name);
            std::string table_name{str.substr(dot_pos + 1)};
            IronHandle::Strings::strip(table_name);
            result.push_back(database_name);
            result.push_back(table_name);
        }

        return result;
    }

    /**
     * @brief Calculate the display width of a string
     *
     * For ASCII characters, width is 1; for Chinese characters, width is also 1
     *
     * @param str The string to calculate width for
     * @return The display width of the string
     */
    auto Strings::getDisplayWidth(const std::string &str) -> int
    {
        int width = 0;
        for (size_t i = 0; i < str.size();)
        {
            if (static_cast<unsigned char>(str[i]) < 0x80)
            {
                // ASCII character
                width++;
                i++;
            }
            else if (static_cast<unsigned char>(str[i]) >= 0xE0)
            {
                // 3-byte UTF-8 character (Chinese character)
                width++;
                i += 3;
            }
            else if (static_cast<unsigned char>(str[i]) >= 0xC0)
            {
                // 2-byte UTF-8 character
                width++;
                i += 2;
            }
            else
            {
                // Other cases
                width++;
                i++;
            }
        }
        return width;
    }

    /**
     * @brief Extract table names from a string
     *
     * @param lstrs String containing table names
     * @return Vector containing all table names
     */
    auto Strings::getTableNames(const std::string &lstrs) -> std::vector<std::string>
    {
        if (lstrs.empty())
        {
            return {};
        }

        /* expected line: table1,table2,... */
        std::vector<std::string> table_names;
        const static char space{' '};

        std::string new_strs{lstrs};
        new_strs.erase(std::remove(new_strs.begin(), new_strs.end(), space), new_strs.end()); /* move all of space to end position */

        std::string table_name;
        for (auto c : new_strs)
        {
            if (c == ',')
            {
                table_names.push_back(table_name);
                table_name.clear();
            }
            else
            {
                table_name += c;
            }
        }

        if (!table_name.empty())
        {
            table_names.push_back(table_name);
            table_name.clear();
        }

        return table_names;
    }
}