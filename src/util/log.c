#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "log.h"

void pil_log_debug(File file, const char *msg)
{
    if (msg == NULL)
        return;

    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    fprintf(file.__file, "%4d/%02d/%02d %02d:%02d:%02d [debug] %s\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, msg);
}

void pil_log_warn(File file, const char *msg)
{
    if (msg == NULL)
        return;

    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    fprintf(file.__file, "%4d/%02d/%02d %02d:%02d:%02d [warn]  %s\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, msg);
}

void pil_log_err(File file, const char *msg)
{
    if (msg == NULL)
        return;

    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    fprintf(file.__file, "%4d/%02d/%02d %02d:%02d:%02d [error] %s\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, msg);
}
