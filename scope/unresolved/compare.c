
#include <debug.h>

#include "struct.h"
#include "compare.h"

int compare_unresolved(const void* a, const void* b)
{
	const struct unresolved* A = a;
	const struct unresolved* B = b;
	
	return strcmp(A->name, B->name);
}

