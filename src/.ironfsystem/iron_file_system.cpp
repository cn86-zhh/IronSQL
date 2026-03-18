#include "iron_file_system.hpp"

namespace IronFileSystem
{
    /**
     * @brief Check if a directory exists.
     *
     * @param path The path to the directory.
     * @return true If the directory exists.
     * @return false If the directory does not exist.
     */
    auto Fsys::inspectDirectoryExist(const std::filesystem::path &path) -> bool
    {
        return std::filesystem::exists(path);
    }

    /**
     * @brief Create a directory.
     * ATTENTION: This function include not explicit processing method.
     * inculde: try-catch
     * @param path The path to the directory.
     * @return true If the directory was created.
     * @return false If the directory could not be created.
     */
    auto Fsys::createDirectory(const std::filesystem::path &path) -> bool
    {
        try
        {
            std::filesystem::create_directory(path);
            return true;
        }
        catch (const std::filesystem::filesystem_error &e)
        {
            std::cerr << "error creating directory: " << e.what() << std::endl;
            return false;
        }
    }

    /**
     * @brief Check if a file exists.
     *
     * @param path The path to the file.
     * @return true If the file exists.
     * @return false If the file does not exist.
     */
    auto Fsys::inspectFileExist(const std::filesystem::path &path) -> bool
    {
        return std::filesystem::exists(path);
    }

    /**
     * @brief Create a file.
     * ATTENTION: This function include not explicit processing method.
     * inculde: try-catch
     * @param path The path to the file.
     * @return true If the file was created.
     * @return false If the file could not be created.
     */
    auto Fsys::createFile(const std::filesystem::path &path) -> bool
    {
        try
        {
            std::ofstream file(path);
            if (file.is_open())
            {
                file.close();
                return true;
            }
            return false;
        }
        catch (const std::exception &e)
        {
            std::cerr << "error creating file: " << e.what() << std::endl;
            return false;
        }
    }

} // namespace IronFileSystem