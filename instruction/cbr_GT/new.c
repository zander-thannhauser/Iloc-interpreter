
#include <assert.h>
#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_cbr_GT_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr1, unsigned vr2,
	struct block* label)
{
	int error = 0;
	ENTER;
	
	struct cbr_GT_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&cbr_GT_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr1 = vr1;
		this->vr2 = vr2;
		
		this->label = tinc(label);
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















