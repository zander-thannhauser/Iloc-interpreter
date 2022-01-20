
#include "struct.h"
#include "free.h"

void free_call_instruction(struct instruction* super)
{
	struct call_instruction* const this = (typeof(this)) super;
	ENTER;
	
	tfree(this->callme);
	tfree(this->args);
	
	EXIT;
}

