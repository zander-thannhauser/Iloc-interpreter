
#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_jumpI_instruction(
	struct instruction** new,
	unsigned line,
	struct instruction* instruction)
{
	int error = 0;
	ENTER;
	
	struct jumpI_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&jumpI_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->instruction = tinc(instruction);
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















