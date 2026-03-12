#include "iron_keywds.hpp"

namespace IronKeywds
{
    /***********************************************************
     * zone brief:                                             *
     *                                                         *
     * from:                                                   *
     * namespace->IronKeywds                                   *
     * class    -> Kw                                          *
     **********************************************************/

    const std::string Kw::NONE{"none"};
    const int Kw::ZERO{0};

    const bool Kw::ENABLE{true};
    const std::string Kw::DOT{"."};
    const std::string Kw::TO{"to"};

    const std::string Kw::MINT{"maxint"};
    const std::string Kw::BINT{"bigint"};
    const std::string Kw::INT{"int"};
    const std::string Kw::CHAR{"char"};
    const std::string Kw::STRING{"string"};
    const std::string Kw::DOUBLE{"double"};
    const std::string Kw::FLOAT{"float"};
    const std::string Kw::BOOL{"bool"};
    const std::string Kw::ERRT{"errt"};

    /***********************************************************
     * zone brief:                                             *
     *                                                         *
     * from:                                                   *
     * namespace->IronKeywds                                   *
     * class    -> Level                                       *
     **********************************************************/

    const std::string Level::ERR{"error: "};
    const std::string Level::WARN{"warning: "};
    const std::string Level::INFO{"info: "};
    const std::string Level::FATAL{"fatal: "};
    const std::string Level::DONE{"done: "};

    /****************************************************************
     * @brief Returns the "none" keyword.                           *
     *                                                              *
     * This function returns the string "none", used to indicate no *
     * value or uninitialized state.                                *
     *                                                              *
     * @return The "none" keyword.                                  *
     ***************************************************************/
    const std::string Kw::none_() { return NONE; }

    /*************************************************
     * @brief Returns the zero value.                *
     *                                               *
     * This function returns the integer value 0.    *
     *                                               *
     * @return The zero value.                       *
     ************************************************/
    const int Kw::zero_() { return ZERO; }

    /*************************************************
     * @brief Returns the "maxint" keyword.          *
     *                                               *
     * This function returns the string "maxint",    *
     * used to represent the maxint data type.       *
     *                                               *
     * @return The "maxint" keyword.                 *
     ************************************************/
    const std::string Kw::maxInt_() { return MINT; }

    /*************************************************
     * @brief Returns the "bigint" keyword.          *
     *                                               *
     * This function returns the string "bigint",    *
     * used to represent the bigint data type.       *
     *                                               *
     * @return The "bigint" keyword.                 *
     ************************************************/
    const std::string Kw::bigInt_() { return BINT; }

    /*************************************************
     * @brief Returns the "int" keyword.             *
     *                                               *
     * This function returns the string "int",       *
     * used to represent the int data type.          *
     *                                               *
     * @return The "int" keyword.                    *
     ************************************************/
    const std::string Kw::int_() { return INT; }

    /*************************************************
     * @brief Returns the "char" keyword.            *
     *                                               *
     * This function returns the string "char",      *
     * used to represent the char data type.         *
     *                                               *
     * @return The "char" keyword.                   *
     ************************************************/
    const std::string Kw::char_() { return CHAR; }

    /*************************************************
     * @brief Returns the "string" keyword.          *
     *                                               *
     * This function returns the string "string",    *
     * used to represent the string data type.       *
     *                                               *
     * @return The "string" keyword.                 *
     ************************************************/
    const std::string Kw::string_() { return STRING; }

    /*************************************************
     * @brief Returns the "double" keyword.          *
     *                                               *
     * This function returns the string "double",    *
     * used to represent the double data type.       *
     *                                               *
     * @return The "double" keyword.                 *
     ************************************************/
    const std::string Kw::double_() { return DOUBLE; }

    /*************************************************
     * @brief Returns the "float" keyword.           *
     *                                               *
     * This function returns the string "float",     *
     * used to represent the float data type.        *
     *                                               *
     * @return The "float" keyword.                  *
     ************************************************/
    const std::string Kw::float_() { return FLOAT; }

    /*************************************************
     * @brief Returns the "bool" keyword.            *
     *                                               *
     * This function returns the string "bool",      *
     * used to represent the bool data type.         *
     *                                               *
     * @return The "bool" keyword.                   *
     ************************************************/
    const std::string Kw::bool_() { return BOOL; }

    /*************************************************
     * @brief Returns the "errt" keyword.            *
     *                                               *
     * This function returns the string "errt",      *
     * used to indicate an error type.               *
     *                                               *
     * @return The "errt" keyword.                   *
     ************************************************/
    const std::string Kw::errt_() { return ERRT; }

    /*************************************************
     * @brief Returns the enable flag.               *
     *                                               *
     * This function returns the boolean value true, *
     * used to enable features or options.           *
     *                                               *
     * @return The enable flag (true).               *
     ************************************************/
    const bool Kw::enable_() { return ENABLE; }

    /*************************************************
     * @brief Returns the dot keyword.               *
     *                                               *
     * This function returns the string ".",         *
     * used to represent a dot in a table name.      *
     *                                               *
     * @return The dot keyword.                      *
     ************************************************/
    const std::string Kw::dot_() { return DOT; }

    /*************************************************
     * @brief Returns the "to" keyword.              *
     *                                               *
     * This function returns the string "to",        *
     * used to represent the "to" clause in a query. *
     *                                               *
     * @return The "to" keyword.                     *
     ************************************************/
    const std::string Kw::to_() { return TO; }

    /*********************************************************************************************/

    /*************************************************
     * @brief Returns the "error" keyword.           *
     *                                               *
     * This function returns the string "error",     *
     * used to indicate an error message.            *
     *                                               *
     * @return The "error" keyword.                  *
     ************************************************/
    const std::string Level::error() { return ERR; }

    /*************************************************
     * @brief Returns the "done" keyword.            *
     *                                               *
     * This function returns the string "done",      *
     * used to indicate the completion of a task.    *
     *                                               *
     * @return The "done" keyword.                   *
     ************************************************/
    const std::string Level::done() { return DONE; }

    /*************************************************
     * @brief Returns the "info" keyword.            *
     *                                               *
     * This function returns the string "info",      *
     * used to indicate information-level messages.  *
     *                                               *
     * @return The "info" keyword.                   *
     ************************************************/
    const std::string Level::info() { return INFO; }

    /*************************************************
     * @brief Returns the "warn" keyword.            *
     *                                               *
     * This function returns the string "warn",      *
     * used to indicate warning-level messages.      *
     *                                               *
     * @return The "warn" keyword.                   *
     ************************************************/
    const std::string Level::warn() { return WARN; }

    /*************************************************
     * @brief Returns the "fatal" keyword.           *
     *                                               *
     * This function returns the string "fatal",     *
     * used to indicate fatal-level messages.        *
     *                                               *
     * @return The "fatal" keyword.                  *
     ************************************************/
    const std::string Level::fatal() { return FATAL; }
} // namespace IronKeywds