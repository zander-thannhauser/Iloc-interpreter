
#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_cbr_EQ_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr1, unsigned vr2,
	struct instruction* instruction)
{
	int error = 0;
	ENTER;
	
	struct cbr_EQ_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&cbr_EQ_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr1 = vr1;
		this->vr2 = vr2;
		
		this->instruction = tinc(instruction);
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















