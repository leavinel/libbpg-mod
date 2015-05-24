/**
 * @file
 * Debug printf() for Windows platforem
 * @author Leav Wu (leavinel@gmail.com)
 */
#ifndef _DPRINTF_H_
#define _DPRINTF_H_

#include <stdio.h>

#ifdef _WIN32
#include <stdarg.h>
#include <windows.h>

#ifdef __GNUC__
static void dprintf (const char s_fmt[], ...) __attribute__((format(printf, 1, 2)));
#endif // __GNUC__

static void dprintf (const char s_fmt[], ...)
{
    char buf[128];
    va_list ap;

    va_start (ap, s_fmt);
    vsnprintf (buf, sizeof(buf), s_fmt, ap);
    va_end (ap);

    OutputDebugStringA (buf);
}


#else // WIN32
#define dprintf(s_fmt, ...)     fprintf (stderr, s_fmt, __VA_ARGS__)
#endif // WIN32


#endif /* _DPRINTF_H_ */
