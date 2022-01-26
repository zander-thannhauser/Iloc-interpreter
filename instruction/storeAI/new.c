
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_storeAI_instruction(
	struct instruction** new,
	unsigned line,
	unsigned val, unsigned dst, int index)
{
	int error = 0;
	ENTER;
	
	struct storeAI_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&storeAI_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->val = val;
		this->dst = dst;
		this->index = index;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















