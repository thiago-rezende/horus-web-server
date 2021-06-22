/**
 * @file logger.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Logger interface abstraction
 * @version 0.1
 * @date 2021-06-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace horus
{
    namespace logger
    {
        namespace level
        {
            enum log_level
            {
                trace = spdlog::level::trace,
                debug = spdlog::level::debug,
                info = spdlog::level::info,
                warn = spdlog::level::warn,
                err = spdlog::level::err,
                critical = spdlog::level::critical,
            };
        }

        void init(const char *name = "log", level::log_level level = level::trace, const char *pattern = "[%n] [%^%l%$] [thread %t] %v")
        {
            spdlog::set_default_logger(spdlog::stdout_color_mt(name));
            spdlog::set_pattern(pattern);
            spdlog::set_level(static_cast<spdlog::level::level_enum>(level));
        }

        template <typename... Args>
        void trace(Args &&...args) { spdlog::trace(std::forward<Args>(args)...); }

        template <typename... Args>
        void debug(Args &&...args) { spdlog::debug(std::forward<Args>(args)...); }

        template <typename... Args>
        void info(Args &&...args) { spdlog::info(std::forward<Args>(args)...); }

        template <typename... Args>
        void warn(Args &&...args) { spdlog::warn(std::forward<Args>(args)...); }

        template <typename... Args>
        void error(Args &&...args) { spdlog::error(std::forward<Args>(args)...); }

        template <typename... Args>
        void critical(Args &&...args) { spdlog::critical(std::forward<Args>(args)...); }
    } // namespace logger

} // namespace horus
