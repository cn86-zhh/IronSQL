#include "iron_server_settings.hpp"

static const bool FALSE{false};
static const bool TRUE{true};

/**
 * @brief IronSQL enable settings function.
 * this function just only include the enable settings.
 *
 * @param settings_sentence Settings sentence
 * @param ref_result Reference parameter to store the result
 */
void ironSettingsEnable(const std::string &settings_sentence, bool &ref_result)
{
    // enable global highlight
    if (settings_sentence == "set -enable --global --highlight")
    {
    }

    // enable debug mode
    if (settings_sentence == "set -enable --debug")
    {
    }

    // enable debug highlight mode
    if (settings_sentence == "set -enable --debug --highlight")
    {
    }

    // enable help info highlight
    if (settings_sentence == "set -enable --highlight --for-help" || settings_sentence == "set -enable --help --highlight")
    {
    }

    // other unknown settings setting reference parameter to FALSE
    else
    {
        ref_result = FALSE;
    }
}

/**
 * @brief IronSQL disable settings function.
 * this function just only include the disable settings.
 *
 * @param settings_sentence Settings sentence
 * @param ref_result Reference parameter to store the result
 */
void ironSettingsDisable(const std::string &settings_sentence, bool &ref_result)
{
    // disable global highlight
    if (settings_sentence == "set -disable --global --highlight")
    {
    }

    // disable debug mode
    if (settings_sentence == "set -disable --debug")
    {
    }

    // disable debug highlight mode
    if (settings_sentence == "set -disable --debug --highlight")
    {
    }

    // disable help info highlight
    if (settings_sentence == "set -disable --highlight --for-help" || settings_sentence == "set -disable --help --highlight")
    {
    }

    // change language
    if (settings_sentence.substr(0, 9) == "set -lang")
    {
    }

    // other unknown settings setting reference parameter to FALSE
    else
    {
        ref_result = FALSE;
    }
}
