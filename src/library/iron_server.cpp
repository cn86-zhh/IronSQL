#include "iron_server.hpp"
#include "iron_proces.hpp"
#include "iron_handle.hpp"
#include "iron_fmtout.hpp"
#include "iron_status.hpp"
#include "iron_keywds.hpp"
#include "iron_parser.hpp"
#include "iron_help.hpp"
#include "iron_syntax.hpp"
#include "iron_logsystem.hpp"
#include "iron_stdio.hpp"

/***************************************************
 * zone brief:                                     *
 *                                                 *
 * ios: namespace -> IronStdOst                    *
 *      class     -> OutStream                     *
 *                                                 *
 * lgs: namespace -> IronLogSystem                 *
 *      class     -> LogOut                        *
 **************************************************/

using ios = IronStdOst::OutStream;
using lgs = IronLogSystem::LogOut;

namespace IronServer
{
    /******************************************************
     * zone brief:                                        *
     *                                                    *
     * Set alias references for namespace and class names *
     *****************************************************/

    using Synw = IronSyntax::Word;
    using keyw = IronKeywds::Level;

    static void settingsAdjust(const std::string &settings_sentence)
    {
        const static bool TRUE{true};
        const static bool FALSE{false};

        // using debug mode with highlight.
        if (settings_sentence == "set -enable --debug --highlight")
        {
            ios::prt64("using debug mode with highlight!");
            lgs::setDebugHighlight(TRUE);
        }

        // disable debug mode with highlight.
        if (settings_sentence == "set -disable --debug --highlight")
        {
            ios::prt64("disable debug mode with highlight!");
            lgs::setDebugHighlight(FALSE);
        }

        // using debug mode.
        if (settings_sentence == "set -enable --debug")
        {
            ios::prt64("using debug mode!");
            lgs::setDebug(TRUE);
        }

        // disable debug mode.
        if (settings_sentence == "set -disable --debug")
        {
            ios::prt64("disable debug mode!");
            lgs::setDebug(FALSE);
        }
    }

    /**
     * @brief Shows the structure of a target table.
     *
     * This function shows the structure of a target table specified in the query.
     * If the table name is not qualified with a database name, the current database is used.
     *
     * @param query The SQL select sentence to process.
     */
    static void
    showTableStruct(const std::string &query)
    {
        /***************************************************************************
         * expected processing sentence:                                           *
         * table_name                                                              *
         * database_name.table_name                                                *
         **************************************************************************/

        auto tmp_list{IronHandle::Strings::extractDatabaseAndTable(query)};

        if (tmp_list.empty())
        {
            ios::err64(keyw::error() + "invalid query sentence.");
            lgs::IRON_DEBUG("invalid query sentence.");
            return;
        }

        std::string database_name{IronStatus::Manage::getDatabaseName()}; // default using manager database object.
        std::string table_name{IronKeywds::Kw::none_()};                  // default using none table name.

        if (tmp_list.size() == 1)
        {
            table_name = tmp_list.at(0);
        }

        if (tmp_list.size() == 2)
        {
            database_name = tmp_list.at(0);
            ios::prt64("database_name:" + database_name);
            lgs::IRON_DEBUG("database_name:" + database_name);
            table_name = tmp_list.at(1);
        }

        IronFormatOut::Printer::printTableStruct(database_name, table_name);
    }

    /**
     * @brief Shows the datas of a target table.
     *
     * This function shows the datas of a target table specified in the query.
     * If the table name is not qualified with a database name, the current database is used.
     *
     * @param query The SQL select sentence to process.
     */
    static void showTargetTableDatas(const std::string &query)
    {
        /***************************************************************************
         * expected processing sentence:                                           *
         * table_name                                                              *
         * database_name.table_name                                                *
         **************************************************************************/

        auto tmp_list{IronHandle::Strings::extractDatabaseAndTable(query)};

        if (tmp_list.empty())
        {
            ios::err64(keyw::error() + "invalid query sentence.");
            lgs::IRON_DEBUG("invalid query sentence.");
            return;
        }

        std::string database_name{IronStatus::Manage::getDatabaseName()}; // default using manager database object.
        std::string table_name{IronKeywds::Kw::none_()};                  // default using none table name.

        if (tmp_list.size() == 1)
        {
            table_name = tmp_list.at(0);
        }

        if (tmp_list.size() == 2)
        {
            database_name = tmp_list.at(0);
            table_name = tmp_list.at(1);
        }

        IronFormatOut::Printer::printTableDatas(database_name, table_name);
    }

