
#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_cbrne_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr,
	struct instruction* instruction)
{
	int error = 0;
	ENTER;
	
	struct cbrne_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&cbrne_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr = vr;
		this->instruction = tinc(instruction);
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















