#include <unordered_map>
#include <mutex>
#include <algorithm>

#include "iron_proces.hpp"
#include "iron_object.hpp"
#include "iron_status.hpp"
#include "iron_keywds.hpp"
#include "iron_verify.hpp"
#include "iron_stdio.hpp"
#include "iron_handle.hpp"
#include "iron_logsystem.hpp"

/* ***********************************************************
 * zone brief:                                               *
 *           Global alias settings                           *
 ************************************************************/

using ios = IronStdOst::OutStream;
using kwl = IronKeywds::Level;
using log = IronLogSystem::LogOut;

namespace _IronInnerProces_
{
    struct _TbMap
    {
        /* 结构解析: 表名:表索引 */
        std::unordered_map<std::string, int> table_map;
        /* 表名最大宽度 */
        int table_name_max_width{0};
    }; // struct _TbMap

    struct _FdMap
    {
        /* 结构解析: 表名称->(字段名称:字段类型) */
        std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> field_map;
        /* 结构解析: 表名称->(字段名称:字段索引) */
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> field_index_map;
        /* 结构解析: 表名称->字段名称最大宽度 */
        std::unordered_map<std::string, int> field_name_max_width_map;
        /* 结构解析: 表名称->字段类型最大宽度 */
        std::unordered_map<std::string, int> field_type_max_width_map;
    }; // struct _FdMap

    class _Pub
    {
    private:
        _Pub() = delete;
        ~_Pub() = delete;

    public:
        static auto _inspectFieldNameRepeat(const std::vector<std::string> &field_names) -> bool;
    }; // private class _Pub

    class _Level
    {
    private:
        _Level() = delete;
        ~_Level() = delete;

    public:
        class _Database
        {
        private:
            _Database() = delete;
            ~_Database() = delete;

            /* 结构解析: 数据库名:数据库ID */
            static std::unordered_map<std::string, int> databases_map;
            /* 数据库名最大宽度 */
            static int database_name_max_width;

        public:
            static void _recordDatabaseIndexToMap(const std::string &database_name, int database_index);
            static void _synchronizationDatabaseIndexToMap(const std::string &database_name);
            static auto _obtainDatabaseNames() -> std::vector<std::string>;
            static auto _obtainDatabaseNameMaxWidth() -> int;
            static auto _obtainDatabaseIndex(const std::string &database_name) -> int;

        public:
            static auto _inspectExistDatabase(const std::string &database_name) -> bool;
            static auto _inspectEmptyDatabases() -> bool;
        }; // private class _Database

        class _Table
        {
        private:
            _Table() = delete;
            ~_Table() = delete;

            /* 结构解析: 数据库名:表映射 -> 表名:表索引 */
            static std::unordered_map<std::string, _TbMap> tables_map;

        public:
            static void _recordTableIndexToMap(const std::string &database_name, const std::string &table_name, int table_index);
            static void _synchronizationTableIndexToMap(const std::string &database_name, const std::string &table_name);
            static auto _obtainTableNames(const std::string &database_name) -> std::vector<std::string>;
            static auto _obtainTableIndex(const std::string &database_name, const std::string &table_name) -> int;
            static auto _obtainTableNameMaxWidth(const std::string &database_name) -> int;

        public:
            static auto _inspectEmptyTables(const std::string &database_name) -> bool;
            static auto _inspectExistTable(const std::string &database_name, const std::string &table_name) -> bool;
        }; // private class _Table

        class _Field
        {
        private:
            _Field() = delete;
            ~_Field() = delete;

            /* 结构解析: 数据库名:字段映射 -> 表名称->(字段名称:字段类型) */
            static std::unordered_map<std::string, _FdMap> fields_map;

        public:
            static void _recordFieldAndTypeToMap(const std::string &database_name, const std::string &table_name,
                                                 const std::vector<std::string> &field_names,
                                                 const std::vector<std::string> &field_types);
            static auto _obtainFieldNames(const std::string &database_name, const std::string &table_name)
                -> std::vector<std::string>;
            static auto _obtainFieldTypes(const std::string &database_name, const std::string &table_name)
                -> std::vector<std::string>;
            static auto _obtainFieldNameMaxWidth(const std::string &database_name, const std::string &table_name) -> int;
            static auto _obtainFieldTypeMaxWidth(const std::string &database_name, const std::string &table_name) -> int;
            static auto _obtainFieldIndex(const std::string &database_name, const std::string &table_name,
                                          const std::string &field_name) -> int;
        }; // private class _Field

        class _Data
        {
        private:
            _Data() = delete;
            ~_Data() = delete;
            /* 结构解析: 数据库名:数据映射 -> 表名称->(list[field_value1_width, field_value2_width, ...]) */
            static std::unordered_map<std::string, std::unordered_map<std::string, std::vector<int>>> data_map;

        public:
            static void _recordDataRowWidthToMap(const std::string &database_name, const std::string &table_name,
                                                 const std::vector<int> &field_value_widths);
            static auto _obtainDataRowWidth(const std::string &database_name, const std::string &table_name) -> std::vector<int>;
        }; // private class _Data

        class _Link
        {
        private:
            _Link() = delete;
            ~_Link() = delete;

        public:
            static std::mutex linkmtx;
            static std::vector<int> fields_column_max;
            static std::vector<int> datas_column_max;

            static auto addInt(const int &val, std::vector<int> &tar_array) -> void;
            static auto getTarIntArray(const std::vector<int> &tar_array) -> std::vector<int>;
        }; // private class _Link

    }; // private class _Level

    /***********************************************************
     * zone brief:                                             *
     *                                                         *
     * define:                                                 *
     *        Declaration Definition                           *
     **********************************************************/

    std::unordered_map<std::string, int> _Level::_Database::databases_map;
    int _Level::_Database::database_name_max_width{0};
    std::unordered_map<std::string, _TbMap> _Level::_Table::tables_map;
    std::unordered_map<std::string, _FdMap> _Level::_Field::fields_map;
    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<int>>> _Level::_Data::data_map;

    std::mutex _Level::_Link::linkmtx;
    std::vector<int> _Level::_Link::fields_column_max;
    std::vector<int> _Level::_Link::datas_column_max;

    /**
     * @brief Records the database index to the map.
     *
     * @param database_name The name of the database.
     * @param database_index The index of the database.
     */
    void _Level::_Database::_recordDatabaseIndexToMap(const std::string &database_name, int database_index)
    {
        databases_map[database_name] = database_index;
        database_name_max_width = std::max(database_name_max_width, IronHandle::Strings::getDisplayWidth(database_name));
    }

    /**
     * @brief Synchronizes the database index in the map by removing the specified database.
     *
     * @param database_name The name of the database to remove.
     */
    void _Level::_Database::_synchronizationDatabaseIndexToMap(const std::string &database_name)
    {
        // Delete the specified mapping relationship
        size_t delete_res = databases_map.erase(database_name);

        if (delete_res == 0)
        {
            ios::err64(kwl::fatal() + "delete database failed: " + database_name);
            log::IRON_DEBUG("delete database failed: " + database_name);
        }
    }

