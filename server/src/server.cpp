#include "server.hpp"
#include "connection.hpp"
#include "logger.hpp"

namespace horus
{
    server::server(asio::io_context &context, uint16_t port, std::filesystem::path document_root)
        : signals_(context),
          context_(context),
          connection_manager_(),
          acceptor_(context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)),
          socket_(context),
          document_root_(document_root)
    {
        horus::logger::info("[server] listening on port {}", port);

        signals_.add(SIGINT);
        signals_.add(SIGTERM);
#if defined(SIGQUIT)
        signals_.add(SIGQUIT);
#endif // defined(SIGQUIT)

        do_await_stop();

        do_async_accept();
    }

    void server::run()
    {
        context_.run();
    }

    void server::do_async_accept()
    {
        auto handler = [&](asio::error_code error)
        {
            if (!acceptor_.is_open())
                return;

            horus::logger::info("[connection] <{}> accepted", socket_.remote_endpoint().address().to_string());

            connection_manager_.start(std::make_shared<connection>(std::move(socket_), connection_manager_));

            do_async_accept();
        };

        acceptor_.async_accept(socket_, handler);
    }

    void server::do_await_stop()
    {
        auto handler = [this](asio::error_code ec, int signo)
        {
            horus::logger::info("[server] stopping");

            acceptor_.close();
            connection_manager_.stop_all();
        };

        signals_.async_wait(handler);
    }
} // namespace horus
