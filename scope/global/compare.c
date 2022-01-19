
#include <string.h>

#include "struct.h"
#include "compare.h"

int compare_globals(const void* a, const void* b)
{
	const struct global* A = a;
	const struct global* B = b;
	
	return strcmp(A->name, B->name);
}

