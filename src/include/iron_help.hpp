#pragma once

#ifndef IRON_HELP_HPP
#define IRON_HELP_HPP

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <mutex>

namespace IronHelp
{
    class ShowHelpInformation
    {
    private:
        ShowHelpInformation() = delete;
        ~ShowHelpInformation() = delete;
        static std::mutex hmtx;

    public:
        static void setHighlight(const bool &enable_highlight);
        static void showWelcomeMessage(const std::string &lang, const bool &enable_highlight = false);
        static void showIronSQLSyntaxInformationDetails(const std::string &lang, const bool &enable_highlight = false);
    }; // class ShowHelpInformation
} // namespace IronHelp

#endif // IRON_HELP_HPP