    /**
     * @brief Links a table from a database.
     * link syntax: link table from table1 to table2, link table database1.table1 to database1.table2
     * This function links a table from the specified database to the current database.
     *
     * @param query The SQL link table sentence to process.
     */
    static void linkTableDatas(const std::string &query)
    {
        std::string database_name{IronStatus::Manage::getDatabaseName()};
        static const std::string _NONE_{IronKeywds::Kw::none_()};

        /***************************************************************************
         * expected processing sentence:                                           *
         * link table from table1 to table2 new new_table_name                     *
         * link table from database1.table1 to database1.table2 new new_table_name *
         **************************************************************************/

        std::string table_src_name{_NONE_};
        std::string table_dst_name{_NONE_};
        std::string new_table_name{_NONE_};

        auto tokens = IronHandle::Strings::stringName(query);

        if (tokens.empty())
        {
            return;
        }

        if (tokens.size() == 4)
        {
            database_name = tokens.at(0);
            table_src_name = tokens.at(1);
            table_dst_name = tokens.at(2);
            new_table_name = tokens.at(3);
        }
        else if (tokens.size() == 3)
        {
            table_src_name = tokens.at(0);
            table_dst_name = tokens.at(1);
            new_table_name = tokens.at(2);
        }
        else
        {
            ios::err64(keyw::error() + "invalid link table sentence: '" + query + "'");
            lgs::IRON_DEBUG("invalid link table sentence: '" + query + "'");
            return;
        }

        IronHandle::Strings::strip(table_src_name);
        IronHandle::Strings::strip(table_dst_name);
        IronHandle::Strings::strip(new_table_name);

        IronProces::Core::linkTable(database_name, table_src_name, table_dst_name, new_table_name);
    }

    /**
     * @brief Shows the datas of multiple linked tables.
     *
     * This function shows the datas of multiple linked tables specified in the query.
     * If the table names are not qualified with a database name, the current database is used.
     *
     * @param query The SQL select sentence to process.
     */
    static void linkShowMultipleTableDatas(const std::string &query)
    {
        static const char delimiter{':'};
        auto deli_pos = query.find(delimiter);

        std::string database_name{IronStatus::Manage::getDatabaseName()};
        if (database_name == IronKeywds::Kw::none_() && deli_pos != std::string::npos)
        {
            database_name = query.substr(0, deli_pos);
            IronHandle::Strings::strip(database_name);
        }

        IronFormatOut::Printer::printMultipleTableData(database_name, IronHandle::Strings::getTableNames(query.substr(deli_pos + 1)));
    }

    /**
     * @brief Processes a SELECT SQL statement.
     *
     * This function handles SELECT statements, extracting field names, table name, and database name
     * (if specified in the format database.table), then prints the query results.
     *
     * @param query The SQL SELECT statement to process.
     */
    static void selectSentenceShowTargetTableDatas(const std::string &query)
    {
        /********************************************************
         * expected processing sentence:                        *
         *                                                      *
         * select field1,fieldN from table_name;                *
         * select field1,fieldN from database_name.table_name;  *
         *******************************************************/

        static const std::string key_dot{Synw::dot()};
        static const std::string key_select{Synw::select()};
        static const std::string key_from{Synw::from()};

        auto dot_pos = query.find(key_dot);
        auto select_pos = query.find(key_select);
        auto from_pos = query.find(key_from);

        if (select_pos == std::string::npos || from_pos == std::string::npos)
        {
            ios::err64(keyw::error() + "invalid select sentence");
            lgs::IRON_DEBUG("invalid select sentence");
            return;
        }

        std::vector<std::string> field_names;

        // Obtain database name(if exists)
        std::string database_name{IronStatus::Manage::getDatabaseName()};
        if (dot_pos != std::string::npos && dot_pos > from_pos)
        {
            database_name = query.substr(from_pos + key_from.size(), dot_pos - from_pos - key_from.size());
            IronHandle::Strings::strip(database_name);
        }

        // Detection database object name not is none.
        if (database_name == IronKeywds::Kw::none_())
        {
            ios::err64(keyw::error() + "no database selected");
            lgs::IRON_DEBUG("no database selected");
            return;
        }

        // Obtain table name
        std::string table_name;
        if (dot_pos != std::string::npos && dot_pos > from_pos)
        {
            // format database.table
            table_name = query.substr(dot_pos + 1);
        }
        else
        {
            // handle just table name
            table_name = query.substr(from_pos + key_from.size());
        }
        IronHandle::Strings::strip(table_name);

        // Obtain field names(comma-separated) between select and from keywords
        std::string field_names_str{query.substr(select_pos + key_select.size(), from_pos - select_pos - key_select.size())};
        IronHandle::Strings::strip(field_names_str);

        for (auto &field_name : IronHandle::Strings::split(field_names_str, ","))
        {
            IronHandle::Strings::strip(field_name);
            field_names.push_back(field_name);
        }

        IronFormatOut::Printer::printTargetQuery(database_name, table_name, field_names);
    }

