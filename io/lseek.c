// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
    off_t res = syscall(__NR_lseek, fd, offset, whence);

    if (res < 0)
    {
        errno = -res;
        return (off_t)-1;
    }

    return res;
}
