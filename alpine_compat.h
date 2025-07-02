#ifndef ALPINE_COMPAT_H
#define ALPINE_COMPAT_H

#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

// Define error() function for Alpine/musl compatibility
static inline void error(int status, int errnum, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    if (errnum != 0) {
        fprintf(stderr, ": %s", strerror(errnum));
    }
    fprintf(stderr, "\n");
    if (status != 0) {
        exit(status);
    }
}

// Define umask_t for Alpine compatibility
typedef mode_t umask_t;

#endif // ALPINE_COMPAT_H 