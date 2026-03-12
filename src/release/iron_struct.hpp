#pragma once

#ifndef IRON_STRUCT_HPP
#define IRON_STRUCT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <variant>

namespace IronStruct
{
    enum class MaskType
    {
        MAXINT,
        BIGINT,
        INT,
        CHAR,
        STRING,
        DOUBLE,
        FLOAT,
        BOOL,
        ERRT // Mask type error
    };

    using Value = std::variant<long long, long, int, char, std::string, double, float, bool>;

    struct Field
    {
        std::string name;
        MaskType type;
    }; // struct Field

    struct Table
    {
        std::string name;
        std::vector<Field> fields;
        std::vector<std::vector<Value>> values;
    }; // struct Table

    struct Database
    {
        std::string name;
        std::vector<Table> tables;
    }; // struct Database

} // namespace IronStruct

#endif // IRON_STRUCT_HPP
