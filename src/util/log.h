#ifndef __PIL_UTIL_LOG_H
#define __PIL_UTIL_LOG_H

typedef enum LogLevel {
    LOG_DEBUG,
    LOG_WARN,
    LOG_ERR,
}LogLevel;

typedef void (*pil_log_debug_cb)(const char *);
typedef void (*pil_log_warn_cb)(const char *);
typedef void (*pil_log_error_cb)(const char *);

typedef struct Log {
    pil_log_debug_cb debug;
    pil_log_warn_cb warn;
    pil_log_error_cb error;
}Log;

#endif