    /**
     * @brief Processes help commands for IronSQL.
     *
     * This function handles various help commands and displays the appropriate help information.
     *
     * @param help_cmd The help command to process.
     * @param enableHighlight Whether to enable syntax highlighting.
     * @default true
     * @param ref_result Reference to a boolean that will be set to false if the command is unrecognized.
     */
    static void ironSQLHelp(const std::string &help_cmd, bool &ref_result, const bool &enableHighlight)
    {
        if (help_cmd == "help -p")
        {
            IronHelp::ShowHelpInformation::showProjectProgress(enableHighlight);
        }

        else if (help_cmd == "help -s")
        {
            IronHelp::ShowHelpInformation::showHelpGuide(enableHighlight);
        }
        else if (help_cmd == "help -database")
        {
            IronHelp::ShowHelpInformation::showIronSQLSyntaxInformation(enableHighlight, "database");
        }
        else if (help_cmd == "help -table")
        {
            IronHelp::ShowHelpInformation::showIronSQLSyntaxInformation(enableHighlight, "table");
        }
        else if (help_cmd == "help -data")
        {
            IronHelp::ShowHelpInformation::showIronSQLSyntaxInformation(enableHighlight, "data");
        }
        else if (help_cmd == "help -syntax --all")
        {
            IronHelp::ShowHelpInformation::showIronSQLSyntaxInformation(enableHighlight);
        }
        else
        {
            ref_result = false;
        }
    }

