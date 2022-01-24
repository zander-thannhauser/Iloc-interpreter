
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_cbr_GT_instruction(struct instruction* super)
{
	struct cbr_GT_instruction* const this = (typeof(this)) super;
	ENTER;
	
	tfree(this->instruction);
	
	EXIT;
}

