
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_multI_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr1,
	int literal,
	unsigned vr3)
{
	int error = 0;
	ENTER;
	
	struct multI_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&multI_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr1 = vr1;
		this->literal = literal;
		this->vr3 = vr3;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















