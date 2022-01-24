
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_loadAI_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr1, int intlit, unsigned vr3)
{
	int error = 0;
	ENTER;
	
	struct loadAI_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&loadAI_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr1 = vr1;
		this->intlit = intlit;
		this->vr3 = vr3;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















