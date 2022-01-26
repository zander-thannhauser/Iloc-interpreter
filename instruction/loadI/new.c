
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
		#ifdef ASM_VERBOSE
		this->literal.kind = isint ? vk_int : vk_ptr;
		#endif
		this->literal.as_int = intlit;
		
		this->vr = vr;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}

















