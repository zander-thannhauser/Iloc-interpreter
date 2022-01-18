
#include <debug.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_global(
	struct global** new,
	char* name,
	size_t size, void* value)
{
	int error = 0;
	ENTER;
	
	struct global* this = NULL;
	
	error = tmalloc((void**) &this, sizeof(*this), free_global);
	
	if (!error)
	{
		this->name = tinc(name);
		this->size = size;
		this->value = tinc(value);
		
		*new = this;
	}
	
	EXIT;
	return error;
}

