// puts.c creat de mine
#include <unistd.h>

#ifndef STDOUT_FILENO
#define STDOUT_FILENO 1
#endif

int puts(const char *str) {
    size_t len = 0;
    const char *s = str;
    while (*s++) len++;

    write(STDOUT_FILENO, str, len);

    write(STDOUT_FILENO, "\n", 1);

    return len + 1;
}
