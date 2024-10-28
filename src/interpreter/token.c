#include <stdlib.h>

#include "pil.h"

#define RETURN_THIS(KIND, EXPR)\
    case KIND:\
    return EXPR;

const char *token_type_to_string(enum TokenKind kind)
{
    switch(kind) {
        RETURN_THIS(TOKEN_EOF,          "EOF");
        RETURN_THIS(TOKEN_INVALID,      "INVALID");

        RETURN_THIS(TOKEN_EXCL,         "!");
        RETURN_THIS(TOKEN_MOD,          "%");
        RETURN_THIS(TOKEN_CARET,        "^");
        RETURN_THIS(TOKEN_AMP,          "&");
        RETURN_THIS(TOKEN_ASTERISK,     "*"); 
        RETURN_THIS(TOKEN_LEFT_PAR,     "(");
        RETURN_THIS(TOKEN_RIGHT_PAR,    ")");
        RETURN_THIS(TOKEN_MINUS,        "-");
        RETURN_THIS(TOKEN_PLUS,         "+");
        RETURN_THIS(TOKEN_EQ,           "="); 
        RETURN_THIS(TOKEN_LEFT_SQUARE,  "[");
        RETURN_THIS(TOKEN_RIGHT_SQUARE, "]");
        RETURN_THIS(TOKEN_LEFT_CURLY,   "{");
        RETURN_THIS(TOKEN_RIGHT_CURLY,  "}");
        RETURN_THIS(TOKEN_QUOTE,        "'");
        RETURN_THIS(TOKEN_DQUOTE,       "\"");
        RETURN_THIS(TOKEN_BAR,          "|");
        RETURN_THIS(TOKEN_SLASH,        "/");
        RETURN_THIS(TOKEN_SEMICOLON,    ";");
        RETURN_THIS(TOKEN_LT,           "<");
        RETURN_THIS(TOKEN_GT,           ">");
        RETURN_THIS(TOKEN_DOT,          ".");
        RETURN_THIS(TOKEN_QUESTION,     "?");
        RETURN_THIS(TOKEN_COMMA,        ",");

        RETURN_THIS(TOKEN_PROC,         "proc");
        RETURN_THIS(TOKEN_IF,           "if");
        RETURN_THIS(TOKEN_ELSE,         "else");
        RETURN_THIS(TOKEN_OR,           "or");
        RETURN_THIS(TOKEN_AND,          "and");
        RETURN_THIS(TOKEN_NOT,          "not");
        RETURN_THIS(TOKEN_STRUCT,       "struct");
        RETURN_THIS(TOKEN_ENUM,         "enum");
        RETURN_THIS(TOKEN_UNION,        "union");
        RETURN_THIS(TOKEN_CASE,         "case");
        RETURN_THIS(TOKEN_OF,           "of");
        RETURN_THIS(TOKEN_OTHERWISE,    "otherwise");
        RETURN_THIS(TOKEN_RETURN,       "return");
        RETURN_THIS(TOKEN_WHILE,        "while");

        RETURN_THIS(TOKEN_BOOL,         "bool");
        RETURN_THIS(TOKEN_BYTE,         "i8");
        RETURN_THIS(TOKEN_WORD,         "i16");
        RETURN_THIS(TOKEN_DWORD,        "i32");
        RETURN_THIS(TOKEN_QWORD,        "i64");
        RETURN_THIS(TOKEN_UBYTE,        "u8");
        RETURN_THIS(TOKEN_UWORD,        "u16");
        RETURN_THIS(TOKEN_UDWORD,       "u32");
        RETURN_THIS(TOKEN_UQWORD,       "u64");
        RETURN_THIS(TOKEN_VOID,         "void");
        RETURN_THIS(TOKEN_FLOAT,        "f32");
        RETURN_THIS(TOKEN_DOUBLE,       "f64");
        RETURN_THIS(TOKEN_TRUE,         "true");
        RETURN_THIS(TOKEN_FALSE,        "false");

        RETURN_THIS(TOKEN_LTE,          "<=");
        RETURN_THIS(TOKEN_GTE,          ">=");
        RETURN_THIS(TOKEN_EQEQ,         "==");
        RETURN_THIS(TOKEN_NE,           "!=");

        RETURN_THIS(TOKEN_IDENTIFIER, "IDENTIFIER");
    }

    UNREACHABLE("UNKOWN TOKEN KIND");
}
