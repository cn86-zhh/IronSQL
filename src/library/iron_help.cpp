#include "iron_path_manage.hpp"
#include "iron_help.hpp"
#include <random>
#include <vector>

namespace IronHelpColor
{
    static const std::string R{"\033[31m"};
    static const std::string G{"\033[32m"};
    static const std::string Y{"\033[33m"};
    static const std::string B{"\033[34m"};
    static const std::string M{"\033[35m"};
    static const std::string C{"\033[36m"};
    static const std::string W{"\033[37m"};
    static const std::string E{"\033[0m"};

    class Ht
    {
    private:
        Ht() = delete;
        ~Ht() = delete;

    public:
        static void _printHighlightString(const std::string &color, const std::string &msg);
    }; // class Ht

    /**
     * @brief Prints a highlighted string with the specified color.
     *
     * This function prints a message with the specified color code for highlighting.
     *
     * @param color The color code to use for highlighting.
     * @param msg The message to print.
     */
    void Ht::_printHighlightString(const std::string &color, const std::string &msg)
    {
        std::cout << color << msg << E << std::endl;
    }
}

namespace IronHelp
{
    namespace Color = IronHelpColor;
    static bool enableHelpHighlight{false};

    /**
     * @brief Sets the highlight status for help messages.
     *
     * This function sets the highlight status for help messages.
     *
     * @param enable_highlight Whether to enable color highlighting.
     */
    void ShowHelpInformation::setHighlight(const bool &enable_highlight)
    {
        enableHelpHighlight = enable_highlight;
    }

    static const std::vector<std::string> COLORS = {Color::R, Color::G, Color::Y, Color::B, Color::M, Color::C, Color::W};

    static std::string getRandomColor();
    static void showIronSQLHelpWelcome(const bool &enable_highlight);
    static void showHelpLevelForDatabase(const bool &enable_highlight);
    static void showHelpLevelForTable(const bool &enable_highlight);
    static void showHelpLevelForData(const bool &enable_highlight);

