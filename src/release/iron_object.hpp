#pragma once

#ifndef IRON_OBJECT_HPP
#define IRON_OBJECT_HPP

#include "iron_attribute.hpp"
#include <shared_mutex>
#include "iron_struct.hpp"

namespace IronObject
{
    class Interface
    {
    private:
        Interface() = delete;
        ~Interface() = delete;

    public:
        static std::shared_mutex mtx;
        static std::vector<IronStruct::Database> databases;
        static std::vector<IronAttribute::AttributeForDatabase> database_attributes;
        static std::vector<IronAttribute::AttributeForTable> table_attributes;
        static std::vector<IronAttribute::AttributeForField> field_attributes;
    }; // class Interface

} // namespace IronObject

#endif // IRON_OBJECT_HPP
