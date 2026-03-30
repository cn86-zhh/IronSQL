#include "iron_verify_att0.hpp"
#include <unordered_map>

/**********************************************************************************
 * @brief Attribute type map.                                                     *
 *                                                                                *
 * @note Attribute type is used to determine the visibility of the attribute.     *
 **********************************************************************************/
static const std::unordered_map<std::string, IronAttribute::AttributeType> attribute_type_map{
    {"public", IronAttribute::AttributeType::PUBLIC},       /* attribute: public */
    {"private", IronAttribute::AttributeType::PRIVATE},     /* attribute: private */
    {"protected", IronAttribute::AttributeType::PROTECTED}, /* attribute: protected */
};

/**************************************************************************************
 * @brief Attribute permission map.                                                   *
 *                                                                                    *
 * @note Attribute permission is used to determine the access level of the attribute. *
 **************************************************************************************/
static const std::unordered_map<std::string, IronAttribute::AttributePermission> permission_map{
    {"r", IronAttribute::AttributePermission::R}, /* permission: read */
    {"w", IronAttribute::AttributePermission::W}, /* permission: write */
    {"x", IronAttribute::AttributePermission::X}, /* permission: execute */
    {"l", IronAttribute::AttributePermission::L}, /* permission: link */
};

/**************************************************************************************
 * @brief Attribute type string map.                                                  *
 *                                                                                    *
 * @note Attribute type string map is used to convert attribute type to string.       *
 **************************************************************************************/
static const std::unordered_map<IronAttribute::AttributeType, std::string> attribute_type_str_map{
    {IronAttribute::AttributeType::PUBLIC, "public"},       /* attribute: public */
    {IronAttribute::AttributeType::PRIVATE, "private"},     /* attribute: private */
    {IronAttribute::AttributeType::PROTECTED, "protected"}, /* attribute: protected */
};

/**************************************************************************************
 * @brief Allow read permission.                                                      *
 * default: true                                                                      *
 *                                                                                    *
 * @note Allow read permission is used to determine if the attribute can be read.     *
 * @param permission The attribute permission to check.                               *
 * @return bool True if the attribute can be read, false otherwise.                   *
 **************************************************************************************/
auto IronVerifyAtt0::InspectorAtt0::allow_permission_r(const std::string &permission) -> bool
{
    if (permission.empty())
    {
        return true; /* default allow read permission */
    }

    return permission_map.find(permission) != permission_map.end();
}

/**************************************************************************************
 * @brief Allow write permission.                                                     *
 * default: true                                                                      *
 *                                                                                    *
 * @note Allow write permission is used to determine if the attribute can be written. *
 * @param permission The attribute permission to check.                               *
 * @return bool True if the attribute can be written, false otherwise.                *
 **************************************************************************************/
auto IronVerifyAtt0::InspectorAtt0::allow_permission_w(const std::string &permission) -> bool
{
    if (permission.empty())
    {
        return true; /* default allow write permission */
    }

    return permission_map.find(permission) != permission_map.end();
}

/*****************************************************************************************
 * @brief Allow execute permission.                                                      *
 * default: true                                                                         *
 *                                                                                       *
 * @note Allow execute permission is used to determine if the attribute can be executed. *
 * @param permission The attribute permission to check.                                  *
 * @return bool True if the attribute can be executed, false otherwise.                  *
 *****************************************************************************************/
auto IronVerifyAtt0::InspectorAtt0::allow_permission_x(const std::string &permission) -> bool
{
    if (permission.empty())
    {
        return true; /* default allow execute permission */
    }

    return permission_map.find(permission) != permission_map.end();
}

/**************************************************************************************
 * @brief Allow link permission.                                                      *
 * default: false                                                                     *
 * not allowed use link permission.                                                   *
 *                                                                                    *
 * @note Allow link permission is used to determine if the attribute can be linked.   *
 * @param permission The attribute permission to check.                               *
 * @return bool True if the attribute can be linked, false otherwise.                 *
 **************************************************************************************/
auto IronVerifyAtt0::InspectorAtt0::allow_permission_l(const std::string &permission) -> bool
{
    if (permission.empty())
    {
        return false; /* default allow link permission */
    }

    return permission_map.find(permission) != permission_map.end();
}

/*****************************************************************************************
 * @brief Allow virtual read permission.                                                 *
 * default: public
 *                                                                                       *
 * @note Allow virtual read permission is used to determine if the attribute can be read.*
 * @param attribute_ The attribute permission to check.                                  *
 * @return std::string The virtual read permission.                                      *
 *****************************************************************************************/
auto IronVerifyAtt0::InspectorAtt0::allow_attribute_vr(const std::string &attribute_) -> std::string
{
    if (attribute_.empty())
    {
        return "public"; /* default allow virtual read permission */
    }

    if (attribute_type_map.find(attribute_) != attribute_type_map.end())
    {
        return attribute_type_str_map.at(attribute_type_map.at(attribute_));
    }
}
