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
     * This function creates a new table in the specified database by merging the fields and
     * types of the source and destination tables.
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

        // merge table values for destination table
        for (const auto &row : dst_table.values)
        {
            std::vector<IronStruct::Value> new_row;
            for (size_t i = 0; i < new_fields.size(); ++i)
            {
                const std::string &field = new_fields[i];
                auto it = std::find(dst_fields.begin(), dst_fields.end(), field);
                if (it != dst_fields.end())
                {
                    size_t dst_index = std::distance(dst_fields.begin(), it);
                    if (dst_index < row.size())
                    {
                        new_row.push_back(row[dst_index]);

                        std::string value_str = IronVerify::Inspector::valueToString(row[dst_index]);
                        field_value_widths[i] = std::max(field_value_widths[i], IronHandle::Strings::getDisplayWidth(value_str));
                    }
                    else
                    {
                        // index out of bounds, add default value
                        new_row.push_back({});
                    }
                }
                else
                {
                    // field does not exist, add default value
                    new_row.push_back({});
                }
            }
            new_table_ref.values.push_back(new_row);
        }

        // merge table values for source table
        for (const auto &row : src_table.values)
        {
            std::vector<IronStruct::Value> new_row;
            for (size_t i = 0; i < new_fields.size(); ++i)
            {
                const std::string &field = new_fields[i];
                auto it = std::find(src_fields.begin(), src_fields.end(), field);
                if (it != src_fields.end())
                {
                    size_t src_index = std::distance(src_fields.begin(), it);
                    if (src_index < row.size())
                    {
                        new_row.push_back(row[src_index]);

                        std::string value_str = IronVerify::Inspector::valueToString(row[src_index]);
                        field_value_widths[i] = std::max(field_value_widths[i], IronHandle::Strings::getDisplayWidth(value_str));
                    }
                    else
                    {
                        // index out of bounds, add default value
                        new_row.push_back({});
                    }
                }
                else
                {
                    // field does not exist, add default value
                    new_row.push_back({});
                }
            }
            new_table_ref.values.push_back(new_row);
        }

        _IronInnerProces_::_Level::_Data::_recordDataRowWidthToMap(database_name, new_table_name, field_value_widths);
    }
} // namespace IronProces