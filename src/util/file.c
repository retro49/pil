#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "file.h"
#include "panic.h"

struct File *read_file(const char *fullpath)
{
    if (fullpath == NULL)
        return NULL;

    struct File *file = (struct File*)malloc(sizeof(struct File));
    if (file == NULL)
        return NULL;

    memset(file, 0, sizeof(struct File));
    file->filepath = fullpath;

#ifdef _WIN32
#include <Windows.h>
    HANDLE hFile;
    hFile  = CreateFile(file->fullpath, FILE_READ_DATA, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        goto __failure;

    LARGE_INTEGER fileSize;
    if (GetFileSize(hFile, &fileSize) == 0) {
        CloseHandle(hFile);
        goto __failure;
    }
    CloseHandle(hFile);
    file->size = fileSize.QuadPart;
#else
#include <sys/stat.h>
    struct stat sb;
    if (stat(file->filepath, &sb) == -1)
        goto __failure;
    file->size  = sb.st_size;
#endif

    if (file->size <= 0) {
        file->content = NULL;
        return file;
    }

    char *buffer = (char*)malloc(sizeof(char) * file->size);
    if (buffer == NULL) {
        if (file != NULL)
            free(file);

        PANIC("UNABLE TO ALLOCATE FILE BUFFER", 1);
    }

    FILE *__file = fopen(file->filepath, "r");
    if (__file == NULL) {
        // LOG WHY
        goto __failure;
    }

    fread(buffer, sizeof(char), file->size, __file);
    file->content = buffer;
    file->__file = __file;

    return file;

__failure:
    if (buffer != NULL)
        free(buffer);

    if (__file != NULL)
        fclose(__file);

    if (file != NULL)
        free(file);
    return NULL;
}

void  close_file(struct File *file)
{
    if (file == NULL)
        return;

    if (file->__file != NULL)
        fclose(file->__file);

    if (file->content != NULL)
        free((char*)file->content);

    free(file);
}
