
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_testlt_instruction(
	struct instruction** new,
	unsigned line,
	unsigned in, unsigned out)
{
	int error = 0;
	ENTER;
	
	struct testlt_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&testlt_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->in = in;
		this->out = out;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















