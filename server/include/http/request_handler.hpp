/**
 * @file request_handler.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief HTTP request handler
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <string>
#include <filesystem>

#include "http/request.hpp"
#include "http/response.hpp"

namespace horus
{
    namespace http
    {
        class request_handler
        {
        private:
            std::filesystem::path document_root_;

        public:
            request_handler(std::filesystem::path document_root);
            ~request_handler() = default;

            void handle_request(const request &req, response &res);

        private:
            bool url_decode(const std::string &in, std::string &out);

        public:
            request_handler(const request_handler &) = delete;
            request_handler(const request_handler &&) = delete;

            request_handler &operator=(const request_handler &) = delete;
            request_handler &operator=(const request_handler &&) = delete;
        };

    } // namespace http

} // namespace horus
