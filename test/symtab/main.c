#include "../../src/symtab.h"

int main() {
	char var1[] = "aba";
	BucketListRec *l = st_insert(var1, 0, 0, Integer, false);
    return 0;
}
