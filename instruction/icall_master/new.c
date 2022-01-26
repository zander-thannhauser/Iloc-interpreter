
#include <assert.h>
#include <memory/tinc.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_icall_master_instruction(
	struct instruction** new,
	unsigned line,
	struct block* callme,
	struct vregister_ll* args,
	unsigned vr)
{
	int error = 0;
	ENTER;
	
	struct icall_master_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&icall_master_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->callme = tinc(callme);
		
		this->args = tinc(args);
		this->vr = vr;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















