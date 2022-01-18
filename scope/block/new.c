
#include <memory/tmalloc.h>
#include <memory/tinc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_block(
	struct block** new,
	char* name,
	struct instruction* instruction)
{
	int error = 0;
	ENTER;
	
	struct block* this;
	
	error = tmalloc((void**) &this, sizeof(*this), free_block);
	
	if (!error)
	{
		this->name = tinc(name);
		this->instruction = tinc(instruction);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

