#include "iron_path_init.hpp"

namespace IronPathInit
{

    std::shared_mutex Initer::pmtx;

    auto Initer::initPath(const std::filesystem::path &tpath) -> void
    {
        std::lock_guard<std::shared_mutex> lock(pmtx);

        if (!std::filesystem::exists(tpath))
        {
            try
            {
                std::filesystem::create_directories(tpath);
            }
            catch (const std::filesystem::filesystem_error &)
            {
                std::cerr << "error: create path failed (maybe permission denied)" << tpath.string() << std::endl;
                return;
            }
        }
    }
} // namespace IronPathInit
