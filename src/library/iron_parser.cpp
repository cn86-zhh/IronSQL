#include "iron_parser.hpp"
#include "iron_handle.hpp"

namespace IronParser
{
    static const std::string bracket_left{"("};
    static const std::string bracket_right{")"};

    /********************************************************************************************************
     * @brief Extracts field definitions from a SQL query.                                                  *
     *                                                                                                      *
     * This function extracts field definitions from a SQL query by finding the content between parentheses.*
     *                                                                                                      *
     * @param query The SQL query to extract field definitions from.                                        *
     * @return A vector of field definition strings.                                                        *
     ********************************************************************************************************/
    static auto extractFieldDefinitions(const std::string &query) -> std::vector<std::string>
    {
        std::vector<std::string> field_definitions;
        auto left_pos = query.find(bracket_left);
        auto right_pos = query.find(bracket_right);
        auto field_defs_str = query.substr(left_pos + 1, right_pos - left_pos - 1);
        auto field_defs = IronHandle::Strings::split(field_defs_str, ",");
        for (const auto &field_def : field_defs)
        {
            std::string trimmed_def = field_def;
            IronHandle::Strings::strip(trimmed_def);
            if (!trimmed_def.empty())
            {
                field_definitions.push_back(trimmed_def);
            }
        }
        return field_definitions;
    }

    /********************************************************************************************************
     * @brief Resolves field names from a SQL query.                                                        *
     * This function extracts field names from a SQL query by parsing the field definitions.                *
     *                                                                                                      *
     * @param query The SQL query to resolve field names from.                                              *
     * @return A vector of field names.                                                                     *
     ********************************************************************************************************/
    auto Resolver::resolveFieldNames(const std::string &query) -> std::vector<std::string>
    {
        std::vector<std::string> field_names;
        auto field_definitions = extractFieldDefinitions(query);

        for (const auto &field_def : field_definitions)
        {
            auto parts = IronHandle::Strings::split(field_def, " ");
            if (!parts.empty())
            {
                field_names.push_back(parts[0]);
            }
        }
        return field_names;
    }

    /********************************************************************************************************
     * @brief Resolves field types from a SQL query.                                                        *
     * This function extracts field types from a SQL query by parsing the field definitions.                *
     *                                                                                                      *
     * @param query The SQL query to resolve field types from.                                              *
     * @return A vector of field types.                                                                     *
     ********************************************************************************************************/
    auto Resolver::resolveFieldTypes(const std::string &query) -> std::vector<std::string>
    {
        std::vector<std::string> field_types;
        auto field_definitions = extractFieldDefinitions(query);

        for (const auto &field_def : field_definitions)
        {
            auto parts = IronHandle::Strings::split(field_def, " ");
            if (parts.size() >= 2)
            {
                field_types.push_back(parts[1]);
            }
        }
        return field_types;
    }

    /********************************************************************************************************
     * @brief Resolves the table name from an INSERT statement.                                             *
     * This function extracts the table name from an INSERT INTO statement.                                 *
     *                                                                                                      *
     * @param query The INSERT statement to resolve the table name from.                                    *
     * @return The table name, or an empty string if not found.                                             *
     ********************************************************************************************************/
    auto Resolver::resolveInsertTableName(const std::string &query) -> std::string
    {
        // INSERT INTO table_name (fields) VALUES (values);
        size_t start = 12;
        auto bracket_pos = query.find(bracket_left, start);
        if (bracket_pos == std::string::npos)
        {
            return "";
        }
        std::string table_name = query.substr(start, bracket_pos - start);
        IronHandle::Strings::strip(table_name);
        return table_name;
    }

    /*********************************************************************************************************
     * @brief Resolves field names from an INSERT statement.                                                 *
     * This function extracts field names from the parentheses in an INSERT statement.                       *
     *                                                                                                       *
     * @param query The INSERT statement to resolve field names from.                                        *
     * @return A vector of field names.                                                                      *
     *********************************************************************************************************/
    auto Resolver::resolveInsertFieldNames(const std::string &query) -> std::vector<std::string>
    {
        std::vector<std::string> field_names;
        auto left_pos = query.find(bracket_left);
        auto right_pos = query.find(bracket_right);
        if (left_pos == std::string::npos || right_pos == std::string::npos)
        {
            return field_names;
        }
        auto fields_str = query.substr(left_pos + 1, right_pos - left_pos - 1);
        auto fields = IronHandle::Strings::split(fields_str, ",");
        for (const auto &field : fields)
        {
            std::string trimmed_field = field;
            IronHandle::Strings::strip(trimmed_field);
            if (!trimmed_field.empty())
            {
                field_names.push_back(trimmed_field);
            }
        }
        return field_names;
    }

    /********************************************************************************************************
     * @brief Resolves field values from an INSERT statement.                                               *
     * This function extracts field values from the VALUES clause of an INSERT statement,                   *
     * handling commas within quoted strings.                                                               *
     *                                                                                                      *
     * @param query The INSERT statement to resolve field values from.                                      *
     * @return A vector of field values.                                                                    *
     ********************************************************************************************************/
    auto Resolver::resolveInsertFieldValues(const std::string &query) -> std::vector<std::string>
    {
        std::vector<std::string> field_values;

        auto values_pos = query.find("VALUES");
        if (values_pos == std::string::npos)
        {
            values_pos = query.find("values");
        }
        if (values_pos == std::string::npos)
        {
            return field_values;
        }

        auto left_pos = query.find(bracket_left, values_pos);
        auto right_pos = query.find(bracket_right, values_pos);
        if (left_pos == std::string::npos || right_pos == std::string::npos)
        {
            return field_values;
        }
        auto values_str = query.substr(left_pos + 1, right_pos - left_pos - 1);

        std::string current_value;
        bool in_single_quote = false;
        bool in_double_quote = false;

        for (size_t i = 0; i < values_str.size(); ++i)
        {
            char c = values_str[i];

            if (c == '\'' && !in_double_quote)
            {
                in_single_quote = !in_single_quote;
                current_value += c;
            }
            else if (c == '"' && !in_single_quote)
            {
                in_double_quote = !in_double_quote;
                current_value += c;
            }
            else if (c == ',' && !in_single_quote && !in_double_quote)
            {
                IronHandle::Strings::strip(current_value);

                if ((current_value.size() >= 2 && current_value.front() == '\'' && current_value.back() == '\'') ||
                    (current_value.size() >= 2 && current_value.front() == '"' && current_value.back() == '"'))
                {
                    current_value = current_value.substr(1, current_value.size() - 2);
                }
                field_values.push_back(current_value);
                current_value.clear();
            }
            else
            {
                current_value += c;
            }
        }

        IronHandle::Strings::strip(current_value);
        if ((current_value.size() >= 2 && current_value.front() == '\'' && current_value.back() == '\'') ||
            (current_value.size() >= 2 && current_value.front() == '"' && current_value.back() == '"'))
        {
            current_value = current_value.substr(1, current_value.size() - 2);
        }
        field_values.push_back(current_value);

        return field_values;
    }
} // namespace IronParser