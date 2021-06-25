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

#include <cxxopts.hpp>

#include "utils/platform_detection.hpp"
#include "utils/path.hpp"
#include "network.hpp"
#include "logger.hpp"
#include "server.hpp"

int main(int argc, char **argv)
{
    cxxopts::Options options("horus-web-server", "Simple and (not yet) configurable web server written in C++");

    options.add_options("", {{"port", "port number", cxxopts::value<uint16_t>()->default_value("8080")},
                             {"doc", "document root", cxxopts::value<std::string>()->default_value((horus::utils::get_executable_dir().parent_path() / "share" / "horus-www").string())},
                             {"h,help", "print help"}});

    try
    {
        cxxopts::ParseResult options_result = options.parse(argc, argv);

        if (options_result.count("help"))
        {
            std::cout << options.help() << std::endl;
            return 0;
        }

        horus::logger::init();

        horus::logger::info("Horus Web Server {}", "v0.1.0");

        asio::io_context context;

        std::filesystem::path document_root = options_result["doc"].as<std::string>();

        bool document_root_exists = std::filesystem::exists(document_root);

        if (!document_root_exists)
        {
            horus::logger::error("document root not found: \"{}\"", document_root.string());
            return 1;
        }

        horus::logger::info("[server] document root: {}", document_root.string());

        horus::server server(context, options_result["port"].as<uint16_t>(), document_root);
        server.run();
    }
    catch (const std::exception &e)
    {
        horus::logger::error("[exception]: {}", e.what());
    }

    return 0;
}
