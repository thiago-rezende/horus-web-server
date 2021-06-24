/**
 * @file main.cpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Server entry point
 * @version 0.1
 * @date 2021-06-22
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "network.hpp"
#include "logger.hpp"
#include "server.hpp"

int main(int argc, char **argv)
{
    horus::logger::init();

    horus::logger::info("Horus Web Server {}", "v0.1.0");

    try
    {
        asio::io_context context;

        horus::server server(context, 8080);
        server.run();
    }
    catch (const std::exception &e)
    {
        horus::logger::error("[exception]: {}", e.what());
    }

    return 0;
}
