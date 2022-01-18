
#include <memory/tmalloc.h>
#include <memory/tinc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_unresolved(
	struct unresolved** new,
	char* name,
	struct instruction* instruction)
{
	int error = 0;
	ENTER;
	
	struct unresolved* this;
	
	error = tmalloc((void**) &this, sizeof(*this), free_unresolved);
	
	if (!error)
	{
		this->name = tinc(name);
		this->instruction = tinc(instruction);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

