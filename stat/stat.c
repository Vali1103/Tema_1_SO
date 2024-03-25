// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

#define SYS_stat 4

int stat(const char *restrict path, struct stat *restrict buf)
{
    if (!path || !buf) {
        errno = EINVAL;
        return -1;
    }

    long result = syscall(SYS_stat, path, buf);

    if (result < 0) {
        errno = -result;
        return -1;
    }
	/* TODO: Implement stat(). */
    return 0;
}
