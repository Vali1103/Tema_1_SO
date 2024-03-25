// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

#define SYS_ftruncate 77

int ftruncate(int fd, off_t length)
{
    if (length < 0) {
        errno = EINVAL;
        return -1;
    }

    int result = syscall(SYS_ftruncate, fd, length);

    if (result < 0) {
        errno = -result;
        return -1;
    }
	/* TODO: Implement ftruncate(). */
    return 0;
}





