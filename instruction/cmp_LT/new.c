
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_cmp_LT_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr1, unsigned vr2, unsigned vr3)
{
	int error = 0;
	ENTER;
	
	struct cmp_LT_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&cmp_LT_instruction_inheritance,
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
















