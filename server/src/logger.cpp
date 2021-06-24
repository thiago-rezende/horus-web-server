#include "logger.hpp"

namespace horus
{
    namespace logger
    {
        void init(spdlog::level::level_enum level, const char *pattern)
        {
            spdlog::set_default_logger(spdlog::stdout_color_mt("logger"));
            spdlog::set_pattern(pattern);
            spdlog::set_level(static_cast<spdlog::level::level_enum>(level));
        }
    } // namespace logger

} // namespace horus