    /**
     * @brief Obtains all database names.
     *
     * @return A vector containing all database names.
     */
    auto _Level::_Database::_obtainDatabaseNames() -> std::vector<std::string>
    {
        std::vector<std::string> tmp_container;
        tmp_container.reserve(databases_map.size());

        for (const auto &database_name : databases_map)
        {
            tmp_container.push_back(database_name.first);
        }

        return tmp_container;
    }

    /**
     * @brief Obtains the maximum width of database names.
     *
     * @return The maximum width of database names.
     */
    auto _Level::_Database::_obtainDatabaseNameMaxWidth() -> int
    {
        return database_name_max_width;
    }

    /**
     * @brief Obtains the index of the specified database.
     *
     * @param database_name The name of the database.
     * @return The index of the database.
     */
    auto _Level::_Database::_obtainDatabaseIndex(const std::string &database_name) -> int
    {
        return databases_map[database_name];
    }

    /**
     * @brief Checks if the specified database exists.
     *
     * @param database_name The name of the database to check.
     * @return true if the database exists, false otherwise.
     */
    auto _Level::_Database::_inspectExistDatabase(const std::string &database_name) -> bool
    {
        return databases_map.find(database_name) != databases_map.end();
    }

    /**
     * @brief Checks if there are no databases.
     *
     * @return true if there are no databases, false otherwise.
     */
    auto _Level::_Database::_inspectEmptyDatabases() -> bool
    {
        if (databases_map.empty())
        {
            return true;
        }
        return false;
    }

    /**
     * @brief Checks if there are duplicate field names.
     *
     * @param field_names A vector of field names to check.
     * @return true if there are duplicate field names, false otherwise.
     */
    auto _Pub::_inspectFieldNameRepeat(const std::vector<std::string> &field_names) -> bool
    {
        std::unordered_set<std::string> field_name_set(field_names.begin(), field_names.end());
        return field_name_set.size() != field_names.size();
    }

    /**
     * @brief Records the table index to the map.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @param table_index The index of the table.
     */
    void _Level::_Table::_recordTableIndexToMap(const std::string &database_name, const std::string &table_name, int table_index)
    {
        tables_map[database_name].table_map[table_name] = table_index;
        tables_map[database_name].table_name_max_width = std::max(
            tables_map[database_name].table_name_max_width, IronHandle::Strings::getDisplayWidth(table_name));
    }

    /**
     * @brief Obtains all table names for the specified database.
     *
     * @param database_name The name of the database.
     * @return A vector containing all table names for the database.
     */
    auto _Level::_Table::_obtainTableNames(const std::string &database_name) -> std::vector<std::string>
    {
        std::vector<std::string> tmp_container;
        tmp_container.reserve(tables_map[database_name].table_map.size());

        for (const auto &table_name : tables_map[database_name].table_map)
        {
            tmp_container.push_back(table_name.first);
        }

        return tmp_container;
    }

    /**
     * @brief Obtains the index of the specified table in the database.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return The index of the table.
     */
    auto _Level::_Table::_obtainTableIndex(const std::string &database_name, const std::string &table_name) -> int
    {
        return tables_map[database_name].table_map[table_name];
    }

    /**
     * @brief Checks if there are no tables in the database.
     *
     * @param database_name The name of the database.
     * @return true if there are no tables, false otherwise.
     */
    auto _Level::_Table::_inspectEmptyTables(const std::string &database_name) -> bool
    {
        if (tables_map[database_name].table_map.empty())
        {
            return true;
        }
        return false;
    }

    /**
     * @brief Checks if the specified table exists in the database.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table to check.
     * @return true if the table exists, false otherwise.
     */
    auto _Level::_Table::_inspectExistTable(const std::string &database_name, const std::string &table_name) -> bool
    {
        return tables_map[database_name].table_map.find(table_name) != tables_map[database_name].table_map.end();
    }

    /**
     * @brief Obtains the maximum width of table names for the specified database.
     *
     * @param database_name The name of the database.
     * @return The maximum width of table names for the database.
     */
    auto _Level::_Table::_obtainTableNameMaxWidth(const std::string &database_name) -> int
    {
        return tables_map[database_name].table_name_max_width;
    }

    /**
     * @brief Records field names and types to the map.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @param field_names A vector of field names.
     * @param field_types A vector of field types.
     */
    void _Level::_Field::_recordFieldAndTypeToMap(const std::string &database_name, const std::string &table_name,
                                                  const std::vector<std::string> &field_names,
                                                  const std::vector<std::string> &field_types)
    {
        fields_map[database_name].field_map[table_name] = std::vector<std::pair<std::string, std::string>>();
        for (size_t i = 0; i < field_names.size(); ++i)
        {
            // record field name and type to vector
            fields_map[database_name].field_map[table_name].emplace_back(field_names[i], field_types[i]);
            fields_map[database_name].field_index_map[table_name].emplace_back(field_names[i], i);

            // record current table field name max width
            fields_map[database_name].field_name_max_width_map[table_name] =
                std::max(fields_map[database_name].field_name_max_width_map[table_name],
                         IronHandle::Strings::getDisplayWidth(field_names[i]));

            // record current table field type max width
            fields_map[database_name].field_type_max_width_map[table_name] =
                std::max(fields_map[database_name].field_type_max_width_map[table_name],
                         IronHandle::Strings::getDisplayWidth(field_types[i]));
        }
    }

    /**
     * @brief Obtains all field names for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return A vector containing all field names for the table.
     */
    auto _Level::_Field::_obtainFieldNames(const std::string &database_name, const std::string &table_name) -> std::vector<std::string>
    {
        std::vector<std::string> tmp_container;
        tmp_container.reserve(fields_map[database_name].field_map[table_name].size());

        for (const auto &field : fields_map[database_name].field_map[table_name])
        {
            tmp_container.push_back(field.first);
        }

        return tmp_container;
    }

    /**
     * @brief Obtains all field types for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return A vector containing all field types for the table.
     */
    auto _Level::_Field::_obtainFieldTypes(const std::string &database_name, const std::string &table_name) -> std::vector<std::string>
    {
        std::vector<std::string> tmp_container;
        tmp_container.reserve(fields_map[database_name].field_map[table_name].size());

        for (const auto &field : fields_map[database_name].field_map[table_name])
        {
            tmp_container.push_back(field.second);
        }

        return tmp_container;
    }

    /**
     * @brief Obtains the maximum width of field names for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return The maximum width of field names for the table.
     */
    auto _Level::_Field::_obtainFieldNameMaxWidth(const std::string &database_name, const std::string &table_name) -> int
    {
        return fields_map[database_name].field_name_max_width_map[table_name];
    }

    /**
     * @brief Obtains the maximum width of field types for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return The maximum width of field types for the table.
     */
    auto _Level::_Field::_obtainFieldTypeMaxWidth(const std::string &database_name, const std::string &table_name) -> int
    {
        return fields_map[database_name].field_type_max_width_map[table_name];
    }

