#include "iron_path_manage.hpp"
#include "iron_help.hpp"
#include "iron_read_help_info.hpp"
#include "iron_path_system.hpp"
#include <random>
#include <vector>

namespace IronHelpColor
{
    static const std::string R{"\033[31m"};
    static const std::string G{"\033[32m"};
    static const std::string Y{"\033[33m"};
    static const std::string B{"\033[34m"};
    static const std::string M{"\033[35m"};
    static const std::string C{"\033[36m"};
    static const std::string W{"\033[37m"};
    static const std::string E{"\033[0m"};

    class Ht
    {

    private:
        Ht() = delete;
        ~Ht() = delete;

    public:
        static void _printHighlightString(const std::string &color, const std::string &msg);
    }; // class Ht

    /******************************************************************************************
     * @brief Prints a highlighted string with the specified color.                           *
     * This function prints a message with the specified color code for highlighting.         *
     *                                                                                        *
     * @param color The color code to use for highlighting.                                   *
     * @param msg The message to print.                                                       *
     ******************************************************************************************/
    void Ht::_printHighlightString(const std::string &color, const std::string &msg) { std::cout << color << msg << E << std::endl; }

} // namespace IronHelpColor

namespace IronHelp
{
    namespace Rinfo = IronReadHelpInfo;
    namespace Color = IronHelpColor;
    namespace IPath = IronPathSystem;

    std::mutex ShowHelpInformation::hmtx; /* Initialize the mutex */

    static bool _enableHelpHighlight{false};

    static const std::string ZH_CN{"zh_cn"};
    static std::string language_tp; /* set language environment variable */

    /******************************************************************************************
     * @brief Sets the highlight status for help messages.                                    *
     * This function sets the highlight status for help messages.                             *
     *                                                                                        *
     * @param enable_highlight Whether to enable color highlighting.                          *
     ******************************************************************************************/
    void ShowHelpInformation::setHighlight(const bool &enable_highlight) { _enableHelpHighlight = enable_highlight; }

    /******************************************************************************************
     * @brief Sets the language environment variable.                                         *
     * This function sets the language environment variable.                                  *
     *                                                                                        *
     * @param lang The language to set.                                                       *
     ******************************************************************************************/
    void ShowHelpInformation::setLanguage(const std::string &lang) { language_tp = lang; }

    /******************************************************************************************
     * @brief The vector of available colors for highlighting.                                *
     ******************************************************************************************/
    static const std::vector<std::string> COLORS = {Color::R, Color::G, Color::Y, Color::B, Color::M, Color::C, Color::W};

