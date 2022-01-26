
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_cbr_LT_instruction(struct instruction* super)
{
	struct cbr_LT_instruction* const this = (typeof(this)) super;
	ENTER;
	
	tfree(this->label);
	
	EXIT;
}

