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

#include "logger.hpp"

int main(int argc, char **argv)
{
    horus::logger::init("server");

    horus::logger::info("Horus Web Server {}", "v1.0.0");
    return 0;
}
