
#include "struct.h"
#include "free.h"

void free_icall_master_instruction(struct instruction* super)
{
	struct icall_master_instruction* const this = (typeof(this)) super;
	ENTER;
	
	tfree(this->callme);
	tfree(this->args);
	
	EXIT;
}

