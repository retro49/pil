#include "pil.h"

static File pil_stdout;
static File pil_stderr;
static File pil_stdin;
static PilContext  pil_context;
static uint8_t     pil_context_log_id = PIL_DEFAULT_LOG_STREAM_ID;


static void pil_log_debug(const char *msg)
{
    if (msg == NULL)
        return;
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    fprintf(pil_context.logfile.__file, "%4d/%02d/%02d %02d:%02d:%02d [debug] %s\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, msg);
}

static void pil_log_warn(const char *msg)
{
    if (msg == NULL)
        return;

    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    fprintf(pil_context.logfile.__file, "%4d/%02d/%02d %02d:%02d:%02d [warn]  %s\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, msg);
}

static void pil_log_err(const char *msg)
{
    if (msg == NULL)
        return;

    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    fprintf(pil_context.logfile.__file, "%4d/%02d/%02d %02d:%02d:%02d [error] %s\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, msg);
}

void pil_context_init()
{
    File psout =  {.__file = stdout, .filepath= NULL, .content= NULL, .size = 0};
    pil_stdout = psout;
    File pserr = {.__file = stderr, .filepath = NULL, .content = NULL, .size = 0};
    pil_stderr = pserr;
    File psin = {.__file = stdin, .filepath = NULL, .content = NULL, .size = 0};
    pil_stdin = psin;

    pil_context_log_id = PIL_DEFAULT_LOG_STREAM_ID;
    pil_context.state = PIL_STATE_INIT;
    pil_context.logfile = pil_stderr;
    pil_context.logger.debug = pil_log_debug;
    pil_context.logger.warn = pil_log_warn;
    pil_context.logger.error = pil_log_err;
}

void pil_log(LogLevel lvl, const char *msg)
{
    if (lvl == LOG_DEBUG) {
        pil_context.logger.debug(msg);
    } else if (lvl == LOG_WARN) {
        pil_context.logger.warn(msg);
    } else if (lvl == LOG_ERR) {
        pil_context.logger.error(msg);
    } else {
        UNREACHABLE("UNKOWN LOGGING LEVEL")
    }
}

void pil_context_set_log_file(const char *p)
{
    if (p == NULL)
        return;

    FILE *__file = fopen(p, "a+");
    if (__file == NULL)
        return;

    File plf = {.__file = __file, .filepath = p, .content = NULL, .size = 0};
    pil_context.logfile = plf;
    pil_context_log_id = PIL_NON_DEFAULT_LOG_STREAM_ID;
}

void pil_context_deinit()
{
    if (pil_context_log_id != PIL_DEFAULT_LOG_STREAM_ID && 
            pil_context_log_id == PIL_NON_DEFAULT_LOG_STREAM_ID) {
        if (pil_context.logfile.__file != NULL)
            fclose(pil_context.logfile.__file);
    }
}
