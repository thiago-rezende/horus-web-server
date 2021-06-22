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

#include "logger.hpp"

#include <asio/io_context.hpp>

int main(int argc, char **argv)
{
    horus::logger::init("server");

    horus::logger::info("Horus Web Server {}", "v1.0.0");

    asio::io_context context;

    context.run();

    return 0;
}
