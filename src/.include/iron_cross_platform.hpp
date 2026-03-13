/****************************************************************
 * This is a cross platform comprehensive header file, which may *
 * result in low efficiency during compilation. But this will no *
 * -t affect the execution efficiency of binary files            *
 ****************************************************************/

#pragma

#ifndef IRON_CROSS_PLATFORM_HPP
#define IRON_CROSS_PLATFORM_HPP

#ifdef _WIN32 // platform: windows

#include <windows.h>
#include <io.h>
#include <fcntl.h>

#else // platform: linux

#include <unistd.h>

#endif // _WIN32

#endif // IRON_CROSS_PLATFORM_HPP