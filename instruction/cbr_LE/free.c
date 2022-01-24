
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_cbr_LE_instruction(struct instruction* super)
{
	struct cbr_LE_instruction* const this = (typeof(this)) super;
	ENTER;
	
	tfree(this->instruction);
	
	EXIT;
}

