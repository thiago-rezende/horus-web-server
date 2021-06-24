/**
 * @file connection_manager.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Connection manager class
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <set>
#include "connection.hpp"

namespace horus
{
    class connection_manager
    {
    private:
        std::set<connection_ptr> connections_;

    public:
        connection_manager() = default;
        ~connection_manager() = default;

        void start(connection_ptr conn);
        void stop(connection_ptr conn);

        void stop_all();

    public:
        connection_manager(const connection_manager &) = delete;
        connection_manager(const connection_manager &&) = delete;

        connection_manager &operator=(const connection_manager &) = delete;
        connection_manager &operator=(const connection_manager &&) = delete;
    };
} // namespace horus
