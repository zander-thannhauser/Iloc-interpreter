
#include <debug.h>

#include "struct.h"
#include "free.h"

void free_unresolved(void* a)
{
	struct unresolved* const this = a;
	tfree(this->name);
	tfree(this->instruction);
}

