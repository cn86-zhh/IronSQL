#pragma once

#ifndef IRON_PARSER_HPP
#define IRON_PARSER_HPP

#include <algorithm>
#include <string>
#include <vector>

namespace IronParser
{
    class Resolver
    {
    private:
        Resolver() = delete;
        ~Resolver() = delete;

    public:
        static auto resolveFieldNames(const std::string &query) -> std::vector<std::string>;
        static auto resolveFieldTypes(const std::string &query) -> std::vector<std::string>;
        static auto resolveInsertTableName(const std::string &query) -> std::string;
        static auto resolveInsertFieldNames(const std::string &query) -> std::vector<std::string>;
        static auto resolveInsertFieldValues(const std::string &query) -> std::vector<std::string>;
    }; // class Resolver
} // namespace IronParser

#endif // IRON_PARSER_HPP