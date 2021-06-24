/**
 * @file path.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Path utils
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <string>
#include <filesystem>

namespace horus
{
    namespace utils
    {
        std::filesystem::path get_executable_path();
        std::filesystem::path get_executable_dir();
    } // namespace utils

} // namespace horus
