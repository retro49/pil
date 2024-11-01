#ifndef __PIL_UTIL_FILE_H
#define __PIL_UTIL_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct File {
    FILE *__file;
    const char *filepath;
    const char *content;
    uint64_t size;
}File;

struct File *read_file(const char *fullpath);
void close_file(struct File *file);
#endif
