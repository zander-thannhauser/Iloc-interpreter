
#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_icall_slave_instruction(
	struct instruction** new,
	unsigned vr)
{
	int error = 0;
	ENTER;
	
	struct icall_slave_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		0,
		&icall_slave_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr = vr;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















