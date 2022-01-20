
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_iret_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr)
{
	int error = 0;
	ENTER;
	
	struct iret_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&iret_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr = vr;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















