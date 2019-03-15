#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "opcodes.h"

typedef char * (*compiler_func)(const char *restrict *const restrict source,
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

char * compile_compile(const char *restrict *const restrict source,
                       char *restrict compiled, size_t *restrict offset);
char * compile_varname_table(const char *restrict *const restrict source,
                             char *restrict compiled,
                             size_t *restrict offset);

char * compile_varname(const char *restrict *const restrict source);

char * compile(const char *restrict source) {
    size_t offset = 0;
    return compile_compile(&source, NULL, &offset);
}

char * compile_compile(const char *restrict *const restrict source,
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
        _vvi_call(compile_varname_table);
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


char * compile_varname_table(const char *restrict *const restrict source,
                             char *restrict compiled,
                             size_t *restrict offset) {
    _pwi_offset_inc(1);
    compiled[-1] = VNMTAB;

    size_t varname_count = 0;
    const char **varname_list = NULL;
    do {
        switch (0[*source]) {
            case '$': {
                const char *new_source = *source;
                const char *new_varname = compile_varname(&new_source);
                if (*new_source != ';') {
                    free((void *)new_varname);
                    goto _compiler_compile_varname_table_outer_loop_end;
                }
                *source = new_source + 1; /* skip ; */
                varname_count += 1;
                varname_list = realloc(varname_list,
                                       sizeof(*varname_list) * varname_count);
                varname_list[varname_count - 1] = new_varname;
                break;
            }
            default:
                goto _compiler_compile_varname_table_outer_loop_end;
        }
    } while (*++*source && **source != '}');
    _compiler_compile_varname_table_outer_loop_end:

    if (varname_count) {
        free((void *)varname_list[0]);
        while (--varname_count) {
            free((void *)varname_count[varname_list]);
        }
    }
    free(varname_list);
    return compiled - *offset;
}

char * compile_varname(const char *restrict *const restrict source) {
    if (**source != '$') {
        return NULL;
    }
    *source += 1;

    size_t buffer_size = 1;
    size_t buffer_index = -1;
    char *buffer = malloc(1);
    do {
        if (++buffer_index > buffer_size) {
            buffer = realloc(buffer, buffer_size<<=1);
        }
        switch (**source) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':

            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':

            case '_':

            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                /* copy the thing */
                buffer[buffer_index] = **source;
                break;
            default:
                goto _compiler_compile_varname_outer_loop_end;
        }
    } while (*++*source && **source != '}');
    _compiler_compile_varname_outer_loop_end:
    *source -= 1;  /* do not consume next chaacter */
    return buffer;
}

#undef _pwi_offset_inc
#undef _vvi_call
