// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

#define SYS_truncate 76

int truncate(const char *path, off_t length)
{
    if (length < 0) {
        errno = EINVAL;
        return -1;
    }

    int result = syscall(SYS_truncate, path, length);

    if (result < 0) {
        errno = -result;
        return -1;
    }
	/* TODO: Implement truncate(). */
    return 0;
}
