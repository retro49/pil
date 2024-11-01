#include "pil.h"

struct Lexer *lexer_new(File *f)
{
    if (f == NULL)
        return NULL;

    struct Lexer *l = NULL;
    l = malloc(sizeof(struct Lexer));
    if (l == NULL)
        return NULL;

    l->file = f;
    l->indicator = 0;
    l->line = 0;
    l->row = 0;
    if (l->file->size <= 0) {
        l->ch = 0;
    } else {
        if (l->file->content == NULL && l->file->size != 0) {
            // UNREACHABLE("undefined behaviour with file")
        } else {
            l->ch = *(l->file->content);
        }
    }

    return l;
}
