#include "src/globals.h"

#include "src/scan.h"
#include "src/util.h"

/* allocate global variables */
int lineno = 0;
FILE *source;
FILE *listing;

/* allocate and set tracing flags */
int TraceScan = TRUE;

int main(int argc, char *argv[]) {
    char pgm[120]; /* source code file name */
    if (argc != 2) {
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    strcpy(pgm, argv[1]);
    if (strchr(pgm, '.') == NULL)
        strcat(pgm, ".tny");
    source = fopen(pgm, "r");
    if (source == NULL) {
        fprintf(stderr, "File %s not found\n", pgm);
        exit(1);
    }
    listing = stdout; /* send listing to screen */
    fprintf(listing, "\nC- COMPILATION: %s\n", pgm);
    while (getToken() != ENDFILE)
        ;
    fclose(source);
    return 0;
}