    /**
     * @brief Obtains the index of the specified field in the table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @param field_name The name of the field.
     * @return The index of the field, or -1 if not found.
     */
    auto _Level::_Field::_obtainFieldIndex(const std::string &database_name, const std::string &table_name,
                                           const std::string &field_name) -> int
    {
        for (const auto &field_index : fields_map[database_name].field_index_map[table_name])
        {
            if (field_index.first == field_name)
            {
                return field_index.second;
            }
        }
        return -1;
    }

    /**
     * @brief Records data row widths to the map.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @param field_value_widths A vector of field value widths.
     */
    void _Level::_Data::_recordDataRowWidthToMap(const std::string &database_name, const std::string &table_name,
                                                 const std::vector<int> &field_value_widths)
    {
        if (data_map[database_name][table_name].size() < field_value_widths.size())
        {
            data_map[database_name][table_name].resize(field_value_widths.size(), 0);
        }

        for (int i{0}; i < field_value_widths.size(); ++i)
        {
            data_map[database_name][table_name][i] = std::max(data_map[database_name][table_name][i], field_value_widths[i]);
        }
    }

    /**
     * @brief Obtains data row widths for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return A vector containing data row widths for the table.
     */
    auto _Level::_Data::_obtainDataRowWidth(const std::string &database_name, const std::string &table_name) -> std::vector<int>
    {
        return data_map[database_name][table_name];
    }

    /**
     * @brief Synchronizes the table index in the map by removing the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table to remove.
     */
    void _Level::_Table::_synchronizationTableIndexToMap(const std::string &database_name, const std::string &table_name)
    {
        size_t delete_res = tables_map[database_name].table_map.erase(table_name);

        if (delete_res == 0)
        {
            ios::err64("fatal: delete table failed: " + table_name);
            log::IRON_DEBUG("delete table failed: " + table_name);
            return;
        }
    }

    /**
     * @brief Adds an integer to the vector.
     *
     * @param val The integer to add.
     */
    void _Level::_Link::addInt(const int &val, std::vector<int> &tar_array)
    {
        std::lock_guard<std::mutex> lock(linkmtx);
        tar_array.push_back(val);
    }

    /**
     * @brief Obtains the vector of integers.
     *
     * @return A vector of integers.
     */
    auto _Level::_Link::getTarIntArray(const std::vector<int> &tar_array) -> std::vector<int>
    {
        return tar_array;
    }

} // namespace _IronInnerProces_

namespace IronProces
{
    /**
     * @brief Obtains all database names.
     *
     * @return A vector containing all database names.
     */
    auto Gets::getDatabaseNames() -> std::vector<std::string>
    {
        return _IronInnerProces_::_Level::_Database::_obtainDatabaseNames();
    }

    /**
     * @brief Obtains the maximum width of database names.
     *
     * @return The maximum width of database names.
     */
    auto Gets::getDatabaseNameMaxWidth() -> int
    {
        return _IronInnerProces_::_Level::_Database::_obtainDatabaseNameMaxWidth();
    }

    /**
     * @brief Obtains all table names for the specified database.
     *
     * @param database_name The name of the database.
     * @return A vector containing all table names for the database.
     */
    auto Gets::getTableNames(const std::string &database_name) -> std::vector<std::string>
    {
        return _IronInnerProces_::_Level::_Table::_obtainTableNames(database_name);
    }

    /**
     * @brief Obtains the maximum width of table names for the specified database.
     *
     * @param database_name The name of the database.
     * @return The maximum width of table names for the database.
     */
    auto Gets::getTableNameMaxWidth(const std::string &database_name) -> int
    {
        return _IronInnerProces_::_Level::_Table::_obtainTableNameMaxWidth(database_name);
    }

    /**
     * @brief Obtains all field names for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return A vector containing all field names for the table.
     */
    auto Gets::getFieldNames(const std::string &database_name, const std::string &table_name) -> std::vector<std::string>
    {
        return _IronInnerProces_::_Level::_Field::_obtainFieldNames(database_name, table_name);
    }

    /**
     * @brief Obtains all field types for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return A vector containing all field types for the table.
     */
    auto Gets::getFieldTypes(const std::string &database_name, const std::string &table_name) -> std::vector<std::string>
    {
        return _IronInnerProces_::_Level::_Field::_obtainFieldTypes(database_name, table_name);
    }

    /**
     * @brief Obtains the maximum width of field names for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return The maximum width of field names for the table.
     */
    auto Gets::getFieldNameMaxWidth(const std::string &database_name, const std::string &table_name) -> int
    {
        return _IronInnerProces_::_Level::_Field::_obtainFieldNameMaxWidth(database_name, table_name);
    }

    /**
     * @brief Obtains the maximum width of field types for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return The maximum width of field types for the table.
     */
    auto Gets::getFieldTypeMaxWidth(const std::string &database_name, const std::string &table_name) -> int
    {
        return _IronInnerProces_::_Level::_Field::_obtainFieldTypeMaxWidth(database_name, table_name);
    }

    /**
     * @brief Obtains all data rows for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return A 2D vector containing all data rows for the table.
     */
    auto Gets::getTableDatas(const std::string &database_name, const std::string &table_name)
        -> std::vector<std::vector<std::string>>
    {
        auto database_index{_IronInnerProces_::_Level::_Database::_obtainDatabaseIndex(database_name)};
        auto table_index{_IronInnerProces_::_Level::_Table::_obtainTableIndex(database_name, table_name)};
        auto current_table{IronObject::Interface::databases[database_index].tables[table_index]};

        std::vector<std::vector<std::string>> table_datas;
        table_datas.reserve(current_table.values.size());

        for (const auto &row : current_table.values)
        {
            std::vector<std::string> tmp_row;
            for (const auto &value : row)
            {
                tmp_row.push_back(IronVerify::Inspector::valueToString(value));
            }
            table_datas.push_back(tmp_row);
        }

        return table_datas;
    }

    /**
     * @brief Obtains data row widths for the specified table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @return A vector containing data row widths for the table.
     */
    auto Gets::getDataRowWidth(const std::string &database_name, const std::string &table_name) -> std::vector<int>
    {
        return _IronInnerProces_::_Level::_Data::_obtainDataRowWidth(database_name, table_name);
    }

