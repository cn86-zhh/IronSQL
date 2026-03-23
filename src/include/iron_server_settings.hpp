#pragma once

#ifndef IRON_SERVER_SETTINGS_HPP
#define IRON_SERVER_SETTINGS_HPP

#include <iostream>
#include <string>

static void ironSettingsEnable(const std::string &settings_sentence, bool &ref_result);
static void ironSettingsDisable(const std::string &settings_sentence, bool &ref_result);

#endif // IRON_SERVER_SETTINGS_HPP