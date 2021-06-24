#include "logger.hpp"
#include "connection.hpp"
#include "connection_manager.hpp"

namespace horus
{
    connection::connection(asio::ip::tcp::socket &&socket, connection_manager &manager)
        : socket_(std::move(socket)),
          connection_manager_(manager)
    {
    }

    void connection::start()
    {
        horus::logger::info("[connection] started");

        do_read();
    }

    void connection::stop()
    {
        socket_.close();

        horus::logger::info("[connection] closed");
    }

    void connection::do_read()
    {
        horus::logger::info("[connection] reading");

        auto handler = [this, self = shared_from_this()](asio::error_code ec, size_t bytes_transferred)
        {
            if (!ec)
            {
                do_write();
            }
            else if (ec != asio::error::operation_aborted)
            {
                connection_manager_.stop(shared_from_this());
            }
        };

        socket_.async_read_some(asio::buffer(buffer_), handler);
    }

    void connection::do_write()
    {
        horus::logger::info("[connection] writing");

        const char response[] =
            "HTTP/1.1 200 OK\r\n"
            "Host: 127.0.0.1:8080\r\n"
            "Content-Type: text/html\r\n"
            "Content-Size: 55\r\n"
            "\r\n"
            "<html><title>It Works!</title><h1>It Works!</h1></html>";

        auto handler = [this, self = shared_from_this()](asio::error_code ec, std::size_t)
        {
            horus::logger::info("[connection] stopping");

            if (!ec)
            {
                asio::error_code ignored_ec;
                socket_.shutdown(asio::ip::tcp::socket::shutdown_both, ignored_ec);
            }

            if (ec != asio::error::operation_aborted)
            {
                connection_manager_.stop(shared_from_this());
            }
        };

        asio::async_write(socket_, asio::buffer(response), handler);
    }

} // namespace horus
