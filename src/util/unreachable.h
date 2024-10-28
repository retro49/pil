#ifndef __PIL_UTIL_UNREACHABLE_H
#define __PIL_UTIL_UNREACHABLE_H

#include <stdio.h>

#define UNREACHABLE(WHY)\
    printf("[file] %s [line] %d,  unreachable code: %s\n", __FILE__, __LINE__, WHY);\
    exit(1);

#endif
