#include <stdio.h>
#include <stdlib.h>

#include "interpreter/pil.h"

int main(int argc, char **argv)
{
    pil_context_init();
    pil_log(LOG_DEBUG, "HOWDY PEOPLE!"); 
    pil_context_deinit();
}
