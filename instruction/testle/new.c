
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_testle_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr1, unsigned vr2)
{
	int error = 0;
	ENTER;
	
	struct testle_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&testle_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr1 = vr1;
		this->vr2 = vr2;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















