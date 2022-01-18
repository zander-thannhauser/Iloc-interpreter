
#include <memory/tmalloc.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_instruction(
	struct instruction** new,
	unsigned line,
	const struct instruction_inheritance* inheritance,
	size_t alloc_size)
{
	int error = 0;
	ENTER;
	
	struct instruction* this;
	
	error = tmalloc((void**) &this, alloc_size, free_instruction);
	
	if (!error)
	{
		this->line = line;
		
		this->inheritance = inheritance;
		this->next = NULL;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

