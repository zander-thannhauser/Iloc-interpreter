
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_load_instruction(
	struct instruction** new,
	unsigned line,
	unsigned src, unsigned val)
{
	int error = 0;
	ENTER;
	
	struct load_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&load_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->src = src;
		this->val = val;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















