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
     *                                                                                        *
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
    static const std::string ZH_CN = "zh_cn";

    /******************************************************************************************
     * @brief Sets the highlight status for help messages.                                    *
     *                                                                                        *
     * This function sets the highlight status for help messages.                             *
     *                                                                                        *
     * @param enable_highlight Whether to enable color highlighting.                          *
     ******************************************************************************************/
    void ShowHelpInformation::setHighlight(const bool &enable_highlight) { _enableHelpHighlight = enable_highlight; }

    /******************************************************************************************
     * @brief The vector of available colors for highlighting.                                *
     ******************************************************************************************/
    static const std::vector<std::string> COLORS = {Color::R, Color::G, Color::Y, Color::B, Color::M, Color::C, Color::W};

    /******************************************************************************************
     * @brief Gets a random color from the COLORS vector.                                     *
     *                                                                                        *
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

        std::filesystem::path sure_help_file;

        // default output is english
#if defined(_WIN32) || defined(_WIN64) // windows
        std::filesystem::path help_file{IronPathManage::Control::windowsSettingsConfigPath() / "Ironsql_syntax_help_en_US.txt"};
#else
        std::filesystem::path help_file{IronPathManage::Control::linuxSettingsConfigPath() / "Ironsql_syntax_help_en_US.txt"};
#endif

        if (lang == ZH_CN)
        {
#if defined(_WIN32) || defined(_WIN64) // windows
            std::filesystem::path help_file{IronPathManage::Control::windowsSettingsConfigPath() / "Ironsql_syntax_help_zh_CN.txt"};
            sure_help_file = help_file;
#else
            std::filesystem::path help_file{IronPathManage::Control::linuxSettingsConfigPath() / "Ironsql_syntax_help_zh_CN.txt"};
            sure_help_file = help_file;
#endif
        }
        else
        {
            sure_help_file = help_file;
        }

        if (!std::filesystem::exists(sure_help_file))
        {
            std::cerr << "Help file not found ! please go to the project official website to get the help file." << std::endl;
            return;
        }

        std::fstream file(sure_help_file.string(), std::ios::in | std::ios::binary);
        if (!file.is_open())
        {
            std::cerr << "Failed to open help file : " << sure_help_file.string() << std::endl;
            return;
        }

        // output help file content
        std::string line;

        // if true: out highlight help file content, else: out help file content as is
        if (enable_highlight || _enableHelpHighlight)
        {
            while (std::getline(file, line))
            {
                Color::Ht::_printHighlightString(_getRandomColor(), line);
            }
            file.close();
            return;
        }

        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        file.close();
    }

    /*********************************************************************************************************
     * @brief Show welcome message.                                                                          *
     *                                                                                                       *
     * @param lang Language of the welcome message.                                                          *
     * @param enable_highlight Whether to enable color highlighting.                                         *
     *********************************************************************************************************/
    void ShowHelpInformation::showWelcomeMessage(const std::string &lang, const bool &enable_highlight = false)
    {
        std::lock_guard<std::mutex> lock(hmtx); // Lock the mutex to ensure thread safety

        auto platform_path = _chooseLanguageContent(
            IPath::Psm::returnPath(
                IronPathManage::Control::linuxSettingsConfigPath() / "iron_welcome_zh_CN.txt",
                IronPathManage::Control::linuxSettingsConfigPath() / "iron_welcome_zh_CN.txt"),
            IPath::Psm::returnPath(
                IronPathManage::Control::windowsSettingsConfigPath() / "iron_welcome_en_US.txt",
                IronPathManage::Control::windowsSettingsConfigPath() / "iron_welcome_en_US.txt"),
            lang);

        std::fstream file(platform_path.string(), std::ios::in | std::ios::binary);

        if (!_openFileStates(file))
        {
            std::cerr << "Failed to open welcome file : " << platform_path.string() << std::endl;
            return;
        }
    }

} // namespace IronHelp