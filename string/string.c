// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int count = 0;
	while(*source) {
		*destination = *source;
		source++;
		destination++;
		count++;
	}

	*destination = '\0';
	destination -= count;

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t count = 0;
	while(count < len && *source) {
		*destination = *source;
		destination++;
		source++;
		count++;
	}

	while(count < len) {
		*destination = '\0';
		destination++;
		count++;
	}

	destination -= count;

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int count = 0;
	while(*destination){
		destination++;
		count++;
	}
	while(*source){
		*destination = *source;
		destination++;
		source++;
		count++;
	}
	*destination = '\0';
	destination -= count;
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int count = 0;
	int count2 = 0;
	while(*destination){
		destination++;
		count++;
	}
	while((size_t)count2 < len && *source){
		*destination = *source;
		destination++;
		source++;
		count++;
		count2++;
	}
	*destination = '\0';
	destination -= count;
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    if (*str1 < *str2)
        return -1;
    else if (*str1 > *str2)
        return 1;
    return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
    size_t count = 0;
    while (count < len && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
        count++;
    }
    if (count == len)
        return 0;
    if (*str1 < *str2)
        return -1;
    else if (*str1 > *str2)
        return 1;
    return 0;
}


size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str) {
        if (*str == (char)c) {
            return (char *)str;
        }
        str++;
    }

    if (c == '\0') {
        return (char *)str;
    }
	/* TODO: Implement strchr(). */
	return NULL;
}

char *strrchr(const char *str, int c)
{
	int count = 0;
	while (*str){
		str++;
		count++;
	}
	if (c == '\0') {
        return (char *)str;
    }
	while (count > 0){
		str--;
		if(*str == (char)c)
			return (char *)str;
		count--;
	}

	/* TODO: Implement strrchr(). */
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
    if (!*needle)
		return (char *)haystack;

    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (!*n) {
            return (char *)haystack;
        }
		haystack++;
    }
	/* TODO: Implement strstr(). */
    return NULL;
}


char *strrstr(const char *haystack, const char *needle)
{
	if (!*needle)
		return (char *)haystack;

    char *last_occurrence = NULL;

    while (*haystack) {
        char *h = (char *)haystack;
        char *n = (char *)needle;

        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }

        if (!*n) {
            last_occurrence = (char *)haystack;
        }

        haystack++;
    }

    return last_occurrence;
	/* TODO: Implement strrstr(). */
}

void *memcpy(void *destination, const void *source, size_t num)
{
	for (size_t i = 0; i < num; i++) {
        ((char *) destination)[i] = ((char *)source)[i];
    }

    return destination;
	/* TODO: Implement memcpy(). */
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest = (char *)destination;
    char *src = (char *)source;

    if (src < dest && dest < src + num) {
        for (size_t i = num; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    } else {
        for (size_t i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    }
	/* TODO: Implement memmove(). */
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	char *p1 = (char *)ptr1;
    char *p2 = (char *)ptr2;

    for (size_t i = 0; i < num; i++) {
        if (p1[i] < p2[i]) return -1;
        if (p1[i] > p2[i]) return 1;
    }

	/* TODO: Implement memcmp(). */
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *ptr = (char *)source;

    for (size_t i = 0; i < num; i++) {
        ptr[i] = (char)value;
    }
	/* TODO: Implement memset(). */
	return source;
}
