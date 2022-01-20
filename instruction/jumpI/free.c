
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_jumpI_instruction(struct instruction* super)
{
	struct jumpI_instruction* const this = (typeof(this)) super;
	ENTER;
	
	tfree(this->instruction);
	
	EXIT;
}

