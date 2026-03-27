#include "iron_langs.hpp"

static const std::unordered_map<std::string, std::string> _lang_map = {
    {"zh_cn", "zh_cn"},
    {"zh_CN", "zh_cn"},
    {"en_us", "en_us"},
    {"en_US", "en_us"},
};

std::mutex IronLangs::Language::lang_mutex_; /* Initialize the mutex */

/************************************************************************************************************
 * @brief Get the language name.                                                                            *
 * @param lang_name Language name                                                                           *
 * @return std::string Language name                                                                        *
 ************************************************************************************************************/
auto IronLangs::Language::getLanguage(const std::string &lang) -> std::string
{
    std::lock_guard<std::mutex> lock(lang_mutex_);

    if (lang.empty())
    {
        return "en_us";
    }

    if (_lang_map.find(lang) != _lang_map.end())
    {
        return _lang_map.at(lang);
    }

    return "en_us";
}
