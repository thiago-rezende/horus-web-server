/**
 * @file request.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief HTTP request
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <string>
#include <vector>
#include <sstream>

#include "http/header.hpp"

namespace horus
{
    namespace http
    {
        struct request
        {
            std::string method;
            std::string target;
            std::string version;
            std::vector<header> headers;
            std::string body;

            std::string to_string()
            {
                std::stringstream req_str;

                req_str << method << " " << target << " " << version << "\r\n";

                for (auto &h : headers)
                    req_str << h.name << ": " << h.value << "\r\n";

                req_str << "\r\n"
                        << body;

                return req_str.str();
            }

            std::string status_line()
            {
                return method + " " + target + " " + version;
            }
        };

    } // namespace http

} // namespace horus
