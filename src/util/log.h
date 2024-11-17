#ifndef __PIL_UTIL_LOG_H
#define __PIL_UTIL_LOG_H

#include "file.h"

typedef enum LogLevel {
    LOG_DEBUG,
    LOG_WARN,
    LOG_ERR,
}LogLevel;

typedef void (*pil_log_debug_cb)(File, const char *);
typedef void (*pil_log_warn_cb)(File, const char *);
typedef void (*pil_log_error_cb)(File, const char *);

typedef struct Log {
    pil_log_debug_cb debug;
    pil_log_warn_cb warn;
    pil_log_error_cb error;
}Log;

void pil_log_debug(File, const char *msg);
void pil_log_warn(File, const char *msg);
void pil_log_err(File, const char *msg);

#define PIL_INFO(_FMT, ...)\
    do {\
        printf("[INFO] "); \
        printf(_FMT, ##__VA_ARGS__); \
        printf("\n");\
    }while(0);

#endif
