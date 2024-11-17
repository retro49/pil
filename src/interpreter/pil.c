#include "pil.h"

static PilContext pil_context;
static File pil_stdout;
static File pil_stderr;
static File pil_stdin;
static uint8_t pil_context_log_id = PIL_DEFAULT_LOG_STREAM_ID;

void pil_context_init()
{
    File psout =  (File){.__file = stdout, .filepath= NULL, .content= NULL, .size = 0};
    pil_stdout = psout;
    File pserr = (File){.__file = stderr, .filepath = NULL, .content = NULL, .size = 0};
    pil_stderr = pserr;
    File psin = (File){.__file = stdin, .filepath = NULL, .content = NULL, .size = 0};
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
        pil_context.logger.debug(pil_context.logfile, msg);
    } else if (lvl == LOG_WARN) {
        pil_context.logger.warn(pil_context.logfile, msg);
    } else if (lvl == LOG_ERR) {
        pil_context.logger.error(pil_context.logfile, msg);
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