    /**
     * @brief Obtains a query array for specified fields in the table.
     *
     * @param database_name The name of the database.
     * @param table_name The name of the table.
     * @param field_names A vector of field names to query.
     * @param ref_bool Reference to a boolean that will be set to true if the query is successful.
     * @return A 2D vector containing the query results.
     */
    auto Gets::getTargetQueryArray(const std::string &database_name, const std::string &table_name,
                                   const std::vector<std::string> &field_names, bool &ref_bool)
        -> std::vector<std::vector<std::string>>
    {
        ref_bool = false;

        if (field_names.empty())
        {
            return {};
        }

        int database_index{_IronInnerProces_::_Level::_Database::_obtainDatabaseIndex(database_name)};
        if (database_index == -1)
        {
            return {};
        }

        int table_index{_IronInnerProces_::_Level::_Table::_obtainTableIndex(database_name, table_name)};
        if (table_index == -1)
        {
            return {};
        }

        auto &current_table{IronObject::Interface::databases[database_index].tables[table_index]};

        // pre-calculate all field indices (performance optimization: avoid repeated lookups in the loop)
        std::vector<int> field_indices;
        field_indices.reserve(field_names.size());

        for (const auto &field_name : field_names)
        {
            int field_index{_IronInnerProces_::_Level::_Field::_obtainFieldIndex(database_name, table_name, field_name)};
            if (field_index == -1)
            {
                return {};
            }
            field_indices.push_back(field_index);
        }

        std::vector<std::vector<std::string>> target_query_array;
        target_query_array.reserve(current_table.values.size());

        for (const auto &row : current_table.values)
        {
            std::vector<std::string> tmp_row;
            tmp_row.reserve(field_indices.size());

            for (int field_index : field_indices)
            {
                tmp_row.push_back(IronVerify::Inspector::valueToString(row[field_index]));
            }
            target_query_array.push_back(std::move(tmp_row));
        }

        ref_bool = true;
        return target_query_array;
    }

    /**
     * @brief Creates a new database.
     *
     * This function creates a new database with the specified name and adds it to the database list.
     *
     * @param database_name The name of the database to create.
     */
    void Core::createDatabase(const std::string &database_name)
    {
        std::unique_lock<std::shared_mutex> lock(IronObject::Interface::mtx);

        if (_IronInnerProces_::_Level::_Database::_inspectExistDatabase(database_name))
        {
            ios::err64(IronKeywds::Level::error() + "database already exist:'" + database_name + "'");
            log::IRON_DEBUG("database already exist:'" + database_name + "'");
            return;
        }

        int database_index{static_cast<int>(IronObject::Interface::databases.size())};
        IronObject::Interface::databases.push_back({database_name, {}});
        _IronInnerProces_::_Level::_Database::_recordDatabaseIndexToMap(database_name, database_index);
    }

    /**
     * @brief Sets the current database to use.
     *
     * This function sets the specified database as the current active database for subsequent operations.
     *
     * @param database_name The name of the database to use.
     */
    void Core::useDatabase(const std::string &database_name)
    {
        std::unique_lock<std::shared_mutex> lock(IronObject::Interface::mtx);

        if (!_IronInnerProces_::_Level::_Database::_inspectExistDatabase(database_name))
        {
            ios::err64(IronKeywds::Level::error() + "database not exist:'" + database_name + "'");
            log::IRON_DEBUG("database not exist:'" + database_name + "'");
            return;
        }

        IronStatus::Manage::settingDatabaseName(database_name);
        IronStatus::Manage::settingTablesNumber(_IronInnerProces_::_Level::_Table::_obtainTableNames(database_name).size());
    }

    /**
     * @brief Creates a new table in the current database.
     *
     * This function creates a new table with the specified name, field names, and field types
     * in the currently selected database.
     *
     * @param table_name The name of the table to create.
     * @param field_names A vector of field names for the table.
     * @param field_types A vector of field types corresponding to the field names.
     */
    void Core::createTable(const std::string &table_name, const std::vector<std::string> &field_names,
                           const std::vector<std::string> &field_types)
    {
        std::unique_lock<std::shared_mutex> lock(IronObject::Interface::mtx);

        std::string database_name{IronStatus::Manage::getDatabaseName()};
        if (database_name == IronKeywds::Kw::none_())
        {
            ios::err64(IronKeywds::Level::error() + "database not selected,you must choice a database object first.");
            log::IRON_DEBUG("database not selected,you must choice a database object first.");
            return;
        }

        if (field_names.size() != field_types.size())
        {
            ios::err64(IronKeywds::Level::error() + "field names and types number not match");
            log::IRON_DEBUG("field names and types number not match");
            return;
        }

        if (_IronInnerProces_::_Pub::_inspectFieldNameRepeat(field_names))
        {
            ios::err64(IronKeywds::Level::error() + "repeat field names");
            log::IRON_DEBUG("repeat field names");
            return;
        }

        for (const auto &field_type : field_types)
        {
            if (IronVerify::Inspector::stringToMaskType(field_type) == IronStruct::MaskType::ERRT)
            {
                ios::err64(IronKeywds::Level::error() + "unknown field type:'" + field_type + "'");
                log::IRON_DEBUG("unknown field type:'" + field_type + "'");
                return;
            };
        }

        if (_IronInnerProces_::_Level::_Table::_inspectExistTable(database_name, table_name))
        {
            ios::err64(IronKeywds::Level::error() + "table already exist:'" + table_name + "'");
            log::IRON_DEBUG("table already exist:'" + table_name + "'");
            return;
        }

        int database_index{_IronInnerProces_::_Level::_Database::_obtainDatabaseIndex(database_name)};

        IronStruct::Table new_table;
        new_table.name = table_name;

        for (size_t i{0}; i < field_names.size(); ++i)
        {
            IronStruct::Field field;
            field.name = field_names[i];
            field.type = IronVerify::Inspector::stringToMaskType(field_types[i]);
            new_table.fields.push_back(field);
        }
        IronObject::Interface::databases[database_index].tables.push_back(new_table);

        int table_index{static_cast<int>(IronObject::Interface::databases[database_index].tables.size()) - 1};

        _IronInnerProces_::_Level::_Table::_recordTableIndexToMap(database_name, table_name, table_index);
        _IronInnerProces_::_Level::_Field::_recordFieldAndTypeToMap(database_name, table_name, field_names, field_types);
    }

    /**
     * @brief Inserts data into a table.
     *
     * This function inserts a new row of data into the specified table with the given field names and values.
     *
     * @param table_name The name of the table to insert data into.
     * @param field_names A vector of field names for the data.
     * @param field_values A vector of field values corresponding to the field names.
     */
    void Core::insertData(const std::string &table_name, const std::vector<std::string> &field_names,
                          const std::vector<std::string> &field_values)
    {
        std::unique_lock<std::shared_mutex> lock(IronObject::Interface::mtx);

        std::string database_name{IronStatus::Manage::getDatabaseName()};

        if (database_name == IronKeywds::Kw::none_())
        {
            ios::err64(IronKeywds::Level::error() + "database not selected,you must choice a database object first.");
            log::IRON_DEBUG("database not selected,you must choice a database object first.");
            return;
        }

        if (_IronInnerProces_::_Pub::_inspectFieldNameRepeat(field_names))
        {
            ios::err64(IronKeywds::Level::error() + "repeat field names");
            log::IRON_DEBUG("repeat field names");
            return;
        }

        if (field_names.size() != field_values.size())
        {
            ios::err64(IronKeywds::Level::error() + "field names and values number not match");
            log::IRON_DEBUG("field names and values number not match");
            return;
        }

        int database_index{_IronInnerProces_::_Level::_Database::_obtainDatabaseIndex(database_name)};
        int table_index{_IronInnerProces_::_Level::_Table::_obtainTableIndex(database_name, table_name)};

        if (table_index == -1)
        {
            ios::err64(IronKeywds::Level::error() + "table not exist:'" + table_name + "'");
            log::IRON_DEBUG("table not exist:'" + table_name + "'");
            return;
        }

        // convert string values to Value type
        std::vector<IronStruct::Value> converted_values;
        converted_values.reserve(field_values.size());

        std::vector<int> field_value_widths;
        field_value_widths.reserve(field_values.size());

        for (const auto &value : field_values)
        {
            converted_values.push_back(IronVerify::Inspector::stringToValue(value));
            field_value_widths.push_back(value.size());
        }

        IronObject::Interface::databases[database_index].tables[table_index].values.push_back(converted_values);
        _IronInnerProces_::_Level::_Data::_recordDataRowWidthToMap(database_name, table_name, field_value_widths);
    }

