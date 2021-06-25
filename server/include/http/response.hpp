/**
 * @file response.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief HTTP response
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <string>
#include <vector>

namespace horus
{
    namespace http
    {
        struct response
        {
            std::string version;
            uint16_t status;
            std::string reason;
            std::vector<header> headers;
            std::string body;

            std::string to_string()
            {
                std::stringstream req_str;

                req_str << version << " " << status << " " << reason << "\r\n";

                for (auto &h : headers)
                    req_str << h.name << ": " << h.value << "\r\n";

                req_str << "\r\n"
                        << body;

                return req_str.str();
            }
        };

    } // namespace http

} // namespace horus
