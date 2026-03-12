#pragma once

#ifndef IRON_VERIFY_HPP
#define IRON_VERIFY_HPP

#include <unordered_map>
#include "iron_struct.hpp"

namespace IronVerify
{
    class Inspector
    {
    private:
        Inspector() = delete;
        ~Inspector() = delete;

    public:
        static auto stringToMaskType(const std::string &str) -> IronStruct::MaskType;
        static auto maskTypeToString(IronStruct::MaskType maskType) -> std::string;
        static auto stringToValue(const std::string &str) -> IronStruct::Value;
        static auto valueToString(IronStruct::Value val) -> std::string;
    }; // class Inspector
} // namespace IronVerify

#endif // IRON_VERIFY_HPP