    /**
     * @brief Drops a database.
     *
     * This function deletes the specified database and all its tables from the system.
     *
     * @param database_name The name of the database to drop.
     */
    void Core::dropDatabase(const std::string &database_name)
    {
        std::unique_lock<std::shared_mutex> lock(IronObject::Interface::mtx);

        // check if databases is empty
        if (_IronInnerProces_::_Level::_Database::_inspectEmptyDatabases())
        {
            ios::err64(IronKeywds::Level::error() + "delete failed, databases is empty!");
            log::IRON_DEBUG("delete failed, databases is empty!");
            return;
        }

        // check if database exists
        if (!_IronInnerProces_::_Level::_Database::_inspectExistDatabase(database_name))
        {
            ios::err64(IronKeywds::Level::error() + "delete failed, undefined database: " + database_name);
            log::IRON_DEBUG("delete failed, undefined database: " + database_name);
            return;
        }

        // execute drop database operation
        int database_index{_IronInnerProces_::_Level::_Database::_obtainDatabaseIndex(database_name)};
        auto &databases = IronObject::Interface::databases;

        databases.erase(databases.begin() + database_index);

        // delete map mapping to keep synchronization
        _IronInnerProces_::_Level::_Database::_synchronizationDatabaseIndexToMap(database_name);
    }

    /**
     * @brief Drops a table from a database.
     *
     * This function deletes the specified table from the specified database.
     *
     * @param database_name The name of the database containing the table.
     * @param table_name The name of the table to drop.
     */
    void Core::dropTable(const std::string &database_name, const std::string &table_name)
    {
        std::unique_lock<std::shared_mutex> lock(IronObject::Interface::mtx);

        // check if databases is empty
        if (_IronInnerProces_::_Level::_Database::_inspectEmptyDatabases())
        {
            ios::err64(IronKeywds::Level::error() + "delete failed, databases is empty!");
            log::IRON_DEBUG("delete failed, databases is empty!");
            return;
        }

        // check if database exists
        if (!_IronInnerProces_::_Level::_Database::_inspectExistDatabase(database_name))
        {
            ios::err64(IronKeywds::Level::error() + "delete failed, undefined database: " + database_name);
            log::IRON_DEBUG("delete failed, undefined database: " + database_name);
            return;
        }

        // check if table exists
        if (!_IronInnerProces_::_Level::_Table::_inspectExistTable(database_name, table_name))
        {
            ios::err64(IronKeywds::Level::error() + "delete failed, undefined table: " + table_name);
            log::IRON_DEBUG("delete failed, undefined table: " + table_name);
            return;
        }

        // execute drop table operation
        int database_index{_IronInnerProces_::_Level::_Database::_obtainDatabaseIndex(database_name)};
        int table_index{_IronInnerProces_::_Level::_Table::_obtainTableIndex(database_name, table_name)};
        auto &databases = IronObject::Interface::databases.at(database_index);

        databases.tables.erase(databases.tables.begin() + table_index);

        // delete map mapping to keep synchronization
        _IronInnerProces_::_Level::_Table::_synchronizationTableIndexToMap(database_name, table_name);
    }

    /**
     * @brief Links two tables in a database.
     *
     * This function creates a new table by merging fields and data from two existing tables.
     * If the tables share common fields, it merges rows based on the first common field.
     * If no common fields exist, it simply appends rows from both tables.
     *
     * @param database_name The name of the database containing the tables.
     * @param table_src_name The name of the source table.
     * @param table_dst_name The name of the destination table.
     * @param new_table_name The name of the new table to create.
     */
    void Core::linkTable(const std::string &database_name, const std::string &table_src_name,
                         const std::string &table_dst_name, const std::string &new_table_name)
    {
        bool is_absolute = !database_name.empty() && database_name != IronKeywds::Kw::none_();

        if (!is_absolute && IronStatus::Manage::getDatabaseName() == IronKeywds::Kw::none_())
        {
            ios::err64(IronKeywds::Level::error() + "no database selected");
            log::IRON_DEBUG("no database selected");
            return;
        }

        if (!is_absolute && IronStatus::Manage::getDatabaseName() != database_name)
        {
            ios::err64(IronKeywds::Level::error() + "database name not match");
            log::IRON_DEBUG("database name not match");
            return;
        }

        // check if table names exist
        std::vector<std::string> tb_array{table_src_name, table_dst_name};

        for (const auto &tb_name : tb_array)
        {
            if (!_IronInnerProces_::_Level::_Table::_inspectExistTable(database_name, tb_name))
            {
                ios::err64(IronKeywds::Level::error() + "undefined table: " + tb_name);
                log::IRON_DEBUG("undefined table: " + tb_name);
                return;
            }
        }

        // check if new table name exists
        if (_IronInnerProces_::_Level::_Table::_inspectExistTable(database_name, new_table_name))
        {
            ios::err64(IronKeywds::Level::error() + "defined table can not be used to link table: " + new_table_name);
            log::IRON_DEBUG("defined table can not be used to link table: " + new_table_name);
            return;
        }

        // obtain field names for both tables
        std::vector<std::string> src_fields = _IronInnerProces_::_Level::_Field::_obtainFieldNames(database_name, table_src_name);
        std::vector<std::string> dst_fields = _IronInnerProces_::_Level::_Field::_obtainFieldNames(database_name, table_dst_name);

        // obtain field types for both tables
        std::vector<std::string> src_types = _IronInnerProces_::_Level::_Field::_obtainFieldTypes(database_name, table_src_name);
        std::vector<std::string> dst_types = _IronInnerProces_::_Level::_Field::_obtainFieldTypes(database_name, table_dst_name);

        // merge field names and types
        std::vector<std::string> new_fields{dst_fields};
        std::vector<std::string> new_types{dst_types};

        // check if field names and types size match
        if (src_fields.size() != src_types.size())
        {
            ios::err64(IronKeywds::Level::error() + "field names and types size mismatch for source table");
            log::IRON_DEBUG("field names and types size mismatch for source table");
            return;
        }

        if (dst_fields.size() != dst_types.size())
        {
            ios::err64(IronKeywds::Level::error() + "field names and types size mismatch for destination table");
            log::IRON_DEBUG("field names and types size mismatch for destination table");
            return;
        }

        for (size_t i = 0; i < src_fields.size(); ++i)
        {
            const std::string &field = src_fields[i];
            const std::string &type = src_types[i];

            auto it = std::find(new_fields.begin(), new_fields.end(), field);
            if (it == new_fields.end())
            {
                // field does not exist, add them in pairs
                new_fields.push_back(field);
                new_types.push_back(type);
            }
        }

        // check if merged field names and types size match
        if (new_fields.size() != new_types.size())
        {
            ios::err64(IronKeywds::Level::error() + "merged field names and types size mismatch");
            log::IRON_DEBUG("merged field names and types size mismatch");
            return;
        }

        // obtain current database index
        int database_index{_IronInnerProces_::_Level::_Database::_obtainDatabaseIndex(database_name)};

        // create new table
        IronStruct::Table new_table;
        new_table.name = new_table_name;

        for (size_t i = 0; i < new_fields.size(); ++i)
        {
            IronStruct::Field field;
            field.name = new_fields[i];
            field.type = IronVerify::Inspector::stringToMaskType(new_types[i]);
            new_table.fields.push_back(field);
        }

        IronObject::Interface::databases[database_index].tables.push_back(new_table);

        int table_index{static_cast<int>(IronObject::Interface::databases[database_index].tables.size()) - 1};

        _IronInnerProces_::_Level::_Table::_recordTableIndexToMap(database_name, new_table_name, table_index);
        _IronInnerProces_::_Level::_Field::_recordFieldAndTypeToMap(database_name, new_table_name, new_fields, new_types);

        // obtain table indices for both source and destination tables
        int src_table_index = _IronInnerProces_::_Level::_Table::_obtainTableIndex(database_name, table_src_name);
        int dst_table_index = _IronInnerProces_::_Level::_Table::_obtainTableIndex(database_name, table_dst_name);

        const auto &src_table = IronObject::Interface::databases[database_index].tables[src_table_index];
        const auto &dst_table = IronObject::Interface::databases[database_index].tables[dst_table_index];
        auto &new_table_ref = IronObject::Interface::databases[database_index].tables[table_index];

        std::vector<int> field_value_widths(new_fields.size(), 0);
        std::vector<std::string> common_fields;

        for (const auto &field : src_fields)
        {
            if (std::find(dst_fields.begin(), dst_fields.end(), field) != dst_fields.end())
            {
                common_fields.push_back(field);
            }
        }

        if (common_fields.empty())
        {
            // No common fields, use simple append mode
            mergeTablesSimpleAppend(src_table, dst_table, new_table_ref, new_fields,
                                    src_fields, dst_fields, field_value_widths);
        }
        else
        {
            // Have common fields, use join mode
            mergeTablesWithJoin(src_table, dst_table, new_table_ref, new_fields,
                                src_fields, dst_fields, common_fields, field_value_widths);
        }

        _IronInnerProces_::_Level::_Data::_recordDataRowWidthToMap(database_name, new_table_name, field_value_widths);
    }

