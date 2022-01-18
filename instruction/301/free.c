
#include "../struct.h"

#include "free.h"

void free_301_instruction(struct instruction* super)
{
	ENTER;
	
	// as to cancel out the tfree in free_instruction:
	tinc(super->next);
	
	EXIT;
}

