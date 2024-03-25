// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

#define SYS_fstat 5

int fstat(int fd, struct stat *st)
{
    if (fd < 0 || !st) {
        errno = EINVAL;
        return -1;
    }

    long result = syscall(SYS_fstat, fd, st);


    if (result < 0) {
        errno = -result;
        return -1;
    }
	/* TODO: Implement fstat(). */
    return 0;
}
