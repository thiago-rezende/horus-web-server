/**
 * @file logger.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Logger interface
 * @version 0.1
 * @date 2021-06-23
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
        void init(spdlog::level::level_enum level = spdlog::level::trace, const char *pattern = "[%^%l%$] %v");

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

/* Logger Macros */
// #ifdef ENABLE_LOGGER // Only defined on debug builds to save performance
#define LOG_TRACE(...) ::spdlog::trace(__VA_ARGS__)
#define LOG_DEBUG(...) ::spdlog::debug(__VA_ARGS__)
#define LOG_INFO(...) ::spdlog::info(__VA_ARGS__)
#define LOG_WARN(...) ::spdlog::warn(__VA_ARGS__)
#define LOG_ERROR(...) ::spdlog::error(__VA_ARGS__)
#define LOG_CRITICAL(...) ::spdlog::critical(__VA_ARGS__)
// #else
// #define LOG_TRACE(...)
// #define LOG_DEBUG(...)
// #define LOG_INFO(...)
// #define LOG_WARN(...)
// #define LOG_ERROR(...)
// #define LOG_CRITICAL(...)
// #endif
