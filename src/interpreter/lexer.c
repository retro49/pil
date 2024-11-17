#include "pil.h"

static bool is_ascii_alpha(char ch) { return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ; }
static bool is_ascii_num(char ch) { return ch >= '0' && ch <= '9'; }
static bool is_ascii_whitespace(char ch) { return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\r'; }
static bool is_ascii_newline(char ch) { return ch == '\n' || ch == '\r'; }

static inline void line_column_check(Lexer *lxr)
{
    if (lxr == NULL)
        return;

    if (is_ascii_newline(lxr->ch)) {
        lxr->line += 1;
        lxr->column = 1;
    } else {
        lxr->column += 1;
    }
}

static void advance(Lexer *lxr)
{
    if(lxr == NULL)
        return;

    if (lxr->pos >= lxr->file->size) {
        lxr->ch = 0;
        return;
    }

    lxr->pos += 1;
    lxr->ch = *(lxr->file->content + lxr->pos);
    line_column_check(lxr);
}

static void abase(Lexer *lxr)
{
    if (lxr == NULL)
        return;
    if (lxr->pos <= 0) return;

    lxr->pos -= 1;
    lxr->ch = *(lxr->file->content + lxr->pos);
    line_column_check(lxr);
}

static bool match(Lexer *lxr, char c)
{
    if (lxr->ch != c)return false;
    advance(lxr);
    return true;
}

static void skip_whitespace(Lexer *lxr)
{
    while(is_ascii_whitespace(lxr->ch)) {
        advance(lxr);
    }
}

static void skip_line_comment(Lexer *lxr)
{
    if (match(lxr, '/')) {
        if(match(lxr, '/')) {
            while ((!is_ascii_newline(lxr->ch)) && lxr->ch != 0) {
                advance(lxr);
            }
        }
    }
}

static char peek(Lexer *lxr)
{
    if ((lxr->pos + 1) >= lxr->file->size) {
        return 0;
    }

    return *(lxr->file->content + (lxr->pos + 1));
}

Lexer *lexer_new(File *f)
{
    if (f == NULL)
        return NULL;

    Lexer *l = NULL;
    l = malloc(sizeof(Lexer));
    if (l == NULL)
        return NULL;

    l->file = f;
    l->pos = 0;
    l->line = 0;
    l->column = 0;

    if (l->file->size <= 0) {
        l->ch = 0;
    } else {
        if (l->file->content == NULL && l->file->size != 0) {
            pil_log(LOG_ERR, "unable to get file content ");
            if (l->file->filepath != NULL)
                pil_log(LOG_ERR, l->file->filepath);
        } else {
            l->ch = *(l->file->content);
        }
    }

    return l;
}

static Token create_token(Lexer *lxr, enum TokenKind kind)
{
    // TODO: source span implementation in lexer
    Token tkn;
    tkn.kind = kind;
    tkn.line = lxr->line;
    tkn.column = lxr->column;

    return tkn;
}

Token lexer_next(Lexer *lxr)
{
    if (lxr == NULL) {
        pil_log(LOG_ERR, "lexer cannot be null");
        UNREACHABLE("lexer cannot be null");
    }

    Token tkn = {0};
    switch(lxr->ch) {
        case 0:
        case '+':
            break;
    }

    return tkn;
}

void lexer_free(Lexer *lxr)
{
    if (lxr == NULL)
        return;

    if (lxr->file != NULL)
        close_file(lxr->file);
        
    free(lxr);
}
