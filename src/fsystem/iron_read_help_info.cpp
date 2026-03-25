#include "iron_read_help_info.hpp"

// shared mutex for read help info
std::shared_mutex IronReadHelpInfo::ReadStream::rmutex;

/********************************************************************************************
 * @brief Read help info from file.                                                         *
 *                                                                                          *
 * @param tarpath File path to read help info from.                                         *
 * @return std::vector<std::string> Help info lines (help content).                         *
 ********************************************************************************************/
auto IronReadHelpInfo::ReadStream::readLine(const std::filesystem::path &tarpath) -> std::vector<std::string>
{
    std::shared_lock<std::shared_mutex> lock(rmutex); /* lock shared mutex */

    if (!std::filesystem::exists(tarpath)) /* check file exists */
    {
        return {};
    }

    std::fstream file(tarpath.string(), std::ios::in | std::ios::binary);
    if (!file.is_open()) /* check file open */
    {
        return {};
    }

    std::vector<std::string> content;
    if (!content.empty()) /* check content array list is empty */
    {
        content.clear(); /* clear content array list */
    }

    std::string line;
    while (std::getline(file, line)) /* read line from file */
    {
        content.push_back(line); /* add line to content array list */
    }

    return content;
}
