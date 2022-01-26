
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_testgt_instruction(
	struct instruction** new,
	unsigned line,
	unsigned in, unsigned out)
{
	int error = 0;
	ENTER;
	
	struct testgt_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&testgt_instruction_inheritance,
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
















