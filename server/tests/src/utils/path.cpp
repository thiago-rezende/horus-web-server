/**
 * @file path.cpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Path utils test
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

#include "utils/path.hpp"

int main()
{
    std::filesystem::path executable_dir = horus::utils::get_executable_dir();

    bool dir_exists = std::filesystem::exists(executable_dir);

    if (!dir_exists)
    {
        std::cerr << "[test] [failed] <path> get executable dir" << std::endl;
        return 1;
    }

    std::cout << "[test] [success] <path> get executable dir" << std::endl;
    return 0;
}
