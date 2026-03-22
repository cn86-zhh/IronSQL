#pragma once

#ifndef IRON_HELP_HPP
#define IRON_HELP_HPP

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace IronHelp
{
    class ShowHelpInformation
    {
    private:
        ShowHelpInformation() = delete;
        ~ShowHelpInformation() = delete;

    public:
        static void setHighlight(const bool &enable_highlight);

        static void welcome(const bool &enable_highlight = false);
        static void showProjectProgress(const bool &enable_highlight = false);
        static void showIronSQLSyntaxInformation(const bool &enable_highlight, const std::string &level_show);
        static void showHelpGuide(const bool &enable_highlight = false);
        static void showIronSQLSyntaxInformation(const bool &enable_highlight = false);
        static void showIronSQLSyntaxInformationDetails(const std::string &lang, const bool &enable_highlight = false);
    }; // class ShowHelpInformation
} // namespace IronHelp

#endif // IRON_HELP_HPP