    /**
     * @brief Merges two tables using simple append mode.
     *
     * When no common fields are found, this function appends all rows from both tables
     * to the new table, filling missing fields with default values.
     *
     * @param src_table Source table to merge from.
     * @param dst_table Destination table to merge from.
     * @param new_table New table to merge into.
     * @param new_fields Combined fields from both tables.
     * @param src_fields Fields from source table.
     * @param dst_fields Fields from destination table.
     * @param field_value_widths Output parameter for field width calculation.
     */
    void Core::mergeTablesSimpleAppend(const IronStruct::Table &src_table,
                                       const IronStruct::Table &dst_table,
                                       IronStruct::Table &new_table,
                                       const std::vector<std::string> &new_fields,
                                       const std::vector<std::string> &src_fields,
                                       const std::vector<std::string> &dst_fields,
                                       std::vector<int> &field_value_widths)
    {
        // Process destination table rows
        for (const auto &row : dst_table.values)
        {
            std::vector<IronStruct::Value> new_row = createMergedRow(row, new_fields, dst_fields);
            updateFieldWidths(new_row, field_value_widths);
            new_table.values.push_back(new_row);
        }

        // Process source table rows
        for (const auto &row : src_table.values)
        {
            std::vector<IronStruct::Value> new_row = createMergedRow(row, new_fields, src_fields);
            updateFieldWidths(new_row, field_value_widths);
            new_table.values.push_back(new_row);
        }
    }

    /**
     * @brief Merges two tables using join mode based on common fields.
     *
     * When common fields are found, this function merges rows based on the first common field,
     * creating combined rows with data from both tables.
     *
     * @param src_table Source table to merge from.
     * @param dst_table Destination table to merge from.
     * @param new_table New table to merge into.
     * @param new_fields Combined fields from both tables.
     * @param src_fields Fields from source table.
     * @param dst_fields Fields from destination table.
     * @param common_fields Common fields for linking.
     * @param field_value_widths Output parameter for field width calculation.
     */
    void Core::mergeTablesWithJoin(const IronStruct::Table &src_table,
                                   const IronStruct::Table &dst_table,
                                   IronStruct::Table &new_table,
                                   const std::vector<std::string> &new_fields,
                                   const std::vector<std::string> &src_fields,
                                   const std::vector<std::string> &dst_fields,
                                   const std::vector<std::string> &common_fields,
                                   std::vector<int> &field_value_widths)
    {
        const std::string &link_field = common_fields[0];

        // Find link field indices in both tables
        size_t src_link_index = std::distance(src_fields.begin(),
                                              std::find(src_fields.begin(), src_fields.end(), link_field));
        size_t dst_link_index = std::distance(dst_fields.begin(),
                                              std::find(dst_fields.begin(), dst_fields.end(), link_field));

        // Build mapping of link field values to destination row indices
        std::unordered_map<std::string, size_t> dst_row_map;
        for (size_t row_idx = 0; row_idx < dst_table.values.size(); ++row_idx)
        {
            const auto &row = dst_table.values[row_idx];
            if (dst_link_index >= row.size())
            {
                continue;
            }
            std::string key = IronVerify::Inspector::valueToString(row[dst_link_index]);
            dst_row_map[key] = row_idx;
        }

        // Track merged destination rows
        std::vector<bool> dst_row_merged(dst_table.values.size(), false);

        // Process source table rows and merge with destination
        for (const auto &src_row : src_table.values)
        {
            std::vector<IronStruct::Value> new_row = createMergedRow(src_row, new_fields, src_fields);

            // Try to find matching destination row
            if (src_link_index < src_row.size())
            {
                std::string link_value = IronVerify::Inspector::valueToString(src_row[src_link_index]);
                auto map_it = dst_row_map.find(link_value);
                if (map_it != dst_row_map.end())
                {
                    size_t dst_row_idx = map_it->second;
                    const auto &dst_row = dst_table.values[dst_row_idx];
                    dst_row_merged[dst_row_idx] = true;

                    // Merge destination data for fields not in source
                    mergeRowData(new_row, dst_row, new_fields, src_fields, dst_fields);
                }
            }

            updateFieldWidths(new_row, field_value_widths);
            new_table.values.push_back(new_row);
        }

        // Add unmerged destination rows
        for (size_t row_idx = 0; row_idx < dst_table.values.size(); ++row_idx)
        {
            if (!dst_row_merged[row_idx])
            {
                std::vector<IronStruct::Value> new_row = createMergedRow(dst_table.values[row_idx],
                                                                         new_fields, dst_fields);
                updateFieldWidths(new_row, field_value_widths);
                new_table.values.push_back(new_row);
            }
        }
    }

