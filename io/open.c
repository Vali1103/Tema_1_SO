// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

#define SYS_open 2

static int handle_error(int ret) {
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return ret;
}

int open(const char *filename, int flags, ...)
{
    int result = syscall(SYS_open, filename, flags);

	/* TODO: Implement open system call. */
    return handle_error(result);
}
