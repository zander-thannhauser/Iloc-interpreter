
#include <debug.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_frame_instruction(
	struct instruction** new,
	unsigned line,
	char* name,
	size_t frame_size,
	struct vregister_ll* args)
{
	int error = 0;
	ENTER;
	
	struct frame_instruction* this;
	
	error = new_instruction(
		(struct instruction**) &this,
		line,
		&frame_instruction_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->name = tinc(name);
		this->frame_size = frame_size;
		this->args = args;
		
		*new = (struct instruction*) this;
	}
	
	EXIT;
	return error;
}
















