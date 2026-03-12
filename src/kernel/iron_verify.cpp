#include "iron_verify.hpp"
#include "iron_keywds.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <type_traits>
#include <limits>
#include <variant>
#include <algorithm>

namespace IronVerify
{
    std::unordered_map<std::string, IronStruct::MaskType> mask_type_map = {
        {IronKeywds::Kw::maxInt_(), IronStruct::MaskType::MAXINT},
        {IronKeywds::Kw::bigInt_(), IronStruct::MaskType::BIGINT},
        {IronKeywds::Kw::int_(), IronStruct::MaskType::INT},
        {IronKeywds::Kw::char_(), IronStruct::MaskType::CHAR},
        {IronKeywds::Kw::string_(), IronStruct::MaskType::STRING},
        {IronKeywds::Kw::double_(), IronStruct::MaskType::DOUBLE},
        {IronKeywds::Kw::float_(), IronStruct::MaskType::FLOAT},
        {IronKeywds::Kw::bool_(), IronStruct::MaskType::BOOL}};

    std::unordered_map<IronStruct::MaskType, std::string> mask_type_str_map = {
        {IronStruct::MaskType::MAXINT, IronKeywds::Kw::maxInt_()},
        {IronStruct::MaskType::BIGINT, IronKeywds::Kw::bigInt_()},
        {IronStruct::MaskType::INT, IronKeywds::Kw::int_()},
        {IronStruct::MaskType::CHAR, IronKeywds::Kw::char_()},
        {IronStruct::MaskType::STRING, IronKeywds::Kw::string_()},
        {IronStruct::MaskType::DOUBLE, IronKeywds::Kw::double_()},
        {IronStruct::MaskType::FLOAT, IronKeywds::Kw::float_()},
        {IronStruct::MaskType::BOOL, IronKeywds::Kw::bool_()}};

    /**
     * @brief Converts a string to a MaskType enum value.
     *
     * This function converts a string representation of a data type to the corresponding MaskType enum value.
     * It supports case-insensitive matching by converting the input string to lowercase.
     *
     * @param str The string representation of the data type.
     * @return The corresponding MaskType enum value, or ERRT if the type is not recognized.
     */
    auto Inspector::stringToMaskType(const std::string &str) -> IronStruct::MaskType
    {
        // change to lower case, for case-insensitive matching
        std::string lower_str = str;
        std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);

        if (mask_type_map.find(lower_str) == mask_type_map.end())
        {
            return IronStruct::MaskType::ERRT;
        }
        return mask_type_map[lower_str];
    }

    /**
     * @brief Converts a MaskType enum value to its string representation.
     *
     * This function converts a MaskType enum value to the corresponding string representation.
     *
     * @param maskType The MaskType enum value to convert.
     * @return The string representation of the MaskType, or "errt" if the type is not recognized.
     */
    auto Inspector::maskTypeToString(IronStruct::MaskType maskType) -> std::string
    {
        if (mask_type_str_map.find(maskType) == mask_type_str_map.end())
        {
            return IronKeywds::Kw::errt_();
        }
        return mask_type_str_map[maskType];
    }

    /**
     * @brief Converts a string to a Value variant.
     *
     * This function converts a string to the appropriate type stored in a Value variant.
     * It handles boolean values, NULL values, integers, floating-point numbers, characters, and strings.
     *
     * @param str The string to convert.
     * @return The converted value stored in a Value variant.
     */
    auto Inspector::stringToValue(const std::string &str) -> IronStruct::Value
    {
        // 处理布尔值 true
        if (str == "true")
        {
            return true;
        }

        // 处理布尔值 false
        if (str == "false")
        {
            return false;
        }

        // 处理 NULL 值，转换为空字符串
        if (str == "NULL" || str == "null")
        {
            return std::string("");
        }

        bool is_integer = true;
        size_t start = 0;
        if (str[0] == '-' || str[0] == '+')
        {
            start = 1;
        }
        for (size_t i = start; i < str.length(); ++i)
        {
            if (!std::isdigit(str[i]))
            {
                is_integer = false;
                break;
            }
        }

        if (is_integer)
        {
            long long ll_val = 0;
            std::istringstream iss(str);
            iss >> ll_val;
            if (ll_val <= std::numeric_limits<int>::max() && ll_val >= std::numeric_limits<int>::min())
            {
                return static_cast<int>(ll_val);
            }
            if (ll_val <= std::numeric_limits<long>::max() && ll_val >= std::numeric_limits<long>::min())
            {
                return static_cast<long>(ll_val);
            }
            return ll_val;
        }

        bool is_float = false;
        int dot_count = 0;
        start = 0;
        if (str[0] == '-' || str[0] == '+')
        {
            start = 1;
        }
        for (size_t i = start; i < str.length(); ++i)
        {
            if (str[i] == '.')
            {
                dot_count++;
                if (dot_count > 1)
                {
                    break;
                }
                is_float = true;
            }
            else if (!std::isdigit(str[i]))
            {
                is_float = false;
                break;
            }
        }
        if (is_float && dot_count == 1)
        {
            double d_val = 0.0;
            std::istringstream iss(str);
            iss >> d_val;
            if (d_val <= std::numeric_limits<float>::max() && d_val >= std::numeric_limits<float>::min())
            {
                return static_cast<float>(d_val);
            }
            return d_val;
        }

        if (str.length() == 1)
        {
            return str[0];
        }

        return str;
    }

    /**
     * @brief Converts a Value variant to its string representation.
     *
     * This function converts a Value variant to the appropriate string representation based on its type.
     * It handles boolean values, integers, floating-point numbers, characters, and strings.
     * For floating-point numbers, it limits the precision to 2 decimal places and removes trailing zeros.
     *
     * @param val The Value variant to convert.
     * @return The string representation of the value.
     */
    auto Inspector::valueToString(IronStruct::Value val) -> std::string
    {
        return std::visit([](auto &&arg) -> std::string
                          {
            using T = std::decay_t<decltype(arg)>;
            // 处理布尔类型
            if constexpr (std::is_same_v<T, bool>)
            {
                return arg ? "true" : "false";
            }
            // 处理整数类型（不包括字符）
            else if constexpr (std::is_integral_v<T> && !std::is_same_v<T, char>)
            {
                if (arg == 0)
                {
                    return "null";
                }
                return std::to_string(arg);
            }
            // 处理浮点数类型，限制小数位数为2位
            else if constexpr (std::is_floating_point_v<T>)
            {
                if (arg == 0.0)
                {
                    return "null";
                }
                std::ostringstream oss;
                oss << std::fixed << std::setprecision(2) << arg;
                std::string result = oss.str();
                // 移除末尾的零和小数点（如果不需要）
                while (result.size() > 0 && result.back() == '0')
                {
                    result.pop_back();
                }
                if (result.size() > 0 && result.back() == '.')
                {
                    result.pop_back();
                }
                return result;
            }
            // 处理字符类型
            else if constexpr (std::is_same_v<T, char>)
            {
                if (arg == 0)
                {
                    return "null";
                }
                return std::string(1, arg);
            }
            // 处理字符串类型
            else if constexpr (std::is_same_v<T, std::string>)
            {
                if (arg.empty())
                {
                    return "null";
                }
                return arg;
            }
            // 其他类型返回null
            else
            {
                return "null";
            } }, val);
    }
} // namespace IronVerify
