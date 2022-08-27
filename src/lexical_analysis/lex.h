#ifndef _LEX_H_
#define _LEX_H_

#include <stdbool.h>

#include "types.h"

/* enabling this constant causes token information to be
 * printed to the listing file as each token is
 * recognized by the scanner
 */
bool trace_scan;

/* function getToken returns the 
 * next token in source file
 */
Token getToken();

#endif

