
#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>


#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define SYS_lseek 8

off_t lseek(int fd, off_t offset, int whence)
{
    if (whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END) {
        errno = EINVAL;
        return (off_t) -1;
    }

    int r = syscall(SYS_lseek, fd, offset, whence);

    if (r < 0) {
        errno = -r;
        return (off_t) -1;
    }
	/* TODO: Implement lseek(). */
    return (off_t)r;
}
