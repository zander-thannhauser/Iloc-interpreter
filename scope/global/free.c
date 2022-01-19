
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_global(void* a)
{
	struct global* const g = a;
	ENTER;
	
	tfree(g->name);
	
	EXIT;
}

