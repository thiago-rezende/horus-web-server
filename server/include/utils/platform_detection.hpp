/**
 * @file platform_detection.hpp
 * @author Thiago Rezende (horus.he4rt@gmail.com)
 * @brief Platorm detection using predefined macros
 * @version 0.1
 * @date 2021-06-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

/* Check for Windows platform */
#if defined(_WIN32)
#define PLATFORM_WINDOWS
// #error "[platform] Windows platform is not supported!"
/* Windows x64/x86 */
#if defined(_WIN64)
/* Windows x64  */
#define PLATFORM_WINDOWS_64
// #error "[platform] x64 Builds are not supported!"
#else // _WIN64
/* Windows x86 */
#define PLATFORM_WINDOWS_86
#error "[platform] x86 Builds are not supported!"
#endif // _WIN32
/* Check for Apple flatofrms */
#elif defined(__APPLE__) || defined(__MACH__)
#define PLATFORM_APPLE
// #error "[platform] Apple platforms are not supported!"
#include <TargetConditionals.h>
/* TARGET_OS_MAC exists on all the platforms
* so we must check all of them (in this order)
* to ensure that we're running on MAC
* and not some other Apple platform
*/
#if TARGET_IPHONE_SIMULATOR == 1
#define PLATFORM_IOS_SIMULATOR
#error "[platform] IOS simulator is not supported!"
#elif TARGET_OS_IPHONE == 1
#define PLATFORM_IOS
#error "[platform] IOS is not supported!"
#elif TARGET_OS_MAC == 1
#define PLATFORM_MACOS
// #error "[platform] MacOS is not supported!"
#else
#error "[platform] Unknown Apple platform!"
#endif // __APPLE__ || __MACH__
/* We also have to check __ANDROID__ before __linux__
 * since android is based on the linux kernel
 * it has __linux__ defined
 */
#elif defined(__ANDROID__)
#define PLATFORM_ANDROID
#error "[platform] Android is not supported!"
#elif defined(__linux__)
#define PLATFORM_LINUX
// #error "[platform] Linux is not supported!"
#else // __linux__
/* Unknown compiler/platform */
#error "[platform] Unknown platform!"
#endif
