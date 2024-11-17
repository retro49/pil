#ifndef __PIL_PIL_H
#define __PIL_PIL_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "enums.h"
#include "../util/panic.h"
#include "../util/file.h"
#include "../util/log.h"
#include "../util/unreachable.h"

typedef struct PilContext PilContext;

typedef enum PilState {
    PIL_STATE_INIT,
    PIL_STATE_LEX,
    PIL_STATE_PARSING,
    PIL_STATE_DEINIT,
}PilState;

struct PilContext {
    PilState state;
    Log logger;
    File logfile;
};

void pil_context_init();
void pil_context_deinit();
void pil_context_set_log_file(const char *p);

#define PIL_DEFAULT_LOG_STREAM          stderr
#define PIL_DEFAULT_LOG_STREAM_ID       0
#define PIL_NON_DEFAULT_LOG_STREAM_ID   1

void pil_log(LogLevel, const char *);
void pil_info(const char *);


typedef uint64_t Position;
typedef uint64_t Line;
typedef uint64_t Column;

typedef struct SourceSpan SourceSpan;
typedef struct Token Token;
typedef struct Lexer Lexer;

struct SourceSpan {
    const char *str;
    uint32_t from;
    uint32_t to;
};

struct TokenData {
    union {
        struct {
            char *string;
            size_t string_len;
        };
    };
};

struct Token {
    enum TokenKind kind;
    uint32_t line;
    uint32_t column;
    struct SourceSpan span;
};

struct Lexer {
    File *file;
    Position pos;
    Line line;
    Column column;
    char ch;
    Token token;
    struct TokenData data;
};

const char *token_type_to_string(enum TokenKind kind);

Lexer *lexer_new(File *f);
Token lexer_next(Lexer *lxr);
void lexer_free(Lexer *lxr);

#endif
