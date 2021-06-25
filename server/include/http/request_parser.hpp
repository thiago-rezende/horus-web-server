/**
 * @file request_parser.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief HTTP request parser
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <vector>

#include "http/common.hpp"
#include "http/request.hpp"

namespace horus
{
    namespace http
    {
        class request_parser
        {
        private:
            enum class state
            {
                method_start,
                method,
                uri,
                http_version_h,
                http_version_t_1,
                http_version_t_2,
                http_version_p,
                http_version_slash,
                http_version_major_start,
                http_version_major,
                http_version_minor_start,
                http_version_minor,
                expecting_newline_1,
                header_line_start,
                header_lhs,
                header_name,
                space_before_header_value,
                header_value,
                expecting_newline_2,
                expecting_newline_3
            };

            state state_;

        public:
            request_parser();
            ~request_parser() = default;

            void reset();

            enum class result_type
            {
                ok,
                error,
                indeterminate
            };

            template <typename InputIterator>
            std::tuple<result_type, InputIterator> parse(request &req, InputIterator begin, InputIterator end)
            {
                while (begin != end)
                {
                    result_type result = consume(req, *begin++);

                    if (result == result_type::ok || result == result_type::error)
                        return std::make_tuple(result, begin);
                }

                return std::make_tuple(result_type::indeterminate, begin);
            }

        private:
            std::vector<std::string> split(std::string text, std::string delimiter);
            result_type consume(request &req, char input);

            static bool is_char(int c);
            static bool is_ctl(int c);
            static bool is_tspecial(int c);
            static bool is_digit(int c);

            bool validate_method(std::string method);
            bool validate_version(std::string version);

        public:
            request_parser(const request_parser &) = delete;
            request_parser(const request_parser &&) = delete;

            request_parser &operator=(const request_parser &) = delete;
            request_parser &operator=(const request_parser &&) = delete;
        };
    } // namespace http

} // namespace horus
