#include "iron_object.hpp"

namespace IronObject
{
    std::shared_mutex Interface::mtx;
    std::vector<IronStruct::Database> Interface::databases;

    /* IronSQL database attributes
     * inlcude:
     *      - database name
     *      - database type
     *      - database permission
     *      - database link
     */
    std::vector<IronAttribute::AttributeForDatabase> Interface::database_attributes;

    /* IronSQL table attributes
     * inlcude:
     *      - database name
     *      - table name
     *      - table type
     *      - table permission
     *      - table link
     */
    std::vector<IronAttribute::AttributeForTable> Interface::table_attributes;

    /* IronSQL field attributes
     * inlcude:
     *      - table name
     *      - field name
     *      - field type
     *      - field link
     *      - field null
     *      - field delete
     *      - field modify
     */
    std::vector<IronAttribute::AttributeForField> Interface::field_attributes;
} // namespace IronObject
