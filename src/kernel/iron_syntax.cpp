#include "iron_syntax.hpp"

namespace IronSyntax
{
    const std::string Word::SHOW{"show"};
    const std::string Word::SPACE{" "};
    const std::string Word::DATABASES{"databases"};
    const std::string Word::DATABASE{"database"};
    const std::string Word::USE{"use"};
    const std::string Word::SELECT{"select"};
    const std::string Word::FROM{"from"};
    const std::string Word::INSERT{"insert"};
    const std::string Word::INTO{"into"};
    const std::string Word::VALUES{"values"};
    const std::string Word::DATAS{"datas"};
    const std::string Word::STRUCT{"struct"};
    const std::string Word::DOT{"."};
    const std::string Word::CREATE{"create"};
    const std::string Word::TABLES{"tables"};
    const std::string Word::STAR{"*"};
    const std::string Word::TABLE{"table"};
    const std::string Word::HELP{"help"};

    /**
     * @brief Returns the "show" keyword.
     * 
     * @return The "show" keyword as a constant reference to std::string.
     */
    const std::string &Word::show()
    {
        return SHOW;
    }

    /**
     * @brief Returns the space character.
     * 
     * @return The space character as a constant reference to std::string.
     */
    const std::string &Word::space()
    {
        return SPACE;
    }

    /**
     * @brief Returns the "databases" keyword.
     * 
     * @return The "databases" keyword as a constant reference to std::string.
     */
    const std::string &Word::databases()
    {
        return DATABASES;
    }

    /**
     * @brief Returns the "database" keyword.
     * 
     * @return The "database" keyword as a constant reference to std::string.
     */
    const std::string &Word::database()
    {
        return DATABASE;
    }

    /**
     * @brief Returns the "use" keyword.
     * 
     * @return The "use" keyword as a constant reference to std::string.
     */
    const std::string &Word::use()
    {
        return USE;
    }

    /**
     * @brief Returns the "select" keyword.
     * 
     * @return The "select" keyword as a constant reference to std::string.
     */
    const std::string &Word::select()
    {
        return SELECT;
    }

    /**
     * @brief Returns the "from" keyword.
     * 
     * @return The "from" keyword as a constant reference to std::string.
     */
    const std::string &Word::from()
    {
        return FROM;
    }

    /**
     * @brief Returns the "insert" keyword.
     * 
     * @return The "insert" keyword as a constant reference to std::string.
     */
    const std::string &Word::insert()
    {
        return INSERT;
    }

    /**
     * @brief Returns the "into" keyword.
     * 
     * @return The "into" keyword as a constant reference to std::string.
     */
    const std::string &Word::into()
    {
        return INTO;
    }

    /**
     * @brief Returns the "values" keyword.
     * 
     * @return The "values" keyword as a constant reference to std::string.
     */
    const std::string &Word::values()
    {
        return VALUES;
    }

    /**
     * @brief Returns the "datas" keyword.
     * 
     * @return The "datas" keyword as a constant reference to std::string.
     */
    const std::string &Word::datas()
    {
        return DATAS;
    }

    /**
     * @brief Returns the "struct" keyword.
     * 
     * @return The "struct" keyword as a constant reference to std::string.
     */
    const std::string &Word::struct_()
    {
        return STRUCT;
    }

    /**
     * @brief Returns the dot (".") character.
     * 
     * @return The dot character as a constant reference to std::string.
     */
    const std::string &Word::dot()
    {
        return DOT;
    }

    /**
     * @brief Returns the "create" keyword.
     * 
     * @return The "create" keyword as a constant reference to std::string.
     */
    const std::string &Word::create()
    {
        return CREATE;
    }

    /**
     * @brief Returns the "tables" keyword.
     * 
     * @return The "tables" keyword as a constant reference to std::string.
     */
    const std::string &Word::tables()
    {
        return TABLES;
    }

    /**
     * @brief Returns the star ("*") character.
     * 
     * @return The star character as a constant reference to std::string.
     */
    const std::string &Word::star()
    {
        return STAR;
    }

    /**
     * @brief Returns the "table" keyword.
     * 
     * @return The "table" keyword as a constant reference to std::string.
     */
    const std::string &Word::table()
    {
        return TABLE;
    }

    /**
     * @brief Returns the "help" keyword.
     * 
     * @return The "help" keyword as a constant reference to std::string.
     */
    const std::string &Word::help()
    {
        return HELP;
    }
}