    /**
     * @brief Creates a merged row by mapping values from a source row to combined fields.
     *
     * @param source_row Source row data.
     * @param new_fields Combined fields from both tables.
     * @param source_fields Fields from the source table.
     * @return Merged row with values mapped to combined fields.
     */
    std::vector<IronStruct::Value> Core::createMergedRow(const std::vector<IronStruct::Value> &source_row,
                                                         const std::vector<std::string> &new_fields,
                                                         const std::vector<std::string> &source_fields)
    {
        std::vector<IronStruct::Value> new_row(new_fields.size());

        for (size_t i = 0; i < new_fields.size(); ++i)
        {
            const std::string &field = new_fields[i];
            auto it = std::find(source_fields.begin(), source_fields.end(), field);
            if (it != source_fields.end())
            {
                size_t src_index = std::distance(source_fields.begin(), it);
                if (src_index < source_row.size())
                {
                    new_row[i] = source_row[src_index];
                }
            }
        }

        return new_row;
    }

    /**
     * @brief Merges data from a destination row into an existing merged row.
     *
     * @param new_row Existing merged row to update.
     * @param dst_row Destination row with data to merge.
     * @param new_fields Combined fields from both tables.
     * @param src_fields Fields from source table.
     * @param dst_fields Fields from destination table.
     */
    void Core::mergeRowData(std::vector<IronStruct::Value> &new_row,
                            const std::vector<IronStruct::Value> &dst_row,
                            const std::vector<std::string> &new_fields,
                            const std::vector<std::string> &src_fields,
                            const std::vector<std::string> &dst_fields)
    {
        for (size_t i = 0; i < new_fields.size(); ++i)
        {
            const std::string &field = new_fields[i];
            // Only merge fields not in source table
            if (std::find(src_fields.begin(), src_fields.end(), field) != src_fields.end())
            {
                continue;
            }

            auto it = std::find(dst_fields.begin(), dst_fields.end(), field);
            if (it != dst_fields.end())
            {
                size_t dst_index = std::distance(dst_fields.begin(), it);
                if (dst_index < dst_row.size())
                {
                    new_row[i] = dst_row[dst_index];
                }
            }
        }
    }

    /**
     * @brief Updates field width calculations based on values in a row.
     *
     * @param row Row with values to calculate widths from.
     * @param field_value_widths Current field widths to update.
     */
    void Core::updateFieldWidths(const std::vector<IronStruct::Value> &row,
                                 std::vector<int> &field_value_widths)
    {
        for (size_t i = 0; i < row.size() && i < field_value_widths.size(); ++i)
        {
            std::string value_str = IronVerify::Inspector::valueToString(row[i]);
            field_value_widths[i] = std::max(field_value_widths[i],
                                             IronHandle::Strings::getDisplayWidth(value_str));
        }
    }

    namespace Detail
    {
        /**
         * @brief Creates a row with values mapped to the given fields.
         * @param table The table to get field information from.
         * @param row The source row data.
         * @param fields The fields to map values to.
         * @return A new row with values mapped to the given fields.
         */
        std::vector<std::string> createMappedRow(const IronStruct::Table &table,
                                                 const std::vector<IronStruct::Value> &row,
                                                 const std::vector<std::string> &fields)
        {
            std::vector<std::string> new_row;
            new_row.reserve(fields.size());

            for (const auto &field : fields)
            {
                auto field_it = std::find_if(table.fields.begin(), table.fields.end(),
                                             [&field](const IronStruct::Field &f)
                                             { return f.name == field; });
                if (field_it != table.fields.end())
                {
                    size_t field_index = std::distance(table.fields.begin(), field_it);
                    if (field_index < row.size())
                    {
                        new_row.push_back(IronVerify::Inspector::valueToString(row[field_index]));
                    }
                    else
                    {
                        new_row.push_back("");
                    }
                }
                else
                {
                    new_row.push_back("");
                }
            }

            return new_row;
        }

        /**
         * @brief Finds common fields between a table and a list of fields.
         * @param table The table to check.
         * @param fields The fields to compare with.
         * @return A vector of common field names.
         */
        std::vector<std::string> findCommonFields(const IronStruct::Table &table,
                                                  const std::vector<std::string> &fields)
        {
            std::vector<std::string> common_fields;
            for (const auto &field : table.fields)
            {
                if (std::find(fields.begin(), fields.end(), field.name) != fields.end())
                {
                    common_fields.push_back(field.name);
                }
            }
            return common_fields;
        }

        /**
         * @brief Merges table data with join based on common fields.
         * @param current_table The current table to merge.
         * @param merged_table_data The merged data to update.
         * @param fields The combined fields.
         * @param common_fields The common fields for joining.
         */
        void mergeWithJoin(const IronStruct::Table &current_table,
                           std::vector<std::vector<std::string>> &merged_table_data,
                           const std::vector<std::string> &fields,
                           const std::vector<std::string> &common_fields)
        {
            if (common_fields.empty())
                return;

            const std::string &link_field = common_fields[0];

            // 找到连接字段在当前表和结果表中的索引
            size_t current_link_index = std::distance(current_table.fields.begin(),
                                                      std::find_if(current_table.fields.begin(), current_table.fields.end(),
                                                                   [&link_field](const IronStruct::Field &f)
                                                                   { return f.name == link_field; }));

            size_t result_link_index = std::distance(fields.begin(),
                                                     std::find(fields.begin(), fields.end(), link_field));

            // 构建当前表的连接值映射
            std::unordered_map<std::string, size_t> current_row_map;
            for (size_t row_idx = 0; row_idx < current_table.values.size(); ++row_idx)
            {
                const auto &row = current_table.values[row_idx];
                if (current_link_index < row.size())
                {
                    std::string key = IronVerify::Inspector::valueToString(row[current_link_index]);
                    current_row_map[key] = row_idx;
                }
            }

            // 合并数据
            for (auto &result_row : merged_table_data)
            {
                if (result_link_index < result_row.size())
                {
                    std::string link_value = result_row[result_link_index];
                    auto map_it = current_row_map.find(link_value);
                    if (map_it != current_row_map.end())
                    {
                        size_t current_row_idx = map_it->second;
                        const auto &current_row = current_table.values[current_row_idx];

                        // 合并当前表的数据
                        for (size_t j = 0; j < fields.size(); ++j)
                        {
                            const std::string &field = fields[j];
                            auto field_it = std::find_if(current_table.fields.begin(), current_table.fields.end(),
                                                         [&field](const IronStruct::Field &f)
                                                         { return f.name == field; });
                            if (field_it != current_table.fields.end())
                            {
                                size_t field_index = std::distance(current_table.fields.begin(), field_it);
                                if (field_index < current_row.size())
                                {
                                    result_row[j] = IronVerify::Inspector::valueToString(current_row[field_index]);
                                }
                            }
                        }
                    }
                }
            }

            // 添加当前表中未匹配的行
            std::vector<bool> current_row_merged(current_table.values.size(), false);
            for (size_t row_idx = 0; row_idx < current_table.values.size(); ++row_idx)
            {
                const auto &row = current_table.values[row_idx];
                if (current_link_index < row.size())
                {
                    std::string link_value = IronVerify::Inspector::valueToString(row[current_link_index]);
                    auto map_it = current_row_map.find(link_value);
                    if (map_it != current_row_map.end())
                    {
                        current_row_merged[row_idx] = true;
                    }
                }
            }

            for (size_t row_idx = 0; row_idx < current_table.values.size(); ++row_idx)
            {
                if (!current_row_merged[row_idx])
                {
                    merged_table_data.push_back(createMappedRow(current_table, current_table.values[row_idx], fields));
                }
            }
        }

