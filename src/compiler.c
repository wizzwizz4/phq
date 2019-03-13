#include <stdlib.h>
#include <stddef.h>
#include "opcodes.h"

typedef char * (*compiler_func)(const char **restrict source,
                                  char *restrict compiled,
                                  size_t *restrict offset);

/* "".join(map(choice,[ascii_lowercase]*3)) */
#define _pwi_offset_inc(x) do{\
  *offset += (x);                                                           \
  compiled = (char *)realloc(compiled - *offset + (x), *offset) + *offset; \
}while(0)
#define _vvi_call(x) do{\
  compiled = (x)(source, compiled, offset) + *offset; \
}while(0)

char * compile_compile(const char **restrict source,
                       char *restrict compiled, size_t *restrict offset);

char * compile(const char *source) {
    size_t offset = 0;
    return compile_compile(&source, NULL, &offset);
}

char * compile_compile(const char **restrict source,
                       char *restrict compiled, size_t *restrict offset) {
    /* deal with NULL */
    compiled = (char *)realloc(compiled - *offset, *offset) + *offset;

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
        _pwi_offset_inc(1);
        compiled[-1] = FUNCTION_BLOCK;
        _vvi_call(compile_compile);
        _pwi_offset_inc(1);
        compiled[-1] = END_BLOCK;
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
    } while (*++*source && **source != '}');
    compiled = (char *)realloc(compiled - *offset, *offset + 1) + *offset;
    compiled[0] = '\0';
    return compiled - *offset;
}


char * compile_varname_table(const char **restrict source,
                             char *restrict compiled,
                             size_t *restrict offset) {
    do {
        switch (0[*source]) {
            case '$':
                break;
            default:
                goto _compiler_compile_varname_table_outer_loop_end;
        }
    } while (*++*source && **source != '}');
    _compiler_compile_varname_table_outer_loop_end:
    return compiled - *offset;
}

#undef _pwi_offset_inc
#undef _vvi_call
