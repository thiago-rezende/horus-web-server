#include "utils/path.hpp"
#include "utils/platform_detection.hpp"

#if defined(PLATFORM_WINDOWS)
#include <windows.h>
#include <Shlwapi.h>
#include <io.h>

#define access _access_s
#endif

#if defined(PLATFORM_APPLE)
#include <libgen.h>
#include <limits.h>
#include <mach-o/dyld.h>
#include <unistd.h>
#endif

#if defined(PLATFORM_LINUX)
#include <limits.h>
#include <libgen.h>
#include <unistd.h>

#if defined(__sun)
#define PROC_SELF_EXE "/proc/self/path/a.out"
#else
#define PROC_SELF_EXE "/proc/self/exe"
#endif

#endif

namespace horus
{
    namespace utils
    {
#if defined(PLATFORM_LINUX)
        std::filesystem::path get_executable_path()
        {
            char raw_path[PATH_MAX];

            realpath(PROC_SELF_EXE, raw_path);

            return std::filesystem::path(raw_path);
        }

        std::filesystem::path get_executable_dir()
        {
            return get_executable_path().parent_path();
        }
#endif // defined(PLATFORM_LINUX)

#if defined(PLATFORM_WINDOWS)
        std::filesystem::path get_executable_path()
        {
            char raw_path[MAX_PATH];

            GetModuleFileNameA(nullptr, raw_path, MAX_PATH);

            return std::filesystem::path(raw_path);
        }

        std::filesystem::path get_executable_dir()
        {
            return get_executable_path().parent_path();
        }
#endif // defined(PLATFORM_WINDOWS)

#if defined(PLATFORM_APPLE)
        std::filesystem::path get_executable_path()
        {
            char raw_path[PATH_MAX];
            char real_path[PATH_MAX];

            uint32_t rawPathSize = (uint32_t)sizeof(raw_path);

            if (!_NSGetExecutablePath(raw_path, &rawPathSize))
            {
                realpath(raw_path, real_path);
            }

            return std::filesystem::path(real_path);
        }

        std::filesystem::path get_executable_dir()
        {
            return get_executable_path().parent_path();
        }
#endif // defined(PLATFORM_APPLE)

    } // namespace utils

} // namespace horus
