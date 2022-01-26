
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_fload_instruction(
	struct instruction** new,
	unsigned line,
	unsigned src, unsigned dst)
{
	int error = 0;
	ENTER;
	
	struct fload_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&fload_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->src = src;
		this->dst = dst;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















