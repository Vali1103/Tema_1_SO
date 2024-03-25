// process/nanosleep.c
#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

#define SYS_nanosleep 35
#define NULL ((void *)0)

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int result = syscall(SYS_nanosleep, req, rem);

    if (result == -1) {
        errno = -result;
        return -1;
    }
    return 0;
}

unsigned int sleep(unsigned int seconds) {
    struct timespec req = { .tv_sec = seconds, .tv_nsec = 0 };
    if (nanosleep(&req, NULL) == -1) {
        return seconds - (req.tv_sec + (req.tv_nsec > 0 ? 1 : 0));
    }
    return 0;
}
