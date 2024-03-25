// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS MAP_ANON
#endif

#define SIZE_MAX 0xFFFFFFFFU

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
    if (size == 0) {
        return NULL;
    }

    void *mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mem == MAP_FAILED) {
        return NULL;
    }

    return mem;
}


void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;

    if (nmemb != 0 && size != total_size / nmemb) {
        return NULL;
    }

    void *mem = malloc(total_size);
    if (mem == NULL) {
        return NULL;
    }

    memset(mem, 0, total_size);

    return mem;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (!ptr) {
        return;
    }

    size_t *size_ptr = (size_t *)((char *)ptr - sizeof(size_t));
    size_t size = *size_ptr;

    munmap(size_ptr, size + sizeof(size_t));
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (!ptr) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(size);
    if (!new_ptr) {
        return NULL;
    }

    size_t *old_size_ptr = (size_t *)((char *)ptr - sizeof(size_t));
    size_t old_size = *old_size_ptr;

    memcpy(new_ptr, ptr, old_size < size ? old_size : size);

    free(ptr);

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (size && nmemb > SIZE_MAX / size) {
        return NULL;
    }

    size_t total_size = nmemb * size;

    return realloc(ptr, total_size);
}
