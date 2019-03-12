#include <stdlib.h>
#include <stddef.h>
#include "opcodes.h"

char * compile_compile(const char **restrict source,
                       char *restrict compiled, size_t *restrict offset);

char * compile(const char *source) {
    size_t offset = 0;
    return compile_compile(&source, NULL, &offset);
}

char * compile_compile(const char **restrict source,
                       char *restrict compiled, size_t *restrict offset) {
    /* deal with NULL */
    compiled = realloc(compiled - *offset, *offset);

    do {
        switch (0[*source]) {
            case 'f':
                switch (1[*source]) {
                    case 'u':
                        switch (2[*source]) {
                            case 'n':
                                switch (3[*source]) {
                                    case 'c':
                                        switch (4[*source]) {
                                            case 't':
                                                switch (5[*source]) {
                                                    case 'i':
                                                        switch (6[*source]) {
                                                            case 'o':
switch (7[*source]) {
    case 'n':
        *source += 7;
        *offset += 1;
        compiled = realloc(compiled - *offset + 1, *offset) + *offset;
        *compiled = FUNCTION_BLOCK;
        compiled = compile_compile(source, compiled, offset);
        *offset += 1;
        compiled = realloc(compiled - *offset + 1, *offset) + *offset;
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
