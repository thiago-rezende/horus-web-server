/**
 * @file main.cpp
 * @author Thiago Rezende (bitrateti@gmail.com)
 * @brief Application entry point
 * @version 0.1
 * @date 2020-06-18
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int main(int argc, char **argv)
{
    std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("core");

    spdlog::set_default_logger(logger);
    spdlog::set_pattern("[%n] [%^%l%$] [thread %t] %v");
    spdlog::set_level(spdlog::level::trace);

    spdlog::trace("Horus Web Server {}", "v1.0.0");
    spdlog::debug("This is a debug message");
    return 0;
}
