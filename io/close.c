// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	int id = syscall(__NR_close, fd);
	if (id < 0) {
		errno = -id;
		return  -1;
	}

	return id;
}
