#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"

int main(int argc, char *argv[]) {
    /* highest quality argument parsing */
    for (int argi = 0; argi < argc; argi += 1) {
        switch (argv[argi][0]) {
            case '-':
                switch (argv[argi][1]) {
                    case '-':
                        switch (argv[argi][2]) {
                            case 'c':
                                switch (argv[argi][3]) {
                                    case 'o':
                                        switch (argv[argi][4]) {
                                            case 'm':
                                                switch (argv[argi][5]) {
                                                    case 'p':
                                                        switch (argv[argi]
                                                                [6]) {
                                                            case 'i':
switch (argv[argi][7]) {
    case 'l':
        switch (argv[argi][8]) {
            case 'e':
                switch (argv[argi][9]) {
                    case '=': {
                        size_t size = 1;
                        char *buffer = NULL;
                        register size_t no_read;
                        do {
                            buffer = realloc(buffer, size<<=1);
                            FILE *restrict f = fopen(argv[argi]+10, "r");
                            no_read = fread(buffer, sizeof(char), size, f);
                        } while (no_read == size);
                        buffer[no_read] = '\0';
                        char * const compiled = compile(buffer);
                        printf("%s", compiled);
                        free(compiled);
                        free(buffer);
                        break;
                    }
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
                            case 'h':
                                switch (argv[argi][3]) {
                                    case 'e':
                                        switch (argv[argi][4]) {
                                            case 'l':
                                                switch (argv[argi][5]) {
                                                    case 'p':
                                                        switch (argv[argi]
                                                                [6]) {
                                                            case '\0':
                                                                goto opt_help;
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
                    case '?':
                        switch (argv[argi][2]) {
                            case '\0':
                            opt_help:
                                printf("Welcome to the PHQ help document!\n"
                                       "PHQ is 1 (one) better than PHP.\n"
                                       "\n"
                                       "Syntax:\n"
                                       "  %s --help\n"
                                       "  %s -?      displays this document\n"
                                       "  %s --compile=filename\n"
                                       "             compiles filename\n"
                                       "That is all.\n",
                                       argv[0], argv[0], argv[0]);
                                break;
                        }
                }
                break;
        }
    }
}
