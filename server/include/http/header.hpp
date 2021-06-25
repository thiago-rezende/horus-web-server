/**
 * @file header.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief HTTP message header
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <string>

namespace horus
{
    namespace http
    {
        struct header
        {
            std::string name;
            std::string value;
        };

    } // namespace http

} // namespace horus
