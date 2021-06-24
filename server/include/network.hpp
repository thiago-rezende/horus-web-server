/**
 * @file network.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Commond network include
 * @version 0.1
 * @date 2021-06-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#ifdef _WIN32
#define _WIN32_WINNT 0x0A00 // Windows 10
#endif

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
