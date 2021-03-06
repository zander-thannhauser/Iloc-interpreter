
#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_call_instruction(
	struct instruction** new,
	unsigned line,
	struct block* callme,
	struct vregister_ll* args)
{
	int error = 0;
	ENTER;
	
	struct call_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&call_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->args = tinc(args);
		
		this->callme = tinc(callme);
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















