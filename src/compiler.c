#include <stdlib.h>
#include <stddef.h>
#include "opcodes.h"

char * compile_compile(const char **source,
                       char *compiled, size_t *offset);

char * compile(const char *source) {
    size_t offset = 0;
    return compile_compile(&source, NULL, &offset);
}

char * compile_compile(const char **source,
                       char *compiled, size_t *offset) {
    /* deal with NULL */
    compiled = realloc(compiled - *offset, *offset);

    do {
        switch (*source[0]) {
            case 'f':
                switch (*source[1]) {
                    case 'u':
                        switch (*source[2]) {
                            case 'n':
                                switch (*source[3]) {
                                    case 'c':
                                        switch (*source[4]) {
                                            case 't':
                                                switch (*source[5]) {
                                                    case 'i':
                                                        switch (*source[6]) {
                                                            case 'o':
switch (*source[7]) {
    case 'n':
        *source += 7;
        compiled = realloc(compiled - *offset, ++*offset) + *offset;
        *compiled = FUNCTION_BLOCK;
        compiled = compile_compile(source, compiled, offset);
        compiled = realloc(compiled - *offset, ++*offset) + *offset;
        *compiled = END_BLOCK;
        break;
}
break;
                                                        }
                                                        break;
                                                }
                                                break;
                                        }
                                        break;
                                }
                                break;
                        }
                        break;
                }
                break;
        }
    } while (*(++*source) && **source != '}');
    return compiled - *offset;
}