    /******************************************************************************************
     * @brief Gets a random color from the COLORS vector.                                     *
     * This function returns a randomly selected color code from the predefined COLORS vector *
     *                                                                                        *
     * @return A random color code                                                            *
     * ****************************************************************************************/
    static std::string _getRandomColor()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, COLORS.size() - 1);
        return COLORS[dis(gen)];
    }

    /*********************************************************************************************************
     * @brief Chooses the language content based on the specified language.                                  *
     *                                                                                                       *
     * This function returns the path to the help file for the specified language.                           *
     *                                                                                                       *
     * @param otherLangPath The path to the help file in the other language.                                 *
     * @param enUSPath The path to the help file in English.                                                 *
     * @param lang The language to choose.                                                                   *
     * @return The path to the help file for the specified language.                                         *
     *********************************************************************************************************/
    static auto _chooseLanguageContent(const std::filesystem::path &otherLangPath, const std::filesystem::path &enUSPath,
                                       const std::string &lang) -> std::filesystem::path
    {
        if (lang == ZH_CN)
        {
            return otherLangPath;
        }

        return enUSPath;
    }

    /*********************************************************************************************************
     * @brief Opens the file at the specified path.                                                          *
     *                                                                                                       *
     * This function attempts to open the file at the specified path. If the file is successfully opened,    *
     * it returns true. If the file cannot be opened, it returns false.                                      *
     *                                                                                                       *
     * @warning must manual close file after use.                                                            *
     *                                                                                                       *
     * @param tarfile The file to open.                                                                      *
     * @return true if the file is successfully opened, false otherwise.                                     *
     *********************************************************************************************************/
    static auto _openFileStates(const std::fstream &tarfile) -> bool
    {
        if (!tarfile.is_open())
        {
            return false;
        }

        return true;
    }

    /*********************************************************************************************************
     * @brief Outputs the content of the specified file to the standard output.                              *
     *                                                                                                       *
     * @attention auto close file after use, please do not close it manually.                                *
     *                                                                                                       *
     * @param tarfile The file to read from.                                                                 *
     * @param enable_highlight Whether to enable color highlighting.                                         *
     *********************************************************************************************************/
    static auto _outFileContent(std::fstream &tarfile, const bool &enable_highlight) -> void
    {
        std::string line;

        if (enable_highlight || _enableHelpHighlight) /* out highlight line */
        {
            while (std::getline(tarfile, line))
            {
                Color::Ht::_printHighlightString(_getRandomColor(), line);
            }
            tarfile.close();
            return;
        }

        while (std::getline(tarfile, line)) /* default output */
        {
            std::cout << line << std::endl;
        }
        tarfile.close();
    }

    /******************************************************************************************
     * @brief To obtain the final and determinable path, the parameters only need to be       *
     * passed in as "language type", "default English text file", and "other language files"  *
     *                                                                                        *
     * @param lang choose language, default is English.                                       *
     *                                                                                        *
     * @param fname_en_us default English text file.                                          *
     * @param fname_other other language files.                                               *
     * @return std::filesystem::path the final and determinable path.                         *
     ******************************************************************************************/
    static auto _getTargetHelpFilePath(const std::string &lang, const std::string &fname_en_us, const std::string &fname_other)
        -> std::filesystem::path
    {
        auto platform_path = _chooseLanguageContent(
            IPath::Psm::returnPath(
                IronPathManage::Control::windowsSettingsConfigPath() / fname_other,
                IronPathManage::Control::linuxSettingsConfigPath() / fname_other),
            IPath::Psm::returnPath(
                IronPathManage::Control::windowsSettingsConfigPath() / fname_en_us,
                IronPathManage::Control::linuxSettingsConfigPath() / fname_en_us),
            lang);
        return platform_path;
    }

    /*********************************************************************************************************
     * ***************************************************************************************************** *
     * *                               FROM FILE READ HELP INFORMATION                                     * *
     * ***************************************************************************************************** *
     *********************************************************************************************************/

    /*********************************************************************************************************
     * @brief Show IronSQL syntax information details.                                                       *
     *                                                                                                       *
     * @param lang Language of the help information.                                                         *
     * @param enable_highlight Whether to enable color highlighting.                                         *
     * @details This function use method need keep code style.                                               *
     *********************************************************************************************************/
    void ShowHelpInformation::showIronSQLSyntaxInformationDetails(const std::string &lang, const bool &enable_highlight)
    {
        std::lock_guard<std::mutex> lock(hmtx); // Lock the mutex to ensure thread safety

        std::filesystem::path platform_path{_getTargetHelpFilePath(
            lang, "ironsql_syntax_help_en_US.txt", "ironsql_syntax_help_zh_CN.txt")};

        std::fstream file(platform_path.string(), std::ios::in | std::ios::binary);

        if (!_openFileStates(file))
        {
            std::cerr << "Failed to open help file : " << platform_path.string() << std::endl;
            return;
        }

        _outFileContent(file, enable_highlight);
    }

    /*********************************************************************************************************
     * @brief Show welcome message.                                                                          *
     *                                                                                                       *
     * @param enable_highlight Whether to enable color highlighting.                                         *
     *********************************************************************************************************/
    void ShowHelpInformation::showWelcomeMessage(const bool &enable_highlight)
    {
        std::lock_guard<std::mutex> lock(hmtx); // Lock the mutex to ensure thread safety

        std::filesystem::path platform_path{_getTargetHelpFilePath(language_tp, "iron_welcome_en_US.txt", "iron_welcome_zh_CN.txt")};

        std::fstream file(platform_path.string(), std::ios::in | std::ios::binary);

        if (!_openFileStates(file))
        {
            std::cerr << "Failed to open welcome help file : " << platform_path.string() << std::endl;
            return;
        }

        _outFileContent(file, enable_highlight);
    }

    /*********************************************************************************************************
     * @brief Show help guide.                                                                               *
     *                                                                                                       *
     * @param enable_highlight Whether to enable color highlighting.                                         *
     *********************************************************************************************************/
    void ShowHelpInformation::showHelpGuide(const bool &enable_highlight)
    {
        std::lock_guard<std::mutex> lock(hmtx); // Lock the mutex to ensure thread safety

        const std::string prefix_zn_cn{"iron_help_guide_zh_CN.txt"};
        const std::string prefix_en_us{"iron_help_guide_en_US.txt"};

        std::string fname{prefix_en_us}; /* default en_US */
        if (language_tp == "zh_cn")
        {
            fname = prefix_zn_cn;
        }

        /* get help file path directory */
        auto platform_path{IPath::Psm::returnPath(IronPathManage::Control::windowsSettingsConfigPath(),
                                                  IronPathManage::Control::linuxSettingsConfigPath())};

        if (!std::filesystem::exists(platform_path)) /* check help file path exists */
        {
            std::cerr << "File path not exists: " << platform_path.string() << std::endl;
            return;
        }

        if (!std::filesystem::is_directory(platform_path)) /* check help file path is directory */
        {
            std::cerr << "File path is not directory: " << platform_path.string() << std::endl;
            return;
        }

        std::filesystem::path file_path{platform_path / fname};
        std::fstream file(file_path.string(), std::ios::in | std::ios::binary);

        if (!_openFileStates(file)) /* check help file open success */
        {
            std::cerr << "Failed to open help file : " << file_path.string() << std::endl;
            return;
        }

        _outFileContent(file, enable_highlight); /* output help file content */
    }

    /*********************************************************************************************************
     * @brief Show help more information.                                                                    *
     *                                                                                                       *
     * @param lang Language of the help information.                                                         *
     * @param query_keyword Query keyword for the help information.                                          *
     * @param enable_highlight Whether to enable color highlighting.                                         *
     *********************************************************************************************************/
    void ShowHelpInformation::showHelpMore(const std::string &lang, const std::string &query_keyword, const bool &enable_highlight)
    {
        std::lock_guard<std::mutex> lock(hmtx); // Lock the mutex to ensure thread safety

        if (query_keyword.empty())
        {
            std::cerr << "Error: Query keyword is empty. You must input a query keyword.\n"
                         "for example: help -syntax --more-zh_cn-create"
                      << std::endl;
            return;
        }

        const std::string prefix_zn_cn{"ironsql_syntax_zh_CN_"};
        const std::string prefix_en_us{"ironsql_syntax_en_US_"};
        const std::string suffix_txt{".txt"};

        std::string fname{prefix_en_us + query_keyword + suffix_txt}; /* default en_US */
        if (lang == "zh_cn")
        {
            fname = prefix_zn_cn + query_keyword + suffix_txt;
        }

        /* get help file path directory */
        auto platform_path{IPath::Psm::returnPath(IronPathManage::Control::windowsSettingsConfigPath(),
                                                  IronPathManage::Control::linuxSettingsConfigPath())};

        if (!std::filesystem::exists(platform_path)) /* check help file path exists */
        {
            std::cerr << "File path not exists: " << platform_path.string() << std::endl;
            return;
        }

        if (!std::filesystem::is_directory(platform_path)) /* check help file path is directory */
        {
            std::cerr << "File path is not directory: " << platform_path.string() << std::endl;
            return;
        }

        /* */
        bool find_state{false};
        for (const auto &entry : std::filesystem::directory_iterator(platform_path))
        {
            if (entry.is_regular_file())
            {
                if (entry.path().filename().string() == fname)
                {
                    find_state = true;
                    break;
                }
            }
        }

        if (!find_state) /* check help file exists */
        {
            std::cerr << "Help file not exists: " << fname << std::endl;
            return;
        }

        std::filesystem::path file_path{platform_path / fname};
        std::fstream file(file_path.string(), std::ios::in | std::ios::binary);

        if (!_openFileStates(file)) /* check help file open success */
        {
            std::cerr << "Failed to open help file : " << file_path.string() << std::endl;
            return;
        }

        _outFileContent(file, enable_highlight); /* output help file content */
    }

} // namespace IronHelp