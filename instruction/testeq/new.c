
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_testeq_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr1, unsigned vr2)
{
	int error = 0;
	ENTER;
	
	struct testeq_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&testeq_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->in = vr1;
		this->out = vr2;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















