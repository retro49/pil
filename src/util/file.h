#ifndef __PIL_UTIL_FILE_H
#define __PIL_UTIL_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct File {
    const char *filepath;
    const char *content;
    uint64_t size;
};

struct File *read_file(const char *fullpath);
void close_file(struct File *file);

#endif
