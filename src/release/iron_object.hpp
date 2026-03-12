#pragma once

#ifndef IRON_OBJECT_HPP
#define IRON_OBJECT_HPP

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
    }; // class Interface

} // namespace IronObject

#endif // IRON_OBJECT_HPP
