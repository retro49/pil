#ifndef __PIL_PIL_H
#define __PIL_PIL_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "../util/panic.h"
#include "../util/file.h"
#include "../util/unreachable.h"

typedef uint64_t Indicator;
typedef uint64_t Line;
typedef uint64_t Row;

enum TokenKind {
    TOKEN_EOF,
    TOKEN_INVALID,

    TOKEN_EXCL,         //  !
    TOKEN_MOD,          //  %
    TOKEN_CARET,        //  ^
    TOKEN_AMP,          //  &
    TOKEN_ASTERISK,     //  *
    TOKEN_LEFT_PAR,     //  (
    TOKEN_RIGHT_PAR,    //  )
    TOKEN_MINUS,        //  -
    TOKEN_PLUS,         //  +
    TOKEN_EQ,           //  = 
    TOKEN_LEFT_SQUARE,  //  [
    TOKEN_RIGHT_SQUARE, //  ]
    TOKEN_LEFT_CURLY,   //  {
    TOKEN_RIGHT_CURLY,  //  }
    TOKEN_QUOTE,        //  '
    TOKEN_DQUOTE,       //  "
    TOKEN_BAR,          //  |
    TOKEN_SLASH,        //  /
    TOKEN_SEMICOLON,    //  ;
    TOKEN_LT,           //  <
    TOKEN_GT,           //  >
    TOKEN_DOT,          //  .
    TOKEN_QUESTION,     //  ?
    TOKEN_COMMA,        //  ,


    TOKEN_PROC = 256,       // proc
    TOKEN_IF,               // if
    TOKEN_ELSE,             // else
    TOKEN_OR,               // or
    TOKEN_AND,              // and
    TOKEN_NOT,              // not
    TOKEN_STRUCT,           // struct
    TOKEN_ENUM,             // enum
    TOKEN_UNION,            // union
    TOKEN_CASE,             // case
    TOKEN_OF,               // of
    TOKEN_OTHERWISE,        // otherwise
    TOKEN_RETURN,           // return
    TOKEN_WHILE,            // while

    TOKEN_BOOL,             // bool
    TOKEN_BYTE,             // i8
    TOKEN_WORD,             // i16
    TOKEN_DWORD,            // i32
    TOKEN_QWORD,            // i64

    TOKEN_UBYTE,            // u8
    TOKEN_UWORD,            // u16
    TOKEN_UDWORD,           // u32
    TOKEN_UQWORD,           // u64
    TOKEN_VOID,             // void
    TOKEN_FLOAT,            // f32
    TOKEN_DOUBLE,           // f64
    TOKEN_TRUE,             // true
    TOKEN_FALSE,            // false
    
    TOKEN_LTE,              // <=
    TOKEN_GTE,              // >=
    TOKEN_EQEQ,             // ==
    TOKEN_NE,               // !=

    TOKEN_IDENTIFIER,
};

struct SourceSpan {
    const char *str;
    uint32_t from;
    uint32_t to;
};

struct Token {
    enum TokenKind kind;
    uint32_t line;
    uint32_t column;
    struct SourceSpan span;
};

struct Lexer {
    File *file;
    Indicator indicator;
    Line line;
    Row row;
    char ch;
};

const char *token_type_to_string(enum TokenKind kind);

#endif
