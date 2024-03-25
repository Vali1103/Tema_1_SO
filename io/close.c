// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

#define SYS_close 2

static int process_error(int ret) {
    if (ret == -1) {
        errno = -ret;
        return -1;
    }
    return 0;
}

int close(int fd)
{
    int syscall_result = syscall(SYS_close, fd);
    return process_error(syscall_result);
	/* TODO: Implement close(). */
}
