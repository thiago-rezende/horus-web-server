/**
 * @file session.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Session class
 * @version 0.1
 * @date 2021-06-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <iostream>
#include <array>
#include "network.hpp"

namespace horus
{
    class connection_manager;

    class connection : public std::enable_shared_from_this<connection>
    {
    private:
        asio::ip::tcp::socket socket_;
        std::array<char, 8166> buffer_;
        connection_manager &connection_manager_;

    public:
        connection(asio::ip::tcp::socket &&socket, connection_manager &manager);
        ~connection() = default;

        void start();
        void stop();

    private:
        void do_read();
        void do_write();

    public:
        connection(const connection &) = delete;
        connection(const connection &&) = delete;

        connection &operator=(const connection &) = delete;
        connection &operator=(const connection &&) = delete;
    };

    using connection_ptr = std::shared_ptr<connection>;
} // namespace horus
