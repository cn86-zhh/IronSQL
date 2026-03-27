#pragma once

#ifndef IRON_LANGS_HPP
#define IRON_LANGS_HPP

#include <unordered_map>
#include <mutex>
#include <string>

namespace IronLangs
{

    class Language
    {
    private:
        Language() = delete;
        ~Language() = delete;
        static std::mutex lang_mutex_;

    public:
        static auto getLanguage(const std::string &lang) -> std::string;

    }; // class Language

} // namespace IronLangs

#endif // IRON_LANGS_HPP
