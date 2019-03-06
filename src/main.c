#include <stdio.h>

int main(int argc, char *argv[]) {
    /* highest quality argument parsing */
    for (int argi = 0; argi < argc; argi += 1) {
        switch (argv[argi][0]) {
            case '-':
                switch (argv[argi][1]) {
                    case '-':
                        switch (argv[argi][2]) {
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
                                       "That is all.\n",
                                       argv[0], argv[0]);
                                break;
                        }
                }
                break;
        }
    }
}
