#pragma once

#ifndef IRON_PROCES_HPP
#define IRON_PROCES_HPP

#include <unordered_set>
#include <string>
#include <vector>
#include "iron_struct.hpp"
#include <map>
#include <algorithm>
#include <tuple>

namespace IronProces
{
    class Gets
    {
    private:
        Gets() = delete;
        ~Gets() = delete;

    public:
        static auto getDatabaseNames() -> std::vector<std::string>;
        static auto getDatabaseNameMaxWidth() -> int;

    public:
        static auto getTableNames(const std::string &database_name) -> std::vector<std::string>;
        static auto getTableNameMaxWidth(const std::string &database_name) -> int;

    public:
        static auto getFieldNames(const std::string &database_name, const std::string &table_name) -> std::vector<std::string>;
        static auto getFieldTypes(const std::string &database_name, const std::string &table_name) -> std::vector<std::string>;
        static auto getFieldNameMaxWidth(const std::string &database_name, const std::string &table_name) -> int;
        static auto getFieldTypeMaxWidth(const std::string &database_name, const std::string &table_name) -> int;

    public:
        static auto getTableDatas(const std::string &database_name, const std::string &table_name)
            -> std::vector<std::vector<std::string>>;
        static auto getDataRowWidth(const std::string &database_name, const std::string &table_name)
            -> std::vector<int>;

    public:
        static auto getTargetQueryArray(const std::string &database_name, const std::string &table_name,
                                        const std::vector<std::string> &field_names, bool &ref_bool)
            -> std::vector<std::vector<std::string>>;
        static auto linkShowTable(const std::string &database_name, const std::vector<std::string> &table_names)
            -> std::tuple<std::vector<std::vector<std::string>>, std::vector<std::string>>;

    }; // class Gets

    class Core
    {
    private:
        Core() = delete;
        ~Core() = delete;

    public:
        static void createDatabase(const std::string &database_name);
        static void useDatabase(const std::string &database_name);
        static void createTable(const std::string &table_name, const std::vector<std::string> &field_names,
                                const std::vector<std::string> &field_types);
        static void insertData(const std::string &table_name, const std::vector<std::string> &field_names,
                               const std::vector<std::string> &field_values);
        static void dropDatabase(const std::string &database_name);
        static void dropTable(const std::string &database_name, const std::string &table_name);
        static void linkTable(const std::string &database_name, const std::string &table_src_name,
                              const std::string &table_dst_name, const std::string &new_table_name);

    private:
        static void mergeTablesSimpleAppend(const IronStruct::Table &src_table,
                                            const IronStruct::Table &dst_table,
                                            IronStruct::Table &new_table,
                                            const std::vector<std::string> &new_fields,
                                            const std::vector<std::string> &src_fields,
                                            const std::vector<std::string> &dst_fields,
                                            std::vector<int> &field_value_widths);
        static void mergeTablesWithJoin(const IronStruct::Table &src_table,
                                        const IronStruct::Table &dst_table,
                                        IronStruct::Table &new_table,
                                        const std::vector<std::string> &new_fields,
                                        const std::vector<std::string> &src_fields,
                                        const std::vector<std::string> &dst_fields,
                                        const std::vector<std::string> &common_fields,
                                        std::vector<int> &field_value_widths);
        static std::vector<IronStruct::Value> createMergedRow(const std::vector<IronStruct::Value> &source_row,
                                                              const std::vector<std::string> &new_fields,
                                                              const std::vector<std::string> &source_fields);
        static void mergeRowData(std::vector<IronStruct::Value> &new_row,
                                 const std::vector<IronStruct::Value> &dst_row,
                                 const std::vector<std::string> &new_fields,
                                 const std::vector<std::string> &src_fields,
                                 const std::vector<std::string> &dst_fields);
        static void updateFieldWidths(const std::vector<IronStruct::Value> &row,
                                      std::vector<int> &field_value_widths);
    }; // class Core
} // namespace IronProces

#endif // IRON_PROCES_HPP
