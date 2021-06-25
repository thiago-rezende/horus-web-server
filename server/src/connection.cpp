#include "logger.hpp"
#include "connection.hpp"
#include "connection_manager.hpp"

namespace horus
{
    connection::connection(asio::ip::tcp::socket &&socket, connection_manager &manager)
        : socket_(std::move(socket)),
          connection_manager_(manager),
          request_parser_()
    {
    }

    void connection::start()
    {
        horus::logger::info("[connection] <{}> started", socket_.remote_endpoint().address().to_string());

        do_read();
    }

    void connection::stop()
    {
        if (socket_.is_open())
            horus::logger::info("[connection] <{}> closed", socket_.remote_endpoint().address().to_string());

        socket_.close();
    }

    void connection::do_read()
    {

        auto handler = [this, self = shared_from_this()](asio::error_code ec, size_t bytes_transferred)
        {
            if (!ec)
            {
                horus::logger::info("[connection] <{}> reading", socket_.remote_endpoint().address().to_string());

                http::request_parser::result_type result;
                std::tie(result, std::ignore) = request_parser_.parse(request_, buffer_.data(), buffer_.data() + bytes_transferred);

                if (result == http::request_parser::result_type::ok)
                {
                    horus::logger::info("[connection] <{}> [request]:\n{}", socket_.remote_endpoint().address().to_string(), request_.to_string());
                    do_write();
                }
                else if (result == http::request_parser::result_type::error)
                {
                    horus::logger::error("[connection] <{}> [request] bad request", socket_.remote_endpoint().address().to_string());
                    do_write();
                }
                else
                {
                    do_read();
                }
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
        const char response[] =
            "HTTP/1.1 200 OK\r\n"
            "Host: 127.0.0.1:8080\r\n"
            "Content-Type: text/html\r\n"
            "Content-Size: 55\r\n"
            "\r\n"
            "<html><title>It Works!</title><h1>It Works!</h1></html>";

        auto handler = [this, self = shared_from_this()](asio::error_code ec, std::size_t)
        {
            if (!ec)
            {
                horus::logger::info("[connection] <{}> writing", socket_.remote_endpoint().address().to_string());

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
