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
    source = fopen("test/fixtures/gcd.cm", "r");
    if (source == NULL) {
        fprintf(stderr, "fixture gcd not found");
    }
    listing = fopen("test/lexical/resulting-gcd-tokens.yml",
                    "w"); /* send listing to screen */
    fprintf(listing, "# C- COMPILATION: %s\n", "gcd.cm");
    while (getToken() != ENDFILE)
        ;
    fclose(source);
    fclose(listing);
    return 0;
}
