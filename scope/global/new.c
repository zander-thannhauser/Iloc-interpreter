
#include <debug.h>

#include "struct.h"
#include "free.h"
#include "new.h"

int new_global(
	struct global** new,
	char* name,
	void* value)
{
	int error = 0;
	ENTER;
	
	dpv(name);
	dpv(value);
	
	struct global* this = NULL;
	
	error = tmalloc((void**) &this, sizeof(*this), free_global);
	
	if (!error)
	{
		this->name = tinc(name);
		this->value = value;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

