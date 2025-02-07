// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
    int fd;
    int mode = 0;

    if (flags & O_CREAT)
    {
        va_list args;
        va_start(args, flags);
        mode = va_arg(args, int);
        va_end(args);
    }

    if (mode > 0)
    {
        fd = syscall(__NR_open, filename, flags, mode);
    } else {
        fd = syscall(__NR_open, filename, flags);
    }

    if (fd < 0)
    {
        errno = -fd;
        return -1;
    }

    return fd;
}
