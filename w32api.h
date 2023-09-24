/**
 * @file w32api.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-24
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef W32API_H
#define W32API_H

#include <windows.h>
void w32apiFunction()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written;
    WriteConsoleA(handle, "Hello World!\n", 13, &written, NULL);
}

#endif
