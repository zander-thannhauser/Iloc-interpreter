
#include <string.h>

#include "struct.h"
#include "compare.h"

int compare_blocks(const void* a, const void* b)
{
	const struct block* A = a;
	const struct block* B = b;
	
	return strcmp(A->name, B->name);
}

