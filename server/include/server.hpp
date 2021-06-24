/**
 * @file server.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Server class
 * @version 0.1
 * @date 2021-06-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <optional>

#include "network.hpp"
#include "connection_manager.hpp"

namespace horus
{
    class server
    {
    private:
        asio::signal_set signals_;
        asio::io_context &context_;
        asio::ip::tcp::acceptor acceptor_;
        connection_manager connection_manager_;
        asio::ip::tcp::socket socket_;

    public:
        server(asio::io_context &context, uint16_t port);
        ~server() = default;

        void run();

    private:
        void do_async_accept();
        void do_await_stop();

    public:
        server(const server &) = delete;
        server(const server &&) = delete;

        server &operator=(const server &) = delete;
        server &operator=(const server &&) = delete;
    };
} // namespace horus
