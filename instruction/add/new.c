
#include <debug.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_add_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr1,
	unsigned vr2,
	unsigned vr3)
{
	int error = 0;
	ENTER;
	
	struct add_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&add_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr1 = vr1;
		this->vr2 = vr2;
		this->vr3 = vr3;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















