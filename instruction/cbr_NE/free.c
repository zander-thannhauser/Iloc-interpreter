
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_cbr_NE_instruction(struct instruction* super)
{
	struct cbr_NE_instruction* const this = (typeof(this)) super;
	ENTER;
	
	tfree(this->label);
	
	EXIT;
}

