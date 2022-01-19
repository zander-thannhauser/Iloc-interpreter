
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_iwrite_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr1)
{
	int error = 0;
	ENTER;
	
	struct iwrite_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&iwrite_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr1 = vr1;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















