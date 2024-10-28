#ifndef __PIL_UTIL_PANIC_H
#define __PIL_UTIL_PANIC_H

#include <stdio.h>

#define PANIC(WHY, CODE)\
    printf("[file] %s [line] %d,  panic: %s\n", __FILE__, __LINE__, WHY);\
    exit(CODE);

#endif