    /**
     * @brief Gets a random color from the COLORS vector.
     *
     * This function returns a randomly selected color code from the predefined COLORS vector.
     *
     * @return A random color code.
     */
    static std::string getRandomColor()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, COLORS.size() - 1);
        return COLORS[dis(gen)];
    }

    /**
     * @brief Displays the welcome message for IronSQL.
     *
     * This function prints the welcome message with version information, author details, and usage instructions.
     *
     * @param enable_highlight Whether to enable color highlighting.
     */
    void ShowHelpInformation::welcome(const bool &enable_highlight)
    {
        static const std::string LINE_01{"Welcome to IronSQL"};
        static const std::string LINE_02{"Version release: 0.0.1"};
        static const std::string LINE_03{"Author: gitee(ch86-zhh), github(cn86-zhh)"};
        static const std::string LINE_04{"License: MIT"};
        static const std::string LINE_05{"help -s    * get more help details use"};
        static const std::string LINE_06{"help -p    * show project progress"};
        static const std::string LINE_07{"quit       * exit IronSQL"};
        static const std::string LINE_08{"exit       * ............"};
        static const std::string LINE_09{"#, //, --  * comment line"};
        static const std::string LINE_10{"Official website: https://www.ironsql.org.com"};
        static const std::string LINE_11{"Github   project: https://github.com/cn86-zhh/IronSQL"};
        static const std::string LINE_12{"Gitee    project: https://gitee.com/ch86-zhh/IronSQL"};

        if (enable_highlight)
        {
            Color::Ht::_printHighlightString(getRandomColor(), LINE_01);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_02);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_03);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_04);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_05);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_06);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_07);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_08);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_09);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_10);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_11);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_12);
        }
        else
        {
            std::cout << LINE_01 << std::endl;
            std::cout << LINE_02 << std::endl;
            std::cout << LINE_03 << std::endl;
            std::cout << LINE_04 << std::endl;
            std::cout << LINE_05 << std::endl;
            std::cout << LINE_06 << std::endl;
            std::cout << LINE_07 << std::endl;
            std::cout << LINE_08 << std::endl;
            std::cout << LINE_09 << std::endl;
            std::cout << LINE_10 << std::endl;
            std::cout << LINE_11 << std::endl;
            std::cout << LINE_12 << std::endl;
        }
    }

    /**
     * @brief Displays the project progress for IronSQL.
     *
     * This function prints the current project progress, update date, and implemented SQL syntax.
     *
     * @param enable_highlight Whether to enable color highlighting.
     */
    void ShowHelpInformation::showProjectProgress(const bool &enable_highlight)
    {
        static const std::string LINE_01{"Welcome To IronSQL Project Progress Display"};
        static const std::string LINE_02{"Project progress: 26%"};
        static const std::string LINE_03{"Update Date: 2026-03-07"};
        static const std::string LINE_04{"Implement SQL syntax:"};
        static const std::string LINE_05{"Show (databases, tables, struct, datas)"};
        static const std::string LINE_06{"Insert Into (table_name) Values (value1, value2, ...)"};
        static const std::string LINE_07{"Select (*, fileds) from (table_name)"};
        static const std::string LINE_08{"Select (*, fileds) from (datababse_name.table_name)"};

        if (enable_highlight)
        {
            Color::Ht::_printHighlightString(getRandomColor(), LINE_01);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_02);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_03);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_04);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_05);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_06);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_07);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_08);
        }
        else
        {
            std::cout << LINE_01 << std::endl;
            std::cout << LINE_02 << std::endl;
            std::cout << LINE_03 << std::endl;
            std::cout << LINE_04 << std::endl;
            std::cout << LINE_05 << std::endl;
            std::cout << LINE_06 << std::endl;
            std::cout << LINE_07 << std::endl;
            std::cout << LINE_08 << std::endl;
        }
    }

    /**
     * @brief Displays SQL syntax information based on the specified level.
     *
     * This function shows help information for the specified level (database, table, or data).
     *
     * @param enable_highlight Whether to enable color highlighting.
     * @param level_show The level of help to display ("database", "table", "data", or default for all).
     */
    void ShowHelpInformation::showIronSQLSyntaxInformation(const bool &enable_highlight, const std::string &level_show)
    {
        if (level_show == "database")
        {
            showIronSQLHelpWelcome(enable_highlight);
            showHelpLevelForDatabase(enable_highlight);
        }
        else if (level_show == "table")
        {
            showIronSQLHelpWelcome(enable_highlight);
            showHelpLevelForTable(enable_highlight);
        }
        else if (level_show == "data")
        {
            showIronSQLHelpWelcome(enable_highlight);
            showHelpLevelForData(enable_highlight);
        }
        else
        {
            showIronSQLHelpWelcome(enable_highlight);
            showHelpLevelForDatabase(enable_highlight);
            showHelpLevelForTable(enable_highlight);
            showHelpLevelForData(enable_highlight);
        }
    }

    /**
     * @brief Displays the welcome message for IronSQL syntax help.
     *
     * This function prints the welcome message for the syntax help section.
     *
     * @param enable_highlight Whether to enable color highlighting.
     */
    static void showIronSQLHelpWelcome(const bool &enable_highlight)
    {
        static const std::string LINE_01{"WELCOME TO USE IRONSQL SYNTAX HELP:"};

        if (enable_highlight)
        {
            Color::Ht::_printHighlightString(Color::R, LINE_01);
        }
        else
        {
            std::cout << LINE_01 << std::endl;
        }
    }

    /**
     * @brief Displays help information for database-level commands.
     *
     * This function prints syntax examples for database-level commands like show, use, drop, and link.
     *
     * @param enable_highlight Whether to enable color highlighting.
     */
    static void showHelpLevelForDatabase(const bool &enable_highlight)
    {
        static const std::string LINE_02{"LEVEL FOR DATABASE:"};
        static const std::string LINE_03{"show databases;                                               - show all databases"};
        static const std::string LINE_04{"use <database_name>;                                          - using a database"};
        static const std::string LINE_05{"drop database <database_name>;                                - drop a database"};
        static const std::string LINE_06{"link database <database_name1> to <database_name2>;           - link a database"};

        if (enable_highlight)
        {
            Color::Ht::_printHighlightString(getRandomColor(), LINE_02);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_03);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_04);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_05);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_06);
        }
        else
        {
            std::cout << LINE_02 << std::endl;
            std::cout << LINE_03 << std::endl;
            std::cout << LINE_04 << std::endl;
            std::cout << LINE_05 << std::endl;
            std::cout << LINE_06 << std::endl;
        }
    }

    /**
     * @brief Displays help information for table-level commands.
     *
     * This function prints syntax examples for table-level commands like show, drop, and select.
     *
     * @param enable_highlight Whether to enable color highlighting.
     */
    static void showHelpLevelForTable(const bool &enable_highlight)
    {
        static const std::string LINE_01{"LEVEL FOR TABLE:"};
        static const std::string LINE_02{"show tables;                                                - show all tables"};
        static const std::string LINE_03{"show struct <table_name>;                                   - show table struct"};
        static const std::string LINE_04{"show datas <table_name>;                                    - show table datas"};
        static const std::string LINE_05{"drop table <table_name>;                                    - drop a table"};
        static const std::string LINE_06{"select (*, fileds) from (table_name);                       - show select datas"};
        static const std::string LINE_07{"select (*, fileds) from (database_name.table_name);         - show select datas"};

        if (enable_highlight == true)
        {
            Color::Ht::_printHighlightString(getRandomColor(), LINE_01);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_02);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_03);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_04);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_05);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_06);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_07);
        }
    }

    /**
     * @brief Displays help information for data-level commands.
     *
     * This function prints syntax examples for data-level commands like insert.
     *
     * @param enable_highlight Whether to enable color highlighting.
     */
    static void showHelpLevelForData(const bool &enable_highlight)
    {
        static const std::string LINE_01{"LEVEL FOR DATA:"};
        static const std::string LINE_02{"insert into (table_name) values (value1, value2, ...);      - insert data"};

        if (enable_highlight)
        {
            Color::Ht::_printHighlightString(getRandomColor(), LINE_01);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_02);
        }
        else
        {
            std::cout << LINE_01 << std::endl;
            std::cout << LINE_02 << std::endl;
        }
    }

    /**
     * @brief Displays the help guide for IronSQL.
     *
     * This function prints the help guide with instructions on how to access different levels of help.
     *
     * @param enable_highlight Whether to enable color highlighting.
     */
    void ShowHelpInformation::showHelpGuide(const bool &enable_highlight)
    {
        static const std::string LINE_01{"HELP GUIDE:"};
        static const std::string LINE_02{"help -database;             - show help for database"};
        static const std::string LINE_03{"help -table;                - show help for table"};
        static const std::string LINE_04{"help -data;                 - show help for data"};
        static const std::string LINE_05{"help -syntax --all;         - show help for all"};

        if (enable_highlight)
        {
            Color::Ht::_printHighlightString(getRandomColor(), LINE_01);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_02);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_03);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_04);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_05);
        }
        else
        {
            std::cout << LINE_01 << std::endl;
            std::cout << LINE_02 << std::endl;
            std::cout << LINE_03 << std::endl;
            std::cout << LINE_04 << std::endl;
            std::cout << LINE_05 << std::endl;
        }
    }

    /**
     * @brief Displays the IronSQL syntax information.
     *
     * This function prints the syntax examples for database, table, and data-level commands.
     *
     * @param enable_highlight Whether to enable color highlighting.
     */
    void ShowHelpInformation::showIronSQLSyntaxInformation(const bool &enable_highlight)
    {
        static const std::string SPACE_LINE{""};

        static const std::string LINE_01{"WELCOME TO USE IRONSQL SYNTAX INFORMATION:"};
        static const std::string LINE_02{"[ LEVEL FOR DATABASE ]:"};
        static const std::string LINE_03{"show databases;"};
        static const std::string LINE_04{"drop database <database_name>                                         - drop a database"};
        static const std::string LINE_05{"use <database_name>                                                   - use a database"};
        static const std::string LINE_06{"[ LEVEL FOR TABLE ]:"};
        static const std::string LINE_07{"show table <table_name>                                               - show all tables"};
        static const std::string LINE_08{"drop table <table_name>                                               - drop a table"};
        static const std::string LINE_09{"show struct <table_name>                                              - show table structure"};
        static const std::string LINE_X1{"show struct from <table_name>                                         - ......"};
        static const std::string LINE_X2{"show struct from <database.table_name>                                - ......"};
        static const std::string LINE_10{"[ LEVEL FOR DATA ]:"};
        static const std::string LINE_11{"select (*, fileds) from (database_name.table_name)                    - show select datas"};
        static const std::string LINE_12{"select (*, fileds) from (table_name)                                  - ......"};
        static const std::string LINE_13{"show datas"};
        static const std::string LINE_14{"[ LEVEL FOR LINK SENTENCES ]:"};
        static const std::string LINE_15{"link table from <table1> to <table2> new <new_table>"};
        static const std::string LINE_16{"link table from <database1.table1> to <database1.table2> new <new_table>"};
        static const std::string LINE_X3{"link show table from <database:table_name1, table_name2 ....>         - show link table"};
        static const std::string LINE_17{"[ LEVEL FOR INSERT DATA ]:"};
        static const std::string LINE_18{"insert into table_name (field1, field2, ...) values (value1, value2, ...); - insert data to table"};

        if (enable_highlight)
        {
            Color::Ht::_printHighlightString(getRandomColor(), LINE_01);
            std::cout << SPACE_LINE << std::endl;
            Color::Ht::_printHighlightString(getRandomColor(), LINE_02);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_03);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_04);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_05);
            std::cout << SPACE_LINE << std::endl;
            Color::Ht::_printHighlightString(getRandomColor(), LINE_06);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_07);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_08);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_09);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_X1);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_X2);
            std::cout << SPACE_LINE << std::endl;
            Color::Ht::_printHighlightString(getRandomColor(), LINE_10);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_11);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_12);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_13);
            std::cout << SPACE_LINE << std::endl;
            Color::Ht::_printHighlightString(getRandomColor(), LINE_14);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_15);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_16);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_X3);
            std::cout << SPACE_LINE << std::endl;
            Color::Ht::_printHighlightString(getRandomColor(), LINE_17);
            Color::Ht::_printHighlightString(getRandomColor(), LINE_18);
        }
        else
        {
            std::cout << LINE_01 << std::endl;
            std::cout << SPACE_LINE << std::endl;
            std::cout << LINE_02 << std::endl;
            std::cout << LINE_03 << std::endl;
            std::cout << LINE_04 << std::endl;
            std::cout << LINE_05 << std::endl;
            std::cout << SPACE_LINE << std::endl;
            std::cout << LINE_06 << std::endl;
            std::cout << LINE_07 << std::endl;
            std::cout << LINE_08 << std::endl;
            std::cout << LINE_09 << std::endl;
            std::cout << LINE_X1 << std::endl;
            std::cout << LINE_X2 << std::endl;
            std::cout << SPACE_LINE << std::endl;
            std::cout << LINE_10 << std::endl;
            std::cout << LINE_11 << std::endl;
            std::cout << LINE_12 << std::endl;
            std::cout << LINE_13 << std::endl;
            std::cout << SPACE_LINE << std::endl;
            std::cout << LINE_14 << std::endl;
            std::cout << LINE_15 << std::endl;
            std::cout << LINE_16 << std::endl;
            std::cout << LINE_X3 << std::endl;
            std::cout << SPACE_LINE << std::endl;
            std::cout << LINE_17 << std::endl;
            std::cout << LINE_18 << std::endl;
        }
    }

    void ShowHelpInformation::showIronSQLSyntaxInformationDetails(const std::string &lang, const bool &enable_highlight)
    {
        static const std::string ZH_CN = "zh_cn";
        std::filesystem::path sure_help_file;

        // default output is english
#if defined(_WIN32) || defined(_WIN64) // windows
        std::filesystem::path help_file{IronPathManage::Control::windowsSettingsConfigPath() / "Ironsql_syntax_help_en_US.txt"};
#else
        std::filesystem::path help_file{IronPathManage::Control::linuxSettingsConfigPath() / "Ironsql_syntax_help_en_US.txt"};
#endif

        if (lang == ZH_CN)
        {
#if defined(_WIN32) || defined(_WIN64) // windows
            std::filesystem::path help_file{IronPathManage::Control::windowsSettingsConfigPath() / "Ironsql_syntax_help_zh_CN.txt"};
            sure_help_file = help_file;
#else
            std::filesystem::path help_file{IronPathManage::Control::linuxSettingsConfigPath() / "Ironsql_syntax_help_zh_CN.txt"};
            sure_help_file = help_file;
#endif
        }
        else
        {
            sure_help_file = help_file;
        }

        if (!std::filesystem::exists(sure_help_file))
        {
            std::cerr << "Help file not found ! please go to the project official website to get the help file." << std::endl;
            return;
        }

        std::fstream file(sure_help_file.string(), std::ios::in | std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "Failed to open help file : " << sure_help_file.string() << std::endl;
            return;
        }

        // output help file content
        std::string line;

        // if true: out highlight help file content, else: out help file content as is
        if (enable_highlight || enableHelpHighlight)
        {
            while (std::getline(file, line))
            {
                Color::Ht::_printHighlightString(getRandomColor(), line);
            }
            file.close();
            return;
        }

        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }

} // namespace IronHelp