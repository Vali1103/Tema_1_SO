// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

#define SYS_mmap 9
#define SYS_mremap 25
#define SYS_munmap 11

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long ret = syscall(SYS_mmap, addr, length, prot, flags, fd, offset);
    if (ret == -1) {
        return MAP_FAILED;
    }
    return (void *)ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long ret = syscall(SYS_mremap, old_address, old_size, new_size, flags);
    if (ret == -1) {
        return MAP_FAILED;
    }
    return (void *)ret;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	return syscall(SYS_munmap, addr, length);
}
