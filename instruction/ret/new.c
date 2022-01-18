
#include <debug.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_ret_instruction(
	struct instruction** new,
	unsigned line)
{
	int error = 0;
	ENTER;
	
	struct ret_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&ret_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















