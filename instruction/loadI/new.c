
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_loadI_instruction(
	struct instruction** new,
	unsigned line,
	int intlit,
	bool isint,
	unsigned vr)
{
	int error = 0;
	ENTER;
	
	struct loadI_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&loadI_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->intlit = intlit;
		this->isint = isint;
		this->vr = vr;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















