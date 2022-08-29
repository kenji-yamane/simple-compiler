#include "../../src/globals.h"

#include "../../src/scan.h"
#include "../../src/util.h"

/* allocate global variables */
int lineno = 0;
FILE *source;
FILE *listing;

/* allocate and set tracing flags */
int TraceScan = TRUE;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <input-filename> <output-filename>",
                argv[0]);
        fprintf(stderr,
                "if the output filename is not provided, stdout is used");
        exit(1);
    }
    source = fopen(argv[1], "r");
    if (source == NULL) {
        fprintf(stderr, "%s not found", argv[1]);
        exit(1);
    }
    listing = stdout;
    if (argc > 2) {
        listing = fopen(argv[2], "w");
        if (listing == NULL) {
            fprintf(stderr, "%s not found", argv[2]);
            exit(1);
        }
    }

    fprintf(listing, "# C- COMPILATION: %s\n", "gcd.cm");
    while (getToken() != ENDFILE)
        ;

    fclose(source);
    if (listing != stdout) {
        fclose(listing);
    }
    return 0;
}
