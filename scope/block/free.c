
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_block(void* a)
{
	struct block* const this = a;
	tfree(this->name);
	tfree(this->instruction);
}

