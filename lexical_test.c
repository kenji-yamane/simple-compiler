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
    source = fopen("fixtures/gcd.cm", "r");
    if (source == NULL) {
        fprintf(stderr, "fixture gcd not found");
    }
    listing = stdout; /* send listing to screen */
    fprintf(listing, "# C- COMPILATION: %s\n", "gcd.cm");
    while (getToken() != ENDFILE)
        ;
    fclose(source);
    return 0;
}