    /**
     * @brief Processes an IronSQL query.
     *
     * This function is the main entry point for processing SQL queries. It handles various SQL commands
     * such as CREATE, SHOW, USE, INSERT, SELECT, DROP, and help commands.
     *
     * @param query The SQL query to process.
     */
    void Service::runIronSQL(const std::string &query, const bool &enableHighlight)
    {
        bool help_result = true;

        std::string lower_query = query;
        IronHandle::Strings::lower(lower_query);

        if (lower_query.substr(0, 15) == "create database")
        {
            std::string name{lower_query.substr(15)};
            IronHandle::Strings::strip(name);
            IronProces::Core::createDatabase(name);
        }

        else if (lower_query.substr(0, 15) == "show databases")
        {
            IronFormatOut::Printer::printDatabases();
        }

        else if (lower_query.substr(0, 3) == "use")
        {
            std::string name{lower_query.substr(3)};
            IronHandle::Strings::strip(name);
            IronProces::Core::useDatabase(name);
        }

        else if (lower_query.substr(0, 11) == "show tables")
        {
            if (IronStatus::Manage::getDatabaseName() == IronKeywds::Kw::none_())
            {
                ios::err64(keyw::error() + "no database selected");
                lgs::IRON_DEBUG(keyw::error() + "no database selected");
                return;
            }

            IronFormatOut::Printer::printTables(IronStatus::Manage::getDatabaseName());
        }

        else if (lower_query.substr(0, 11) == "show struct" && lower_query.substr(0, 16) != "show struct from")
        {
            if (IronStatus::Manage::getDatabaseName() == IronKeywds::Kw::none_())
            {
                ios::err64(keyw::error() + "no database selected");
                lgs::IRON_DEBUG("no database selected");
                return;
            }

            std::string table_name{lower_query.substr(11)};

            if (table_name.empty())
            {
                ios::err64(keyw::error() + "no table selected");
                lgs::IRON_DEBUG("no table selected");
                return;
            }

            IronHandle::Strings::strip(table_name);
            IronFormatOut::Printer::printTableStruct(IronStatus::Manage::getDatabaseName(), table_name);
        }

        else if (lower_query.substr(0, 16) == "show struct from")
        {
            std::string sub_strings{lower_query.substr(16)};
            IronHandle::Strings::strip(sub_strings);
            showTableStruct(sub_strings);
        }

        else if (lower_query.substr(0, 10) == "show datas")
        {
            std::string table_name{lower_query.substr(10)};
            IronHandle::Strings::strip(table_name);
            IronFormatOut::Printer::printTableDatas(IronStatus::Manage::getDatabaseName(), table_name);
        }

        else if (lower_query.substr(0, 13) == "select * from")
        {
            std::string table_name{lower_query.substr(13)};
            IronHandle::Strings::strip(table_name);
            showTargetTableDatas(table_name);
        }

        else if (lower_query.substr(0, 11) == "select*from")
        {
            std::string table_name{lower_query.substr(11)};
            IronHandle::Strings::strip(table_name);
            showTargetTableDatas(table_name);
        }

        else if (lower_query == "get current database")
        {
            std::string database_name{IronStatus::Manage::getDatabaseName()};

            if (database_name == IronKeywds::Kw::none_())
            {
                ios::err64(keyw::error() + "no database selected");
                lgs::IRON_DEBUG("no database selected");
                return;
            }

            std::cout << "current using database: ";
            std::cout << database_name << std::endl;
        }

        else if (lower_query == "get tables number")
        {
            std::string database_name{IronStatus::Manage::getDatabaseName()};

            if (database_name == IronKeywds::Kw::none_())
            {
                ios::err64(keyw::error() + "no database selected");
                lgs::IRON_DEBUG("no database selected");
                return;
            }

            std::cout << "tables number: ";
            std::cout << IronStatus::Manage::getTablesNumber() << std::endl;
        }

        else if (lower_query.substr(0, 12) == "create table")
        {
            static const std::string bracket_left{"("};
            auto bracket_pos = lower_query.find(bracket_left);

            if (bracket_pos == std::string::npos)
            {
                ios::err64(keyw::error() + "invalid create table syntax");
                lgs::IRON_DEBUG("invalid create table syntax");
                return;
            }

            std::string table_name = lower_query.substr(12, bracket_pos - 12);
            IronHandle::Strings::strip(table_name);

            if (table_name.empty())
            {
                ios::err64(keyw::error() + "table name is empty");
                lgs::IRON_DEBUG("table name is empty");
                return;
            }

            std::string field_defs = lower_query.substr(bracket_pos);
            IronHandle::Strings::strip(field_defs);

            IronProces::Core::createTable(
                table_name,
                IronParser::Resolver::resolveFieldNames(field_defs),
                IronParser::Resolver::resolveFieldTypes(field_defs));
        }

        else if (lower_query.substr(0, 11) == "insert into")
        {
            if (IronStatus::Manage::getDatabaseName() == IronKeywds::Kw::none_())
            {
                ios::err64(keyw::error() + "no database selected");
                lgs::IRON_DEBUG("no database selected");
                return;
            }

            std::string table_name = IronParser::Resolver::resolveInsertTableName(query);
            if (table_name.empty())
            {
                ios::err64(keyw::error() + "table name is empty");
                lgs::IRON_DEBUG("table name is empty");
                return;
            }

            std::vector<std::string> field_names = IronParser::Resolver::resolveInsertFieldNames(query);
            if (field_names.empty())
            {
                ios::err64(keyw::error() + "field names are empty");
                lgs::IRON_DEBUG("field names are empty");
                return;
            }

            std::vector<std::string> field_values = IronParser::Resolver::resolveInsertFieldValues(query);
            if (field_values.empty())
            {
                ios::err64(keyw::error() + "field values are empty");
                lgs::IRON_DEBUG("field values are empty");
                return;
            }

            if (field_names.size() != field_values.size())
            {
                ios::err64(keyw::error() + "field names and values count mismatch");
                lgs::IRON_DEBUG("field names and values count mismatch");
                return;
            }

            IronProces::Core::insertData(table_name, field_names, field_values);
        }

        else if (lower_query.substr(0, 6) == "select")
        {
            selectSentenceShowTargetTableDatas(lower_query);
        }

        else if (lower_query.substr(0, 4) == "help")
        {
            ironSQLHelp(lower_query, help_result, enableHighlight);
        }

        else if (lower_query.substr(0, 13) == "drop database")
        {
            std::string name{lower_query.substr(13)};
            IronHandle::Strings::strip(name);
            IronProces::Core::dropDatabase(name);
        }

        else if (lower_query.substr(0, 10) == "drop table")
        {
            std::string database_name{IronStatus::Manage::getDatabaseName()};
            if (database_name == IronKeywds::Kw::none_())
            {
                ios::err64(keyw::error() + "no database selected");
                lgs::IRON_DEBUG("no database selected");
                return;
            }

            std::string name{lower_query.substr(10)};
            IronHandle::Strings::strip(name);
            IronProces::Core::dropTable(database_name, name);
        }

        else if (lower_query.substr(0, 15) == "link table from")
        {
            if (lower_query.size() <= 15)
            {
                ios::err64(keyw::error() + "invalid link table sentence:'" + lower_query + "'");
                lgs::IRON_DEBUG("invalid link table sentence:'" + lower_query + "'");
                return;
            }

            std::string new_query{lower_query.substr(15)};
            IronHandle::Strings::strip(new_query);
            linkTableDatas(new_query);
        }

        else if (lower_query.substr(0, 20) == "link show table from")
        {
            std::string sub_string{lower_query.substr(20)};
            IronHandle::Strings::strip(sub_string);
            linkShowMultipleTableDatas(sub_string);
        }

        else if (lower_query.substr(0, 5) == "set -")
        {
            settingsAdjust(lower_query);
        }

        else
        {
            std::cerr << "error: unknown query sentence" << std::endl;
            std::cerr << ":.  .: '" << lower_query << "'" << std::endl;
        }

        if (!help_result)
        {
            std::cerr << "error: unknown help sentence" << std::endl;
            std::cerr << ":.  .: '" << lower_query << "'" << std::endl;
        }
    }
} // namespace IronServer