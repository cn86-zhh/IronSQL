#pragma once

#ifndef IRON_ATTRIBUTE_HPP
#define IRON_ATTRIBUTE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <shared_mutex>

namespace IronAttribute
{
    /*IronSQL attribute type*/
    enum class AttributeType
    {
        PUBLIC,    // default attribute type
        PRIVATE,   // private attribute type
        PROTECTED, // protected attribute type
        PROHIBIT,  // prohibit attribute type
        ERRT       // Attribute type error
    }; // AttributeType

    /*IronSQL attribute permission*/
    enum class AttributePermission
    {
        R,   // read permission
        W,   // write permission
        X,   // execute permission
        L,   // link permission
        ERRT // Attribute permission error
    }; // AttributePermission

    struct AttributeForField
    {
        std::string table_name; // table name
        std::string field_name; // field name
        std::string field_type; // field type
        bool allow_link;        // allow link permission, default is false
        bool allow_null;        // allow null permission, default is true
        bool allow_delete;      // allow delete permission, default is true
        bool allow_modify;      // allow modify permission, default is true
    }; // struct AttributeForField

    struct AttributeForTable
    {
        std::string database_name;    // database name
        std::string table_name;       // table name
        std::string table_type;       // table type
        std::string table_permission; // table permission
        bool allow_link;              // allow link permission, default is false
    }; // struct AttributeForTable

    struct AttributeForDatabase
    {
        std::string database_name;       // database name
        std::string database_type;       // database type
        std::string database_permission; // database permission
        bool allow_link;                 // allow link permission, default is false
    }; // struct AttributeForDatabase
} // namespace IronAttribute

#endif // IRON_ATTRIBUTE_HPP