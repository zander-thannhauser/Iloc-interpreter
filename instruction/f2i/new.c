
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_f2i_instruction(
	struct instruction** new,
	unsigned line,
	unsigned src,
	unsigned dst)
{
	int error = 0;
	ENTER;
	
	struct f2i_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&f2i_instruction_inheritance,
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
















