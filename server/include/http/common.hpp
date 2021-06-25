/**
 * @file common.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Common http
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
        namespace strings
        {
            namespace method
            {
                constexpr std::string_view GET = "GET";
                constexpr std::string_view HEAD = "HEAD";
                constexpr std::string_view POST = "POST";
                constexpr std::string_view PUT = "PUT";
                constexpr std::string_view DELETE_ = "DELETE";
                constexpr std::string_view CONNECT = "CONNECT";
                constexpr std::string_view OPTIONS = "OPTIONS";
                constexpr std::string_view TRACE = "TRACE";
                constexpr std::string_view PATCH = "PATCH";
            } // namespace method

            namespace version
            {
                constexpr std::string_view HTTP_1_0 = "HTTP/1.0";
                constexpr std::string_view HTTP_1_1 = "HTTP/1.1";
            } // namespace version

            constexpr std::string_view COLON = ":";
            constexpr std::string_view CRLF = "\r\n";

        } // namespace strings

    } // namespace http

} // namespace horus
