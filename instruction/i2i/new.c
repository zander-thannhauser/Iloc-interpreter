
#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_i2i_instruction(
	struct instruction** new,
	unsigned line,
	unsigned vr_src,
	unsigned vr_dst)
{
	int error = 0;
	ENTER;
	
	struct i2i_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&i2i_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->vr_src = vr_src;
		this->vr_dst = vr_dst;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