        /**
         * @brief Appends table data to merged data.
         * @param current_table The current table to append.
         * @param merged_table_data The merged data to update.
         * @param fields The combined fields.
         */
        void appendTableData(const IronStruct::Table &current_table,
                             std::vector<std::vector<std::string>> &merged_table_data,
                             const std::vector<std::string> &fields)
        {
            for (const auto &row : current_table.values)
            {
                merged_table_data.push_back(createMappedRow(current_table, row, fields));
            }
        }
    } // namespace Detail

    /**
     * @brief Links and shows table data, merging fields and rows from multiple tables.
     * return detail: tuple<merged_table_data, field_names>
     * @param database_name Name of the database.
     * @param table_names Names of tables to link and show.
     * @return Tuple containing merged table data and field names.
     */
    auto Gets::linkShowTable(const std::string &database_name, const std::vector<std::string> &table_names)
        -> std::tuple<std::vector<std::vector<std::string>>, std::vector<std::string>>
    {
        // 检查数据库是否存在
        if (database_name.empty() ||
            _IronInnerProces_::_Level::_Database::_inspectEmptyDatabases() ||
            !_IronInnerProces_::_Level::_Database::_inspectExistDatabase(database_name))
        {
            ios::err64(kwl::error() + "database not exist: '" + database_name + "'");
            return {};
        }

        // 检查表参数合法性
        if (table_names.size() < 2)
        {
            ios::err64(kwl::error() + "at least 2 tables are required");
            return {};
        }

        // 检查表是否存在
        for (const auto &table_name : table_names)
        {
            if (_IronInnerProces_::_Level::_Table::_inspectEmptyTables(database_name) ||
                !_IronInnerProces_::_Level::_Table::_inspectExistTable(database_name, table_name))
            {
                ios::err64(kwl::error() + "table not exist: '" + table_name + "'");
                return {};
            }
        }

        _IronInnerProces_::_Level::_Link::fields_column_max.clear();
        _IronInnerProces_::_Level::_Link::datas_column_max.clear();

        // 去重, 合并表字段
        std::vector<std::string> _fields{_IronInnerProces_::_Level::_Field::_obtainFieldNames(database_name, table_names[0])};
        for (size_t i{1}; i < table_names.size(); ++i)
        {
            std::vector<std::string> result;
            std::unordered_set<std::string> seen;

            for (const auto &elem : _fields)
            {
                if (seen.insert(elem).second)
                {
                    result.push_back(elem);
                }
            }

            for (const auto &elem : _IronInnerProces_::_Level::_Field::_obtainFieldNames(database_name, table_names[i]))
            {
                if (seen.insert(elem).second)
                {
                    result.push_back(elem);
                }
            }

            _fields = result;
        }

        // 初始化字段宽度向量 - update: 2026-03-19
        _IronInnerProces_::_Level::_Link::fields_column_max.resize(_fields.size(), 0);
        for (size_t i = 0; i < _fields.size(); ++i)
        {
            _IronInnerProces_::_Level::_Link::fields_column_max[i] = _fields[i].size();
        }

        // 初始化数据宽度向量 - update: 2026-03-19
        _IronInnerProces_::_Level::_Link::datas_column_max.resize(_fields.size(), 0);

        auto database_index{_IronInnerProces_::_Level::_Database::_obtainDatabaseIndex(database_name)};
        std::vector<std::vector<std::string>> merged_table_data;

        // 首先获取第一个表的数据作为基础
        if (!table_names.empty())
        {
            auto first_table_index{_IronInnerProces_::_Level::_Table::_obtainTableIndex(database_name, table_names[0])};
            const auto &first_table = IronObject::Interface::databases[database_index].tables[first_table_index];

            // 构建第一个表的数据
            for (const auto &row : first_table.values)
            {
                merged_table_data.push_back(Detail::createMappedRow(first_table, row, _fields));
            }

            // 处理剩余的表
            for (size_t i{1}; i < table_names.size(); ++i)
            {
                auto current_table_index{_IronInnerProces_::_Level::_Table::_obtainTableIndex(database_name, table_names[i])};
                const auto &current_table = IronObject::Interface::databases[database_index].tables[current_table_index];

                // 查找公共字段
                std::vector<std::string> common_fields = Detail::findCommonFields(current_table, _fields);

                if (!common_fields.empty())
                {
                    // 有公共字段，使用连接方式
                    Detail::mergeWithJoin(current_table, merged_table_data, _fields, common_fields);
                }
                else
                {
                    // 无公共字段，简单追加
                    Detail::appendTableData(current_table, merged_table_data, _fields);
                }
            }
        }

        for (auto &row : merged_table_data)
        {
            if (row.empty())
            {
                continue;
            }
            // 计算每个字段的最大宽度 - update: 2026-03-19
            for (size_t i = 0; i < row.size() && i < _IronInnerProces_::_Level::_Link::datas_column_max.size(); ++i)
            {
                int current_width = row[i].size();
                if (current_width > _IronInnerProces_::_Level::_Link::datas_column_max[i])
                {
                    _IronInnerProces_::_Level::_Link::datas_column_max[i] = current_width;
                }
            }
        }

        return std::make_tuple(merged_table_data, _fields);
    }

    /**
     * @brief Obtains the maximum column widths for data.
     *
     * @return A vector of integers representing the maximum column widths for data.
     */
    auto Gets::linkShowTableMaximumWidthPerColumnData() -> std::vector<int>
    {
        return _IronInnerProces_::_Level::_Link::getTarIntArray(_IronInnerProces_::_Level::_Link::datas_column_max);
    }

    /**
     * @brief Obtains the maximum column widths for fields.
     *
     * @return A vector of integers representing the maximum column widths for fields.
     */
    auto Gets::linkShowTableMaximumWidthPerColumnField() -> std::vector<int>
    {
        return _IronInnerProces_::_Level::_Link::getTarIntArray(_IronInnerProces_::_Level::_Link::fields_column_max);
    }
} // namespace IronProces