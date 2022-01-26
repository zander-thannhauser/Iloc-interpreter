
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_storeAO_instruction(
	struct instruction** new,
	unsigned line,
	unsigned val, unsigned dst, unsigned off)
{
	int error = 0;
	ENTER;
	
	struct storeAO_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&storeAO_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->val = val;
		this->dst = dst;
		this->off = off;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















