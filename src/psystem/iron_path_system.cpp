#include "iron_path_system.hpp"

// Initialize the static member variable
std::mutex IronPathSystem::Psm::pmtx;

/************************************************************************************************************
 * @brief Return the path based on the platform.                                                            *
 *                                                                                                          *
 * @param pwindows The path for Windows.                                                                    *
 * @param punix The path for Unix (Linux, MacOS).                                                           *
 * @return std::filesystem::path The path based on the platform.                                            *
 ************************************************************************************************************/
auto IronPathSystem::Psm::returnPath(const std::filesystem::path &pwindows, const std::filesystem::path &punix) -> std::filesystem::path
{
    std::lock_guard<std::mutex> lock(pmtx); /* Lock the mutex to ensure thread safety */

#if defined(_WIN32) || defined(_WIN64) /* Platform: Windows*/
    return pwindows;
#else /* Platform: Unix (Linux, MacOS) */
    return punix;
#endif

} // function returnPath
