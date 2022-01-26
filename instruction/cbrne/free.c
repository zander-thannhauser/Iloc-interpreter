
#include <memory/tfree.h>

#include "struct.h"
#include "free.h"

void free_cbrne_instruction(struct instruction* super)
{
	struct cbrne_instruction* const this = (typeof(this)) super;
	ENTER;
	
	tfree(this->label);
	
	EXIT;
}

